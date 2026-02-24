/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 19:44:44 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/22 08:06:04 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"
#include "settings.h"

static bool	infinity_cy(t_cylinder *obj, t_vec4 oc, t_ray ray, t_formula *form)
{
	double		sqrt_delt;
	double		dot_dn;
	double		dot_noc;

	dot_dn = vec4_dot(ray.dir,obj->norm);
	dot_noc = vec4_dot(obj->norm, oc);
	form->a = 1 - dot_dn * dot_dn;
	form->h = 2 * (vec4_dot(ray.dir, oc) - dot_dn * dot_noc);
	form->c = vec4_dot(oc, oc) - dot_noc * dot_noc - obj->diam * obj->diam / 4;
	sqrt_delt = form->h * form->h - 4.0 * form->a * form->c;
	if (sqrt_delt < 0.0)
		return (false);
	sqrt_delt = sqrt(sqrt_delt);
	form->r1 = (-form->h - sqrt_delt) / (2.0 * form->a);
	form->r2 = (-form->h + sqrt_delt) / (2.0 * form->a);
	if (form->r1 < EPSILON && form->r2 < EPSILON)
		return (false);
	if (form->r1 < EPSILON || form->r1 > form->r2)
		form->r1 = form->r2;
	return (true);
}

static bool	check_height(t_cylinder *obj, t_formula *fm, t_ray ray)
{
	t_point	p;
	t_vec4	p_to_pos;
	double	proje;
	double	half_h;

	half_h = obj->height / 2;
	p = ray_pos(ray, fm->r1);
	p_to_pos = vec4_minus(p, obj->pos);
	proje = vec4_dot(p_to_pos, obj->norm);
	if (fabs(proje) <= half_h)
	{	
		fm->r2 = fm->r1;
		return (true);
	}
	p = ray_pos(ray, fm->r2);
	p_to_pos = vec4_minus(p, obj->pos);
	proje = vec4_dot(p_to_pos, obj->norm);
	fm->r1 = fm->r2;
	return (fabs(proje) <= half_h);
}

static bool	put_cap(t_cylinder *obj, t_ray ray, t_hit *hits)
{
	t_disk	cap;
	bool	hit_cap;
	double	half_h;

	hit_cap = false;
	cap.type = DISK;
	cap.mat = obj->mat;
	cap.norm = obj->norm;
	cap.diam = obj->diam;
	half_h = obj->height / 2;
	cap.pos = vec4_plus(obj->pos, vec4_scale(half_h, cap.norm));
	hit_cap = hit_disk(&cap, hits, ray);
	cap.norm = vec4_scale(-1, cap.norm);
	cap.pos = vec4_plus(obj->pos, vec4_scale(half_h, cap.norm));
	if (hit_disk(&cap, hits, ray))
		hit_cap = true;
	return (hit_cap);
}

static inline
void	fill_hits(t_cylinder *obj, t_hit *hits, t_formula form, t_ray ray)
{
	t_vec4	hip;
	double	m;
	t_point	point;

	if (hits->num_roots && form.r1 > hits->r1)
		return ;
	hits->num_roots = 1;
	hits->r1 = form.r1;
	hits->r2 = form.r2;
	hits->num_roots += fabs(form.r2 - form.r1) > EPSILON;
	point = ray_pos(ray, form.r1);
	hits->hit_point = point;
	hip = vec4_minus(point, obj->pos);
	m = vec4_dot(hip, obj->norm);
	hits->norm = vec4_minus(hip, vec4_scale(m, obj->norm));
	hits->norm = vec4_scale(2 / obj->diam, hits->norm);
	hits->mat = obj->mat;
}

bool	hit_cylinder(void *me, t_hit *hits, t_ray ray)
{
	t_cylinder	*obj;
	t_formula	form;
	t_vec4		oc;
	bool		hit_any;

	obj = me;
	hit_any = false;
	oc = vec4_minus(ray.origin, obj->pos);
	if (infinity_cy(obj, oc, ray, &form))
	{
		if (check_height(obj, &form, ray))
		{
			fill_hits(obj, hits, form, ray);
			hit_any = true;
		}
	}
	if (put_cap(obj, ray, hits))
		hit_any = true;
	return (hit_any);
}
