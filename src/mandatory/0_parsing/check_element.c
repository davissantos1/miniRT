/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:13:55 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/22 07:57:04 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_alight(char *ratio, char **color)
{
	if (!check_ratio(ratio))
		return (0);
	if (!check_color(color))
		return (0);
	return (1);
}

int	check_camera(char **pos, char **norm, char *fov)
{
	if (!check_pos(pos))
		return (0);
	if (!check_norm(norm))
		return (0);
	if (!check_fov(fov))
		return (0);
	return (1);
}

int	check_light(char **pos, char *ratio, char **color)
{
	if (!check_pos(pos))
		return (0);
	if (!check_ratio(ratio))
		return (0);
	if (!check_color(color))
		return (0);
	return (1);
}
