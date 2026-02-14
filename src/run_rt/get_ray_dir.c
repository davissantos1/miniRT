/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:10:22 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/14 12:34:58 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vec4.h"

t_vec4	get_ray_dir(t_ndc ndc, int x, int y)
{
	t_vec4	temp_u;
	t_vec4	temp_v;
	double	px;
	double	py;

	px = (2.0 * ((double)x + 0.5) / WIDTH - 1.0) * ndc.scale * ndc.ratio;
	py = (1.0 - 2.0 * ((double)y + 0.5) / HEIGHT) * ndc.scale;
	temp_u = vec4_scale(px, ndc.u);
	temp_v = vec4_scale(py, ndc.v);
	return(vec4_minus(vec4_plus(temp_u, temp_v), ndc.w));
}
