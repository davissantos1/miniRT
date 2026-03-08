/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shapes_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:39:33 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/08 12:23:22 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing_bonus.h"

int	check_plane(t_minirt *rt, char **pos, char **norm, char **ent)
{
	int		status;
	char	***v;
	
	status = 1;
  	if (!check_pos(pos) || !check_norm(norm))
  		status = 0;
  	if (!check_color(ent))
  		status = 0;
	if (ent + 1)
	{
		v = get_vars(rt, ent);
		if (!check_color(v[7]) || !is_pos(v[11][0]))
			status = 0;
		if (!check_color(v[1]) || !check_color(v[2]) || !check_color(v[3]))
			status = 0;
		if (!check_color(v[8]) || !check_color(v[9]) || !check_color(v[10]))
			status = 0;
		free_vars(v);
	}
	return (status);
}

int	check_sphere(t_minirt *rt, char **pos, char *diam, char **ent)
{
	int		status;
	char	***v;
	
	status = 1;
	if (!check_pos(pos))
		return (0);
	if (!check_if_double(diam))
		return (0);
	if (!is_pos(diam))
		return (0);
	if (ent + 1)
	{
		v = get_vars(rt, ent);
		if (!check_color(v[7]) || !is_pos(v[11][0]))
			status = 0;
		if (!check_color(v[1]) || !check_color(v[2]) || !check_color(v[3]))
			status = 0;
		if (!check_color(v[8]) || !check_color(v[9]) || !check_color(v[10]))
			status = 0;
		free_vars(v);
	}
	return (status);
}

int	check_cylinder(t_minirt *rt, char **pos, char **norm, char **ent)
{
	int		status;
	char	***v;
	
	status = 1;
	if (!check_pos(pos) || !check_norm(norm))
		return (0);
	if (ent + 1)
	{
		v = get_vars(rt, ent);
		if (!check_color(v[7]) || !is_pos(v[11][0]))
			status = 0;
		if (!check_color(v[1]) || !check_color(v[2]) || !check_color(v[3]))
			status = 0;
		if (!check_color(v[8]) || !check_color(v[9]) || !check_color(v[10]))
			status = 0;
		free_vars(v);
	}
	return (status);
}

int	check_cone(t_minirt *rt, char **pos, char **norm, char **ent)
{
	int		status;
	char	***v;
	
	status = 1;
	if (!check_pos(pos) || !check_norm(norm))
		return (0);
	if (ent + 1)
	{
		v = get_vars(rt, ent);
		if (!check_color(v[7]) || !is_pos(v[11][0]))
			status = 0;
		if (!check_color(v[1]) || !check_color(v[2]) || !check_color(v[3]))
			status = 0;
		if (!check_color(v[8]) || !check_color(v[9]) || !check_color(v[10]))
			status = 0;
		free_vars(v);
	}
	return (status);
}

int	check_disk(t_minirt *rt, char **pos, char **norm, char **ent)
{
	int		status;
	char	***v;
	
	status = 1;
	if (!check_pos(pos) || !check_norm(norm))
		return (0);
	if (ent + 1)
	{
		v = get_vars(rt, ent);
		if (!check_color(v[7]) || !is_pos(v[11][0]))
			status = 0;
		if (!check_color(v[1]) || !check_color(v[2]) || !check_color(v[3]))
			status = 0;
		if (!check_color(v[8]) || !check_color(v[9]) || !check_color(v[10]))
			status = 0;
		free_vars(v);
	}
	return (status);
}
