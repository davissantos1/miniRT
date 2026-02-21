/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx4_rotations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 10:24:50 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/21 12:42:05 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtx4.h"
#include <math.h>

inline t_matrix4	mtx4_rotation_x(double angle)
{
	t_matrix4	ret;

	ret = mtx4_identity();
	angle = to_radians(angle);
	ret.data[5] = cos(angle);
	ret.data[6] = -sin(angle);
	ret.data[9] = -ret.data[6];
	ret.data[10] = ret.data[5];
	return (ret);
}

inline t_matrix4	mtx4_rotation_y(double angle)
{
	t_matrix4	ret;

	ret = mtx4_identity();
	angle = to_radians(angle);
	ret.data[0] = cos(angle);
	ret.data[2] = sin(angle);
	ret.data[8] = -ret.data[2];
	ret.data[10] = ret.data[0];
	return (ret);
}

inline t_matrix4	mtx4_rotation_z(double angle)
{
	t_matrix4	ret;

	ret = mtx4_identity();
	angle = to_radians(angle);
	ret.data[0] = cos(angle);
	ret.data[1] = -sin(angle);
	ret.data[4] = -ret.data[1];
	ret.data[5] = ret.data[0];
	return (ret);
}
