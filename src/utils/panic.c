/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:11:30 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/05 18:10:54 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_status	panic(t_status status)
{
	char	*msg;

	if (status == SUCCESS)
		return (SUCCESS);

	ft_putstr_fd("Error\n", 2);
	if (status == ERR_SYSCALL)
		perror("miniRT");
	else
	{
		msg = get_error_msg(status);
		ft_putstr_fd(msg, 2);
	}
	ft_putstr_fd("\n", 2);
	return (status);
}

void	real_panic(t_status status)
{
	panic(status);
	exit(status);
}

void	desperation(t_minirt *rt, t_status status)
{
	gc_free_all(rt->gc);
	real_panic(status);
}
