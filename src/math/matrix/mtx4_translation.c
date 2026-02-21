/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx4_translation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 09:43:24 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/21 09:46:13 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "mtx4.h"

inline t_matrix4	mtx4_translation(double x, double y, double z)
{
	t_matrix4	mtx;

	mtx = mtx4_identity();
	mtx.mtx[0][3] = x;
	mtx.mtx[1][3] = y;
	mtx.mtx[2][3] = z;
	return (mtx);
}
