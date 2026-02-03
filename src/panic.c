/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:11:30 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/02 17:23:12 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_status	panic(t_status status)
{
	if (status != SUCCESS && !errno && status != ERR_FILE_INVALID)
		ft_putstr_fd("miniRT: ", 2);
	if (status == ERR_ARG_NUM)
		ft_putstr_fd("only one arg accepted, type in ./miniRT <.rt file>", 2);
	if (status == ERR_ARG_INVALID)
		ft_putstr_fd("invalid file! input a valid .rt file path", 2);
	if (status == ERR_SYSCALL)
		perror("miniRT: ");
	if (status == ERR_FILE_INVALID)
		ft_putstr_fd("Error\nFormat issue found in .rt file, try again!", 2);
	ft_putstr_fd("\n", 2);
	return (status);
}

void	real_panic(t_status status)
{
	panic(status);
	exit(status);
}
