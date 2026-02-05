/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 08:36:30 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/04 12:03:21 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC4_H
# define VEC4_H

# include "mtx4.h"

typedef struct s_vec4
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vec4;

typedef t_vec4	t_color;
typedef t_vec4	t_point;

//Vec4 basics operations
t_vec4	vec4_minus(t_vec4 u, t_vec4 v);
t_vec4	vec4_plus(t_vec4 u, t_vec4 v);
t_vec4	vec4_times(t_vec4 u, t_vec4 v);
t_vec4	vec4_div(t_vec4 u, t_vec4 v);
//If you need devide by t, pass t like 1/num
t_vec4	vec4_scale(double t, t_vec4 v);

//Vec4 complex operations
double	vec4_length(t_vec4 v);
double	vec4_squared_len(t_vec4 v);
double	vec4_dot(t_vec4 v, t_vec4 u);
t_vec4	vec4_cross(t_vec4 v, t_vec4 u);
t_vec4	vec4_unit_vector(t_vec4 v);

t_vec4	vec4_multi_mtx4(t_matrix4 m, t_vec4 vec);
t_vec4	vec4_init(double x, double y, double z, double w);

#endif
