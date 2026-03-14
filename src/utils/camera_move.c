/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:04:12 by vitosant          #+#    #+#             */
/*   Updated: 2026/03/14 14:35:48 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include "vec4.h"
#include <math.h>

static inline double	sign(double num)
{
	double	ret[2];

	ret[0] = 1.0;
	ret[1] = -1.0;
	return (ret[num < 0]);
}

void	rotate_x(t_camera *cam, double angle)
{
	t_vec4	vec;

	if (fabs(cam->norm.y) > 0.99999)
		vec = vec4_cross(vec4_init(1, 0, 0, 0), cam->norm);
	else
		vec = vec4_cross(vec4_init(0, 1, 0, 0), cam->norm);
	vec = vec4_scale(sign(angle), vec);
	cam->norm = vec4_plus(vec, vec4_scale(fabs(angle), cam->norm));
	cam->norm = vec4_unit_vector(cam->norm);
}

void	rotate_y(t_camera *cam, double angle)
{
	t_vec4	vec;

	if (fabs(cam->norm.y) > 0.99999)
		vec = vec4_cross(vec4_init(1, 0, 0, 0), cam->norm);
	else
		vec = vec4_cross(vec4_init(0, 1, 0, 0), cam->norm);
	vec = vec4_cross(vec, cam->norm);
	vec = vec4_scale(sign(angle), vec);
	cam->norm = vec4_plus(vec, vec4_scale(fabs(angle), cam->norm));
	cam->norm = vec4_unit_vector(cam->norm);
}

