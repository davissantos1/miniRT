/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:39:33 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/11 22:02:26 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_plane(char **pos, char **norm, char **color)
{
	if (!check_pos(pos))
		return (0);
	if (!check_norm(norm))
		return (0);
	if (!check_color(color))
		return (0);
	return (1);
}

int	check_sphere(char **pos, char *diam, char **color)
{
	if (!check_pos(pos))
		return (0);
	if (!check_if_double(diam))
		return (0);
	if (!check_color(color))
		return (0);
	if (!check_positive(diam))
		return (0);
	return (1);
}

int	check_cylinder(char **pos, char **norm, char **color)
{
	if (!check_pos(pos))
		return (0);
	if (!check_norm(norm))
		return (0);
	if (!check_color(color))
		return (0);
	return (1);
}
