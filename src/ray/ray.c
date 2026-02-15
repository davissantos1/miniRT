/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 09:28:20 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/15 11:53:36 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vec4.h"

inline t_ray	ray_init(t_point origin, t_vec4 dir)
{
	return ((t_ray){.origin = origin, .dir = dir});
}

inline t_point	ray_pos(t_ray ray, double t)
{
	t_point	pos;

	pos = vec4_plus(ray.origin, vec4_scale(t, ray.dir));
	pos.w = 1;
	return (pos);
}
