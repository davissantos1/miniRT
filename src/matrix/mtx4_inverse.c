/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx4_inverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:01:10 by vitosant          #+#    #+#             */
/*   Updated: 2026/01/26 14:32:49 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "mtx4.h"

double	mtx4_det(t_matrix4 m)
{
	double	inv[16];
	double	det;

	inv[0] = m.data[5] * m.data[10] * m.data[15]
		- m.data[5] * m.data[11] * m.data[14]
		- m.data[9] * m.data[6] * m.data[15]
		+ m.data[9] * m.data[7] * m.data[14]
		+ m.data[13] * m.data[6] * m.data[11]
		- m.data[13] * m.data[7] * m.data[10];
	inv[4] = -m.data[4] * m.data[10] * m.data[15]
		+ m.data[4] * m.data[11] * m.data[14]
		+ m.data[8] * m.data[6] * m.data[15]
		- m.data[8] * m.data[7] * m.data[14]
		- m.data[12] * m.data[6] * m.data[11]
		+ m.data[12] * m.data[7] * m.data[10];
	inv[8] = m.data[4] * m.data[9] * m.data[15]
		- m.data[4] * m.data[11] * m.data[13]
		- m.data[8] * m.data[5] * m.data[15]
		+ m.data[8] * m.data[7] * m.data[13]
		+ m.data[12] * m.data[5] * m.data[11]
		- m.data[12] * m.data[7] * m.data[9];
	inv[12] = -m.data[4] * m.data[9] * m.data[14]
		+ m.data[4] * m.data[10] * m.data[13]
		+ m.data[8] * m.data[5] * m.data[14]
		- m.data[8] * m.data[6] * m.data[13]
		- m.data[12] * m.data[5] * m.data[10]
		+ m.data[12] * m.data[6] * m.data[9];
	
}
