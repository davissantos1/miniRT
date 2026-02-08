/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:21:19 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/08 15:00:39 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vec4.h"

inline double	vec4_length(t_vec4 v)
{
	double	len;

	len = sqrt(vec4_squared_len(v));
	return (len);
}

inline double	vec4_squared_len(t_vec4 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

inline double	vec4_dot(t_vec4 v, t_vec4 u)
{
	return (v.x * u.x + v.y * u.y + v.z * u.z);
}

inline t_vec4	vec4_cross(t_vec4 v, t_vec4 u)
{
	t_vec4	vec;

	vec.x = v.y * u.z - v.z * u.y;
	vec.y = v.z * u.x - v.x * u.z;
	vec.z = v.x * u.y - v.y * u.x;
	vec.w = 0.0;
	return (vec);
}

inline t_vec4	vec4_unit_vector(t_vec4 v)
{
	return (vec4_scale(1 / vec4_length(v), v));
}
