/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vars_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:54:52 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/08 14:27:52 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes_bonus.h"
#include "settings.h"
#include "minirt.h"
#include "parsing_bonus.h"

char ***get_vars(t_minirt *rt, char **ent)
{
	char	***vars;

	vars = ft_calloc(12, sizeof(char **));
	if (!vars)
		desperation(rt, ERR_SYSCALL);
	vars[0] = ft_split(ent[0], ',');
	if (*(ent + 1))
	{
		vars[1] = ft_split(ent[1], ',');
		vars[2] = ft_split(ent[2], ',');
		vars[3] = ft_split(ent[3], ',');
		vars[4] = ft_split(ent[4], '\0');
		vars[5] = ft_split(ent[5], '\0');
		vars[6] = ft_split(ent[6], '\0');
		vars[7] = ft_split(ent[7], ',');
		vars[8] = ft_split(ent[8], ',');
		vars[9] = ft_split(ent[9], ',');
		vars[10] = ft_split(ent[10], ',');
		vars[11] = ft_split(ent[11], '\0');
		if (!vars[0] || !vars[1] || !vars[2] || !vars[3] || !vars[4] || !vars[5])
			desperation(rt, ERR_SYSCALL);
		if (!vars[6] || !vars[7] || !vars[8] || !vars[9] || !vars[10] || !vars[11])
			desperation(rt, ERR_SYSCALL);
	}
	if (!vars[0])
		desperation(rt, ERR_SYSCALL);
	return (vars);
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
