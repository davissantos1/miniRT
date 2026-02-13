/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:12:56 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/13 10:12:58 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "shapes.h"
#include "vec4.h"
#include <stdbool.h>

bool	hit_plane(t_scene *scene, void *me, t_hit *hits, t_ray ray)
{
	t_plane	*obj;
	t_vec4	p0_minus_origin;
	double	dot_rd_n;
	double	t;

	obj = me;
	dot_rd_n = vec4_dot(ray.dir, obj->norm);
	if (fabs(dot_rd_n) <= 1e-7)
		return (false);
	p0_minus_origin = vec4_minus(obj->pos, ray.origin);
	t = vec4_dot(p0_minus_origin, obj->norm) / dot_rd_n;
	if (t < 1e-7 || (hits->num_roots && t > hits->r1))
		return (false);
	hits->num_roots = 1;
	hits->r1 = t;
	hits->norm = obj->norm;
	hits->material = obj->material;
	if (dot_rd_n > 0)
		hits->norm = vec4_scale(-1, obj->norm);
	hits->hit_point = ray_pos(ray, t);
	return (true);
}
