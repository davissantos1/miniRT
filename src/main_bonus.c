/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:13:55 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/08 14:14:21 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "parsing_bonus.h"
#include "minirt.h"
#include "structs.h"
#include "vec4.h"
#include "mlx.h"

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
		rt = start_minirt(get_name(av[1]));
		parse_minirt(rt, fd);
		if (!gc_addlst(rt->scene->shape, rt->gc, GC_DEFAULT))
			desperation(rt, ERR_SYSCALL);
		run_rt(rt);
		if (close(fd) == -1)
			desperation(rt, ERR_SYSCALL);
	}
	mlx_loop(rt->mlx->init);
	return (SUCCESS);
}
