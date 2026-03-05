/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:04:12 by vitosant          #+#    #+#             */
/*   Updated: 2026/03/05 18:34:00 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "entities.h"
#include "mtx4.h"
#include "vec4.h"
#include <math.h>

void	rotate_x(t_camera *cam, double angle)
{
	t_matrix4	mtx_rotate;

	mtx_rotate = mtx4_rotation_y(angle);
	cam->norm = vec4_unit_vector(vec4_multi_mtx4(mtx_rotate, cam->norm));
}

void	rotate_y(t_camera *cam, double angle)
{
	t_matrix4	mtx_rotate;

	mtx_rotate = mtx4_rotation_x(angle);
	cam->norm = vec4_unit_vector(vec4_multi_mtx4(mtx_rotate, cam->norm));
}
