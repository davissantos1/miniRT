/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_other_shapes_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:20:32 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/17 12:21:56 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing_bonus.h"

int	check_paral(t_minirt *rt, char **pos, char **norm, char **ent)
{
	int		status;
	char	***v;

	status = 1;
	if (!check_pos(pos) || !check_norm(norm))
		return (0);
	if (ft_mtxlen(ent) != 1 && ft_mtxlen(ent) != 12)
		return (0);
	if (ent[1])
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

int	check_rect(t_minirt *rt, char **pos, char **norm, char **ent)
{
	int		status;
	char	***v;

	status = 1;
	if (!check_pos(pos) || !check_norm(norm))
		return (0);
	if (ft_mtxlen(ent) != 1 && ft_mtxlen(ent) != 12)
		return (0);
	if (ent[1])
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
