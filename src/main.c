/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:13:55 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/02 21:09:00 by dasimoes         ###   ########.fr       */
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
		if (check_filename(av[1]))
			return (panic(ERR_ARG_INVALID));
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			return (panic(ERR_SYSCALL));
		rt = minirt_start(av[1]);
		if (!rt)
			return (panic(ERR_SYSCALL));
		//minirt_parse(rt, fd);
		//minirt_run(rt);
		if (close(fd) == -1)
			return (panic(ERR_SYSCALL));
	}
	return (SUCCESS);
}
