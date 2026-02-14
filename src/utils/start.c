/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:25:06 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/14 12:57:21 by vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_minirt	*start_minirt(char *name)
{
	t_minirt	*rt;
	t_gc		*garbage;

	name[ft_strlen(name) - 5] = '\0';
	garbage = gc_init();
	if (!garbage)
		real_panic(ERR_SYSCALL);
	rt = gc_calloc(sizeof(t_minirt), garbage, GC_DEFAULT);
	if (!rt)
		desperation(garbage, ERR_SYSCALL);
	rt->name = name;
	rt->gc = garbage;
	rt->mlx = start_mlx(rt->gc, name);
	if (!rt->mlx)
		desperation(garbage, ERR_SYSCALL);
	rt->scene = gc_calloc(sizeof(t_scene), garbage, GC_DEFAULT);
	if (!rt->scene)
		desperation(garbage, ERR_SYSCALL);
	return (rt);
}

t_mlx	*start_mlx(t_gc *gc, char *name)
{
	t_mlx				*mlx;

	mlx = gc_malloc(sizeof(t_mlx), gc, GC_DEFAULT);
	if (!mlx)
		return (NULL);
	mlx->init = mlx_init();
	if (!mlx->init)
		return (NULL);
	mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, name);
	if (!mlx->win)
		return (NULL);
	mlx->img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	if (!mlx->img)
		return (NULL);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line, &mlx->end);
	return (mlx);
}
