/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:44:14 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/09 16:04:09 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_pos(char **pos)
{
	if(!check_number_3mtx(pos))
		return (0);
	return (1);
}

int	check_norm(char **norm)
{
	double	x;
	double	y;
	double	z;

	if (!check_number_3mtx(norm))
		return (0);
	x = ft_atod(norm[0]);	
	y = ft_atod(norm[1]);	
	z = ft_atod(norm[2]);	
	if (x < -1.0f || x > 1.0f)
		return (0);
	if (y < -1.0f || y > 1.0f)
		return (0);
	if (z < -1.0f || z > 1.0f)
		return (0);
	return (1);
}

int	check_ratio(char *ratio)
{
	double	rat;

	if (!check_if_double(ratio))
		return (0);
	rat = ft_atod(ratio);
	if (rat < 0.0f || rat > 1.0f)
		return (0);
	return (1);
}

int	check_fov(char *fov)
{
	int	field;

	if (!check_if_double(fov))
		return (0);
	field = ft_atoi(fov);
	if (field < 0 || field > 180)
		return (0);
	return (1);
}

int	check_color(char **color)
{
	int	r;
	int	g;
	int	b;

	if (!check_number_3mtx(color))
		return (0);
	r = ft_atoi(color[0]);
	g = ft_atoi(color[1]);
	b = ft_atoi(color[2]);
	if (r < 0 || r > 255)
		return (0);
	if (g < 0 || g > 255)
		return (0);
	if (b < 0 || b > 255)
		return (0);
	return (1);
}
