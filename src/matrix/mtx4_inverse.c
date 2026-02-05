/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx4_inverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:01:10 by vitosant          #+#    #+#             */
/*   Updated: 2026/01/30 21:49:40 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "mtx4.h"

inline void	first_row(t_matrix4 m, t_matrix4 *result)
{
	result->mtx[0][0] = m.mtx[1][1] * m.mtx[2][2] * m.mtx[3][3]
		+ m.mtx[1][2] * m.mtx[2][3] * m.mtx[3][1]
		+ m.mtx[1][3] * m.mtx[2][1] * m.mtx[3][2]
		- m.mtx[1][3] * m.mtx[2][2] * m.mtx[3][1]
		- m.mtx[1][2] * m.mtx[2][1] * m.mtx[3][3]
		- m.mtx[1][1] * m.mtx[2][3] * m.mtx[3][2];
	result->mtx[0][1] = -m.mtx[0][1] * m.mtx[2][2] * m.mtx[3][3]
		- m.mtx[0][2] * m.mtx[2][3] * m.mtx[3][1]
		- m.mtx[0][3] * m.mtx[2][1] * m.mtx[3][2]
		+ m.mtx[0][3] * m.mtx[2][2] * m.mtx[3][1]
		+ m.mtx[0][2] * m.mtx[2][1] * m.mtx[3][3]
		+ m.mtx[0][1] * m.mtx[2][3] * m.mtx[3][2];
	result->mtx[0][2] = m.mtx[0][1] * m.mtx[1][2] * m.mtx[3][3]
		+ m.mtx[0][2] * m.mtx[1][3] * m.mtx[3][1]
		+ m.mtx[0][3] * m.mtx[1][1] * m.mtx[3][2]
		- m.mtx[0][3] * m.mtx[1][2] * m.mtx[3][1]
		- m.mtx[0][2] * m.mtx[1][1] * m.mtx[3][3]
		- m.mtx[0][1] * m.mtx[1][3] * m.mtx[3][2];
	result->mtx[0][3] = -m.mtx[0][1] * m.mtx[1][2] * m.mtx[2][3]
		- m.mtx[0][2] * m.mtx[1][3] * m.mtx[2][1]
		- m.mtx[0][3] * m.mtx[1][1] * m.mtx[2][2]
		+ m.mtx[0][3] * m.mtx[1][2] * m.mtx[2][1]
		+ m.mtx[0][2] * m.mtx[1][1] * m.mtx[2][3]
		+ m.mtx[0][1] * m.mtx[1][3] * m.mtx[2][2];
}

static inline void	second_row(t_matrix4 m, t_matrix4 *result)
{
	result->mtx[1][0] = -m.mtx[1][0] * m.mtx[2][2] * m.mtx[3][3]
		- m.mtx[1][2] * m.mtx[2][3] * m.mtx[3][0]
		- m.mtx[1][3] * m.mtx[2][0] * m.mtx[3][2]
		+ m.mtx[1][3] * m.mtx[2][2] * m.mtx[3][0]
		+ m.mtx[1][2] * m.mtx[2][0] * m.mtx[3][3]
		+ m.mtx[1][0] * m.mtx[2][3] * m.mtx[3][2];
	result->mtx[1][1] = m.mtx[0][0] * m.mtx[2][2] * m.mtx[3][3]
		+ m.mtx[0][2] * m.mtx[2][3] * m.mtx[3][0]
		+ m.mtx[0][3] * m.mtx[2][0] * m.mtx[3][2]
		- m.mtx[0][3] * m.mtx[2][2] * m.mtx[3][0]
		- m.mtx[0][2] * m.mtx[2][0] * m.mtx[3][3]
		- m.mtx[0][0] * m.mtx[2][3] * m.mtx[3][2];
	result->mtx[1][2] = -m.mtx[0][0] * m.mtx[1][2] * m.mtx[3][3]
		- m.mtx[0][2] * m.mtx[1][3] * m.mtx[3][0]
		- m.mtx[0][3] * m.mtx[1][0] * m.mtx[3][2]
		+ m.mtx[0][3] * m.mtx[1][2] * m.mtx[3][0]
		+ m.mtx[0][2] * m.mtx[1][0] * m.mtx[3][3]
		+ m.mtx[0][0] * m.mtx[1][3] * m.mtx[3][2];
	result->mtx[1][3] = m.mtx[0][0] * m.mtx[1][2] * m.mtx[2][3]
		+ m.mtx[0][2] * m.mtx[1][3] * m.mtx[2][0]
		+ m.mtx[0][3] * m.mtx[1][0] * m.mtx[2][2]
		- m.mtx[0][3] * m.mtx[1][2] * m.mtx[2][0]
		- m.mtx[0][2] * m.mtx[1][0] * m.mtx[2][3]
		- m.mtx[0][0] * m.mtx[1][3] * m.mtx[2][2];
}

static inline void	third_row(t_matrix4 m, t_matrix4 *result)
{
	result->mtx[2][0] = m.mtx[1][0] * m.mtx[2][1] * m.mtx[3][3]
		+ m.mtx[1][1] * m.mtx[2][3] * m.mtx[3][0]
		+ m.mtx[1][3] * m.mtx[2][0] * m.mtx[3][1]
		- m.mtx[1][3] * m.mtx[2][1] * m.mtx[3][0]
		- m.mtx[1][1] * m.mtx[2][0] * m.mtx[3][3]
		- m.mtx[1][0] * m.mtx[2][3] * m.mtx[3][1];
	result->mtx[2][1] = -m.mtx[0][0] * m.mtx[2][1] * m.mtx[3][3]
		- m.mtx[0][1] * m.mtx[2][3] * m.mtx[3][0]
		- m.mtx[0][3] * m.mtx[2][0] * m.mtx[3][1]
		+ m.mtx[0][3] * m.mtx[2][1] * m.mtx[3][0]
		+ m.mtx[0][1] * m.mtx[2][0] * m.mtx[3][3]
		+ m.mtx[0][0] * m.mtx[2][3] * m.mtx[3][1];
	result->mtx[2][2] = m.mtx[0][0] * m.mtx[1][1] * m.mtx[3][3]
		+ m.mtx[0][1] * m.mtx[1][3] * m.mtx[3][0]
		+ m.mtx[0][3] * m.mtx[1][0] * m.mtx[3][1]
		- m.mtx[0][3] * m.mtx[1][1] * m.mtx[3][0]
		- m.mtx[0][1] * m.mtx[1][0] * m.mtx[3][3]
		- m.mtx[0][0] * m.mtx[1][3] * m.mtx[3][1];
	result->mtx[2][3] = -m.mtx[0][0] * m.mtx[1][1] * m.mtx[2][3]
		- m.mtx[0][1] * m.mtx[1][3] * m.mtx[2][0]
		- m.mtx[0][3] * m.mtx[1][0] * m.mtx[2][1]
		+ m.mtx[0][3] * m.mtx[1][1] * m.mtx[2][0]
		+ m.mtx[0][1] * m.mtx[1][0] * m.mtx[2][3]
		+ m.mtx[0][0] * m.mtx[1][3] * m.mtx[2][1];
}

static inline void	fourth_row(t_matrix4 m, t_matrix4 *result)
{
	result->mtx[3][0] = -m.mtx[1][0] * m.mtx[2][1] * m.mtx[3][2]
		- m.mtx[1][1] * m.mtx[2][2] * m.mtx[3][0]
		- m.mtx[1][2] * m.mtx[2][0] * m.mtx[3][1]
		+ m.mtx[1][2] * m.mtx[2][1] * m.mtx[3][0]
		+ m.mtx[1][1] * m.mtx[2][0] * m.mtx[3][2]
		+ m.mtx[1][0] * m.mtx[2][2] * m.mtx[3][1];
	result->mtx[3][1] = m.mtx[0][0] * m.mtx[2][1] * m.mtx[3][2]
		+ m.mtx[0][1] * m.mtx[2][2] * m.mtx[3][0]
		+ m.mtx[0][2] * m.mtx[2][0] * m.mtx[3][1]
		- m.mtx[0][2] * m.mtx[2][1] * m.mtx[3][0]
		- m.mtx[0][1] * m.mtx[2][0] * m.mtx[3][2]
		- m.mtx[0][0] * m.mtx[2][2] * m.mtx[3][1];
	result->mtx[3][2] = -m.mtx[0][0] * m.mtx[1][1] * m.mtx[3][2]
		- m.mtx[0][1] * m.mtx[1][2] * m.mtx[3][0]
		- m.mtx[0][2] * m.mtx[1][0] * m.mtx[3][1]
		+ m.mtx[0][2] * m.mtx[1][1] * m.mtx[3][0]
		+ m.mtx[0][1] * m.mtx[1][0] * m.mtx[3][2]
		+ m.mtx[0][0] * m.mtx[1][2] * m.mtx[3][1];
	result->mtx[3][3] = m.mtx[0][0] * m.mtx[1][1] * m.mtx[2][2]
		+ m.mtx[0][1] * m.mtx[1][2] * m.mtx[2][0]
		+ m.mtx[0][2] * m.mtx[1][0] * m.mtx[2][1]
		- m.mtx[0][2] * m.mtx[1][1] * m.mtx[2][0]
		- m.mtx[0][1] * m.mtx[1][0] * m.mtx[2][2]
		- m.mtx[0][0] * m.mtx[1][2] * m.mtx[2][1];
}

bool	mtx4_inverse(t_matrix4 m, t_matrix4 *result)
{
	double	det;

	first_row(m, result);
	det = m.mtx[0][0] * result->mtx[0][0]
		+ m.mtx[1][0] * result->mtx[0][1]
		+ m.mtx[2][0] * result->mtx[0][2]
		+ m.mtx[3][0] * result->mtx[0][3];
	if (dabs(det) < 1e-7)
		return (false);
	second_row(m, result);
	third_row(m, result);
	fourth_row(m, result);
	*result = mtx4_scale(1 / det, *result);
	return (true);
}
