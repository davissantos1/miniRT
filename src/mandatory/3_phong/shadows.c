/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 09:56:10 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/22 08:08:43 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include "ray.h"
#include "structs.h"
#include "vec4.h"
#include "shapes.h"
#include "settings.h"
#include <stdbool.h>

bool	shadows(t_scene *sc, t_light *lig, t_hit hit, t_vec4 light_dir)
{
	t_hit	collision;
	t_point	after_point;
	double	light_distance;
	double	hit_distance;

	collision = (t_hit){0};
	after_point = vec4_plus(vec4_scale(EPSILON, hit.norm), hit.hit_point);
	collision = ray_collision(sc, ray_init(after_point, light_dir));
	if (!collision.num_roots)
		return (false);
	light_distance = vec4_squared_len(vec4_minus(lig->pos, after_point));
	hit_distance = vec4_squared_len(vec4_minus(collision.hit_point, lig->pos));
	return (light_distance > hit_distance);
}
