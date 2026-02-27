/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_mapping_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 12:26:19 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/27 17:46:35 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"
#include <math.h>

void	uv_sphere(t_point p, double *u, double *v)
{
	*v = 1 - ((p.y + 1.0) * 0.5);
	*u = 1 - (atan2(p.z, p.x) + M_PI) / (2 * M_PI);
}

void	uv_plane(t_point p, double *u, double *v)
{
	*u = p.x;
	*v = p.z;
}

void	uv_cylinder(t_point p, double *u, double *v)
{
	*v = 1 - ((p.y + 1.0) * 0.5);
	*u = 1 - (atan2(p.z, p.x) + M_PI) / (2 * M_PI);
}

void	uv_disk(t_point p, double *u, double *v)
{
	*v = 1 - ((p.x + 1.0) * 0.5);
	*u = (p.z + 1.0) / 2.0;
}

void	uv_cone(t_point p, double *u, double *v)
{
	*v = 1 - ((p.y + 1.0) * 0.5);
	*u = 1 - (atan2(p.z, p.x) + M_PI) / (2 * M_PI);
}
