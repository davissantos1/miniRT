/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 08:46:33 by vitosant          #+#    #+#             */
/*   Updated: 2026/03/14 09:44:18 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "shapes_bonus.h"
#include "settings.h"
#include "vec4.h"
#include <math.h>
#include <stdbool.h>

static inline
bool fill_hits(t_rectangle *obj, t_hit * hit, t_ray ray, double t)
{
	t_point	wrld_point;
	t_point	obj_point;

	wrld_point = ray_pos(ray, t);
	obj_point = vec4_multi_mtx4(obj->inverse, wrld_point);
	if (fabs(obj_point.x) > obj->width * 0.5
		|| fabs(obj_point.z) > obj->height * 0.5)
		return (false);
	hit->num_roots = 1;
	hit->r1 = t;
	hit->hit_point = wrld_point;
	hit->inverse = obj->inverse;
	hit->mat = obj->mat;
	hit->type = obj->type;
	hit->norm = obj->norm;
	hit->transform = obj->transform;
	if (vec4_dot(hit->norm, ray.dir) < 0)
		hit->norm = vec4_scale(-1.0, hit->norm);
	return (true);
}

bool	hit_rectangle(void *me, t_hit *hits, t_ray ray)
{
	t_rectangle	*obj;
	t_vec4	p0_minus_origin;
	double	cosine;
	double	t;

	obj = me;
	cosine = vec4_dot(ray.dir, obj->norm);
	if (fabs(cosine) <= EPSILON)
		return (false);
	p0_minus_origin = vec4_minus(obj->pos, ray.origin);
	t = vec4_dot(p0_minus_origin, obj->norm) / cosine;
	if (t < EPSILON || (hits->num_roots && t > hits->r1))
		return (false);
	return (fill_hits(obj, hits, ray, t));
}
