/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:32:19 by vitosant          #+#    #+#             */
/*   Updated: 2026/01/26 14:24:20 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTX4_H
# define MTX4_H

typedef struct s_matrix4
{
	union
	{
		double	mtx[4][4];
		double	data[16];
	};
}	t_matrix4;

// BASIC OPERATIONS
int			mtx4_is_diff(t_matrix4 m1, t_matrix4 m2);
t_matrix4	mtx4_times(t_matrix4 m1, t_matrix4 m2);
t_matrix4	mtx4_identity(void);
t_matrix4	mtx4_transpos(t_matrix4 m);

// INVERSE MATRIX
bool		mtx4_inverse(t_matrix4 m, t_matrix4 *result);
double		mtx4_det(t_matrix4 m);

#endif
