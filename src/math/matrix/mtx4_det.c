/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx4_det.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:45:23 by vitosant          #+#    #+#             */
/*   Updated: 2026/01/30 21:35:46 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "mtx4.h"

inline double	mtx4_det(t_matrix4 m)
{
	t_matrix4	base;

	base = (t_matrix4){0};
	first_row(m, &base);
	return (m.mtx[0][0] * base.mtx[0][0]
			+ m.mtx[1][0] * base.mtx[0][1]
			+ m.mtx[2][0] * base.mtx[0][2]
			+ m.mtx[3][0] * base.mtx[0][3]);
}
