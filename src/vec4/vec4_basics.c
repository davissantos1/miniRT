/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_basics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 09:02:18 by vitosant          #+#    #+#             */
/*   Updated: 2026/01/20 10:00:16 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"

inline t_vec4	vec4_minus(t_vec4 v, t_vec4 u)
{
	t_vec4	vec;

	vec.x = v.x - u.x;
	vec.y = v.y - u.y;
	vec.z = v.z - u.z;
	vec.w = v.w - u.w;
	return (vec);
}

inline t_vec4	vec4_plus(t_vec4 v, t_vec4 u)
{
	t_vec4	vec;

	vec.x = v.x + u.x;
	vec.y = v.y + u.y;
	vec.z = v.z + u.z;
	vec.w = v.w + u.w;
	return (vec);
}

inline t_vec4	vec4_times(t_vec4 v, t_vec4 u)
{
	t_vec4	vec;

	vec.x = v.x * u.x;
	vec.y = v.y * u.y;
	vec.z = v.z * u.z;
	vec.w = v.w * u.w;
	return (vec);
}

inline t_vec4	vec4_div(t_vec4 v, t_vec4 u)
{
	t_vec4	vec;

	vec.x = v.x / u.x;
	vec.y = v.y / u.y;
	vec.z = v.z / u.z;
	vec.w = v.w / u.w;
	return (vec);
}

inline t_vec4	vec4_scale(double t, t_vec4 v)
{
	v.x *= t;
	v.y *= t;
	v.z *= t;
	return (v);
}
