/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 18:32:19 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/21 11:50:21 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTX4_H
# define MTX4_H

# include <stdbool.h>

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
t_matrix4	mtx4_scale(double t, t_matrix4 m);

// INVERSE MATRIX
bool		mtx4_inverse(t_matrix4 m, t_matrix4 *result);
double		mtx4_det(t_matrix4 m);

//SPACE TRANSFORMATION
t_matrix4	mtx4_translation(double x, double y, double z);
t_matrix4	mtx4_scaling(double x, double y, double z);
t_matrix4	mtx4_rotation_x(double angle);
t_matrix4	mtx4_rotation_y(double angle);
t_matrix4	mtx4_rotation_z(double angle);

// UTILS
void		first_row(t_matrix4 m, t_matrix4 *result);
void		print_mtx(t_matrix4 m);
double		dabs(double det);
double		to_radians(double angle);

#endif
