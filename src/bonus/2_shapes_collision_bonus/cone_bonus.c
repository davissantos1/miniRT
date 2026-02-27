/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 08:05:22 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/27 15:41:16 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "shapes_bonus.h"
#include "settings.h"
#include "vec4.h"
#include <math.h>
#include <stdbool.h>

static bool	infinity_co(t_cone *obj, t_vec4 oc, t_ray ray, t_formula *form)
{
	double	sqrt_delt;
	double	dot_dn;
	double	dot_noc;
	double	k;

	k = 1.0 + (obj->diam * obj->diam) / (4.0 * obj->height * obj->height);
	dot_dn = vec4_dot(ray.dir,obj->norm);
	dot_noc = vec4_dot(obj->norm, oc);
	form->a = 1 - k * dot_dn * dot_dn;
	form->h = 2 * (vec4_dot(ray.dir, oc) - k * dot_dn * dot_noc);
	form->c = vec4_dot(oc, oc) - k * dot_noc * dot_noc,
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

static bool	check_heigh(t_cone *obj, t_ray ray, t_formula *form, t_vec4 apex)
{
	t_point	p;
	t_vec4	p_to_apex;
	double	proje;

	p = ray_pos(ray, form->r1);
	p_to_apex = vec4_minus(p, apex);
	proje = vec4_dot(obj->norm, p_to_apex);
	if (proje <= EPSILON && proje > -obj->height)
	{
		form->r2 = form->r1;
		return (true);
	}
	p = ray_pos(ray, form->r2);
	p_to_apex = vec4_minus(p, apex);
	proje = vec4_dot(obj->norm, p_to_apex);
	form->r1 = form->r2;
	return (proje <= EPSILON && proje > -obj->height);
}


static inline
void	fill_hits(t_cone *obj, t_hit *hits, t_formula form, t_ray ray)
{
	t_point	p;
	t_point apex_pos;
	t_vec4	p2apex;
	double	p_height;
	double	k;

	if (hits->num_roots && form.r1 > hits->r1)
		return ;
	k = 1.0 + (obj->diam * obj->diam) / (4.0 * obj->height * obj->height);
	hits->num_roots = 1;
	hits->r1 = form.r1;
	hits->r2 = form.r2;
	hits->num_roots += fabs(form.r1 - form.r2) > EPSILON;
	p = ray_pos(ray, form.r1);
	hits->hit_point = p;
	hits->mat = obj->mat;
	apex_pos = vec4_plus(obj->pos, vec4_scale(obj->height / 2, obj->norm));
	p2apex = vec4_minus(p, apex_pos);
	p_height = vec4_dot(p2apex, obj->norm);
	hits->norm = vec4_minus(p2apex, vec4_scale(p_height * k, obj->norm));
	hits->norm = vec4_unit_vector(hits->norm);
	hits->inverse = obj->inverse;
	hits->type = CONE;
	hits->transform = obj->transform;
}

static bool	put_cap(t_cone *obj, t_hit *hits, t_ray ray)
{
	t_disk	cap;

	cap.pos = vec4_minus(obj->pos, vec4_scale(obj->height / 2, obj->norm));
	cap.pos.w = 1;
	cap.norm = vec4_scale(-1.0, obj->norm);
	cap.type = DISK;
	cap.mat = obj->mat;
	cap.diam = obj->diam;
	cap.transform = disk_transform(&cap, &cap.inverse);
	return(hit_disk(&cap, hits, ray));	
}

bool	hit_cone(void *me, t_hit *hits, t_ray ray)
{
	t_cone		*obj;
	t_formula	form;
	t_vec4		oc;
	t_vec4		apex_pos;
	bool		hit_any;
	
	obj = me;
	apex_pos = vec4_plus(obj->pos, vec4_scale(obj->height / 2, obj->norm));
	oc = vec4_minus(ray.origin, apex_pos);
	hit_any = false;
	if (infinity_co(obj, oc, ray, &form))
	{
		if (check_heigh(obj, ray, &form, apex_pos))
		{
			fill_hits(obj, hits, form, ray);
			hit_any = true;
		}
	}
	hit_any = (put_cap(obj, hits, ray) || hit_any);
	return (hit_any);

}
