/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:12:56 by vitosant          #+#    #+#             */
/*   Updated: 2026/03/07 19:31:11 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "shapes.h"
#include "vec4.h"
#include "settings.h"
#include <stdbool.h>

bool	hit_plane(void *me, t_hit *hits, t_ray ray)
{
	t_plane	*obj;
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
	hits->num_roots = 1;
	hits->r1 = t;
	hits->norm = obj->norm;
	hits->mat = obj->mat;
	if (cosine > 0)
		hits->norm = vec4_scale(-1, obj->norm);
	hits->hit_point = ray_pos(ray, t);
	return (true);
}
