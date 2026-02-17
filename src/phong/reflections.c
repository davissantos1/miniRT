/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:45:56 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/17 13:12:00 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "shapes.h"
#include "structs.h"
#include "vec4.h"
#include <stdio.h>

t_color	reflections(t_scene *scene, t_hit hits, int depth)
{
	t_color	color;
	t_hit	collision;
	t_ray	reflected;

	collision = hits;
	while (depth < 1)
	{
		reflected.dir = reflec_dir(collision.norm, collision.ray_dir);
		reflected.origin = vec4_plus(vec4_scale(1e-7, hits.norm), hits.hit_point);
		collision = ray_collision(scene, reflected);
		
		color = vec4_times(hits.material.kr, collision.material.color);
		depth++;
	}
	return (color);
}
