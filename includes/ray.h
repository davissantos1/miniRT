/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:34:42 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/18 22:11:24 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	RAY_H
# define RAY_H

# include "structs.h"

typedef struct s_ray
{
	t_point	origin;
	t_vec4	dir;
}	t_ray;

t_ray	ray_init(t_point origin, t_vec4 dir);
t_point	ray_pos(t_ray ray, double t);

#endif
