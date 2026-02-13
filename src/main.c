/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:13:55 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/13 14:51:46 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{ 
	t_minirt	*rt;
	int			fd;

	if (ac != 2)
		return (panic(ERR_ARG_NUM));
	else
	{
		if (!check_filename(av[1]))
			return (panic(ERR_ARG_INVALID));
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			return (panic(ERR_SYSCALL));
		rt = start_minirt(av[1]);
		parse_minirt(rt, fd);
		//run_minirt(rt);
		if (close(fd) == -1)
			desperation(rt->gc, ERR_SYSCALL);
	}
	return (SUCCESS);
}
