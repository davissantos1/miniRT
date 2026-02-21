/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:45:56 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/18 21:47:14 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "shapes.h"
#include "structs.h"
#include "vec4.h"
#include <stdio.h>

inline static t_vec4	reflec_dir(t_vec4 norm, t_vec4 dir)
{
	return (vec4_minus(dir, vec4_scale(vec4_dot(norm, dir) * 2.0, norm)));
}

t_color	reflections(t_scene *scene, t_hit hits, int depth)
{
	t_hit	collision;
	t_ray	reflected;

	if (depth)
		return ((t_color){0});
	collision = (t_hit){0};
	reflected.dir = vec4_unit_vector(reflec_dir(hits.norm, hits.ray_dir));
	reflected.origin = vec4_plus(vec4_scale(1e-7, hits.norm), hits.hit_point);
	collision = ray_collision(scene, reflected);
	if (!collision.num_roots)
		return ((t_color){0});
	return (vec4_times(hits.mat.kr, phong(collision, scene, depth - 1)));
}
