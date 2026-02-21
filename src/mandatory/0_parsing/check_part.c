/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:44:14 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/20 22:16:32 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_pos(char **pos)
{
	if (!check_number_3mtx(pos))
		return (0);
	return (1);
}

int	check_norm(char **norm)
{
	t_vec4	test;
	double	len;

	test = vec4_init(ft_atod(norm[0]), ft_atod(norm[1]), ft_atod(norm[2]), 0);
	len = vec4_length(test);
	if (!check_number_3mtx(norm) || len > 1.0f)
		return (0);
	if (test.x < -1.0f || test.x > 1.0f)
		return (0);
	if (test.y < -1.0f || test.y > 1.0f)
		return (0);
	if (test.z < -1.0f || test.z > 1.0f)
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
