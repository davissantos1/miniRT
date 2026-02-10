/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 19:44:44 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/10 10:30:44 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>
#include <stdbool.h>
#include "ray.h"
#include "shapes.h"
#include "vec4.h"

static bool	infinity_cy(t_cylinder *obj, t_vec4 oc, t_ray ray, t_hit *tmp_hit);
static bool	check_height(t_cylinder *obj, t_hit *tmp, t_hit *hit, t_ray ray);
static bool	put_cap(t_scene *scene,t_cylinder *obj, t_ray ray, t_hit *hits);

bool	hit_cylinder(t_scene *scene, void *me, t_hit *hits, t_ray ray)
{
	t_cylinder	*obj;
	t_hit		tmp_hit;
	t_vec4		oc;
	bool		hit_any;

	obj = me;
	hit_any = false;
	oc = vec4_minus(obj->pos, ray.origin);
	if (infinity_cy(obj, oc, ray, &tmp_hit))
	{
		if (check_height(obj, &tmp_hit, hits, ray))
		{
			set_roots(obj, tmp_hit.r1, tmp_hit.r2, hits);
			hit_any = true;
		}
	}
	if (put_cap(scene, obj, ray, hits))
		hit_any = true;
	return (hit_any);
}

static bool	infinity_cy(t_cylinder *obj, t_vec4 oc, t_ray ray, t_hit *tmp_hit)
{
	t_quadratic	formula;
	double		sqrt_delt;
	t_vec4		oc_norm;
	t_vec4		rd_norm;

	oc_norm = vec4_cross(oc, obj->norm);
	rd_norm = vec4_cross(ray.dir, obj->norm);
	formula.a = vec4_squared_len(rd_norm);
	formula.h = vec4_dot(rd_norm, oc_norm);
	formula.c = vec4_squared_len(oc_norm) - (obj->diam * obj->diam / 4);
	sqrt_delt = formula.h * formula.h - formula.a * formula.c;
	if (sqrt_delt < 0)
		return (false);
	sqrt_delt = sqrt(sqrt_delt);
	tmp_hit->r1 = (formula.h - sqrt_delt) / formula.a;
	tmp_hit->r2 = (formula.h + sqrt_delt) / formula.a;
	tmp_hit->num_roots = 1;
	if (fabs(tmp_hit->r1 - tmp_hit->r2) > 1e-7)
		tmp_hit->num_roots = 2;
	return (true);
}

static bool	check_height(t_cylinder *obj, t_hit *tmp, t_hit *hit, t_ray ray)
{
	t_point	p;
	t_vec4	p_to_pos;
	double	proje;
	double	half_h;

	half_h = obj->height / 2;
	p = ray_pos(ray, tmp->r1);
	p_to_pos = vec4_minus(p, obj->pos);
	proje = vec4_dot(p_to_pos, obj->norm);
	if (fabs(proje) <= half_h)
		return (true);
	p = ray_pos(ray, tmp->r2);
	p_to_pos = vec4_minus(p, obj->pos);
	proje = vec4_dot(p_to_pos, obj->norm);
	if (fabs(proje) <= half_h)
	{
		tmp->num_roots = 1;
		tmp->r1 = tmp->r2;
		return (true);
	}
	tmp->num_roots = 0;
	return (false);
}

static bool	put_cap(t_scene *scene,t_cylinder *obj, t_ray ray, t_hit *hits)
{
	t_circle	cap;
	bool		hit_cap;
	double		half_h;

	hit_cap = false;
	cap.type = CIRCLE;
	cap.color = obj->color;
	cap.norm = obj->norm;
	cap.diam = obj->diam;
	half_h = obj->height / 2;
	cap.pos = vec4_plus(obj->pos, vec4_scale(half_h, cap.norm));
	if(hit_circle(scene, &cap, hits, ray))
		hit_cap = true;
	cap.pos = vec4_plus(obj->pos, vec4_scale(-half_h, cap.norm));
	if (hit_circle(scene, &cap, hits, ray))
		hit_cap = true;
	return (hit_cap);
}

