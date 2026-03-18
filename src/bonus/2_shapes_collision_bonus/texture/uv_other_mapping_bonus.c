/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_other_mapping_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:12:31 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/18 20:13:02 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"
#include <math.h>

void	uv_disk(t_point p, double *u, double *v)
{
	*v = 1 - ((p.x + 1.0) * 0.5);
	*u = (p.z + 1.0) * 0.5;
}

void	uv_cone(t_point p, double *u, double *v)
{
	*v = 1 - ((p.y + 1.0) * 0.5);
	*u = 1 - (atan2(p.z, p.x) + M_PI) / (2 * M_PI);
}

void	uv_rectangle(t_point p, double *u, double *v)
{
	*v = (p.z + 1.0) * 0.5;
	*u = 1 - (p.x + 1.0) * 0.5;
}
