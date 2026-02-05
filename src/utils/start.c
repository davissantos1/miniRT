/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:25:06 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/05 18:34:49 by dasimoes         ###   ########.fr       */
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
		desperation(ERR_SYSCALL);
	rt = gc_malloc(sizeof(t_minirt), garbage, GC_DEFAULT);
	if (!rt)
		desperation(ERR_SYSCALL);
	rt->name = name;
	rt->gc = garbage;
	rt->mlx = start_mlx(rt->gc, name);
	if (!rt->mlx)
		desperation(ERR_SYSCALL);
	rt->scene = gc_calloc(sizeof(t_scene), garbage, GC_DEFAULT);
	if (!rt->scene)
		desperation(ERR_SYSCALL);
	return (rt);
}

t_mlx	*start_mlx(t_gc *gc, char *name)
{
	const t_settings	set;
	t_mlx				*mlx;

	mlx = gc_malloc(sizeof(t_mlx), gc, GC_DEFAULT);
	if (!mlx)
		return (NULL);
	mlx->init = mlx_init();
	if (!mlx->init)
		return (NULL);
	set = get_settings();
	mlx->win = mlx_new_window(mlx->init, set->width, set->height, name);
	if (!mlx->win)
		return (NULL);
	mlx->img = mlx_new_image(mlx->init, set->width, set->height);
	if (!mlx->img)
		return (NULL);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line, &mlx->end);
	return (mlx);
}
