/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 09:56:10 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/15 13:53:21 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include "ray.h"
#include "structs.h"
#include "vec4.h"
#include "shapes.h"
#include <stdbool.h>
#include <stdio.h>

bool	shadows(t_scene *scene, t_light *light, t_hit hit, t_vec4 light_dir)
{
	t_hit	collision;
	t_point	after_point;
	double	light_distance;
	double	collision_distance;

	collision = (t_hit){0};
	after_point = vec4_plus(vec4_scale(1e-7, hit.norm), hit.hit_point);
	collision = ray_collision(scene, ray_init(after_point, light_dir));
	if (!collision.num_roots)
		return (false);
	light_distance = vec4_squared_len(vec4_minus(light->pos, after_point));
	collision_distance = vec4_squared_len(vec4_minus(collision.hit_point, light->pos));
	//	printf(" | light: %.2lf collision: %.2lf |\n", light_distance, collision_distance);
	return (light_distance > collision_distance);
}
