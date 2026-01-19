/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 08:36:30 by vitosant          #+#    #+#             */
/*   Updated: 2026/01/19 09:01:25 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC4_H
# define VEC4_H

typedef struct s_vec4
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vec4;

//Vec4 basics operations
inline t_vec4	vec4_minus(t_vec4 u, t_vec4 v);
inline t_vec4	vec4_plus(t_vec4 u, t_vec4 v);
inline t_vec4	vec4_times(t_vec4 u, t_vec4 v);
inline t_vec4	vec4_div(t_vec4 u, t_vec4 v);
//If you need devide by t, pass t like 1/num
inline t_vec4	vec4_scale(double t, t_vec4 v);

//Vec4 complex operations
inline double	vec4_length(t_vec4 v);
inline double	vec4_squared_len(t_vec4 v);
inline double	vec4_dot(t_vec4 v, t_vec4 u);
inline t_vec4	vec4_cross(t_vec4 v, t_vec4 u);
inline t_vec4	vec4_unit_vector(t_vec4 v);

#endif
