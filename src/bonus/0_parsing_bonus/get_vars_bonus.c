/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vars_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:54:52 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/14 08:07:52 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "settings.h"
#include "minirt.h"
#include "parsing_bonus.h"

static void	get_vars_aux(t_minirt *rt, char ****vars, char **ent)
{
	char	***v;

	v = *vars;
	v[1] = ft_split(ent[1], ',');
	v[2] = ft_split(ent[2], ',');
	v[3] = ft_split(ent[3], ',');
	v[4] = ft_split(ent[4], '\0');
	v[5] = ft_split(ent[5], '\0');
	v[6] = ft_split(ent[6], '\0');
	v[7] = ft_split(ent[7], ',');
	v[8] = ft_split(ent[8], ',');
	v[9] = ft_split(ent[9], ',');
	v[10] = ft_split(ent[10], ',');
	v[11] = ft_split(ent[11], '\0');
	if (!v[1] || !v[2] || !v[3] || !v[4] || !v[5])
		desperation(rt, ERR_SYSCALL);
	if (!v[6] || !v[7] || !v[8] || !v[9] || !v[10] || !v[11])
		desperation(rt, ERR_SYSCALL);
}

char	***get_vars(t_minirt *rt, char **ent)
{
	char	***v;

	v = ft_calloc(13, sizeof(char **));
	if (!v)
		desperation(rt, ERR_SYSCALL);
	v[0] = ft_split(ent[0], ',');
	if (*(ent + 1))
		get_vars_aux(rt, &v, ent);
	if (!v[0])
		desperation(rt, ERR_SYSCALL);
	return (v);
}

void	free_vars(char ***vars)
{
	int	i;

	i = 0;
	while (vars[i])
	{
		if (vars[i])
			ft_mtxfree(vars[i]);
		i++;
	}
	free(vars);
}
