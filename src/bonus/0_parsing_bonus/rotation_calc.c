/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 11:35:58 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/21 11:51:20 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "mtx4.h"
#include "vec4.h"
#include <math.h>

t_matrix4	rotation_calc(t_vec4 norm)
{
	t_matrix4	ret;
	t_vec4		up;
	t_vec4		x;
	t_vec4		z;
	
	if (fabs(norm.y) > 0.999999)
		up = vec4_init(1.0, 0.0, 0.0, 0.0);
	else
		up = vec4_init(0.0, 1.0, 0.0, 0.0);
	x = vec4_unit_vector(vec4_cross(up, norm));
	z = vec4_cross(x, norm);
	ret = mtx4_identity();
	ret.mtx[0][0] = x.x;
	ret.mtx[1][0] = x.y;
	ret.mtx[2][0] = x.z;
	ret.mtx[0][1] = norm.x;
	ret.mtx[1][1] = norm.y;
	ret.mtx[2][1] = norm.z;
	ret.mtx[0][2] = z.x;
	ret.mtx[1][2] = z.y;
	ret.mtx[2][2] = z.z;
	return (ret);
}
