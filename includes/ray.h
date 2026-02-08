/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:34:42 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/08 09:54:07 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef	RAY_H
# define RAY_H

# include "vec4.h"

typedef struct s_ray
{
	t_point	origin;
	t_vec4	dir;
}	t_ray;

t_ray	ray_init(t_point origin, t_vec4 dir);
t_ray	ray_pos(t_ray ray, double t);

#endif
