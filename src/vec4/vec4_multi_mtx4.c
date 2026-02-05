/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_multi_mtx4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:20:17 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/04 11:40:00 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"
#include "mtx4.h"

inline t_vec4	vec4_multi_mtx4(t_matrix4 m, t_vec4 vec)
{
	t_vec4	ret;

	ret.x = m.mtx[0][0] * vec.x + m.mtx[0][1] * vec.y
		+ m.mtx[0][2] * vec.z + m.mtx[0][3] * vec.w;
	ret.y = m.mtx[1][0] * vec.x + m.mtx[1][1] * vec.y
		+ m.mtx[1][2] * vec.z + m.mtx[1][3] * vec.w;
	ret.z = m.mtx[2][0] * vec.x + m.mtx[2][1] * vec.y
		+ m.mtx[2][2] * vec.z + m.mtx[2][3] * vec.w;
	ret.w = m.mtx[3][0] * vec.x + m.mtx[3][1] * vec.y
		+ m.mtx[3][2] * vec.z + m.mtx[3][3] * vec.w;
	return (ret);
}
