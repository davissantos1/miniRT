/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 08:40:09 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/10 10:54:03 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"
#include "vec4.h"

static t_color	color_shape(void *me)
{
	t_sphere 	*sphere;
	t_cylinder	*cylinder;
	t_circle	*circle;
	if (((t_wildcard *)me)->type == SPHERE)
	{
		sphere = me;
		return (sphere->color);
	}
	if (((t_wildcard *)me)->type == CIRCLE)
	{
		circle = me;
		return (circle->color);
	}
	cylinder = me;
	return (cylinder->color);
}

void	set_roots(void *me, double r1, double r2, t_hit *hits)
{
	t_color	color;

	color = color_shape(me);
	if (hits->num_roots && r1 > hits->r1)
		return ;
	hits->num_roots = 1;
	hits->r1 = r1;
	hits->r2 = r2;
	if (fabs(r2 - r1) > 1e-7)
		hits->num_roots = 2;
	hits->color = ((int)color.x << 16 | (int)color.y << 8 | (int)color.z);	
}
