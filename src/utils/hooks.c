/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:13:59 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/21 15:31:20 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	hook_keys(int keycode, t_minirt *rt)
{
	if (keycode == 0xff1b)
		desperation(rt, SUCCESS);
	return (0);
}

int	handle_resize(int w, int h, t_minirt *rt)
{
	t_mlx				*m;

	if (!rt || !rt->mlx )
		return (1);
	if (w <=0 || h <= 0)
		return (1);
	printf("porra");
	m = rt->mlx;
	rt->width = w;
	rt->height = h;
	update_size(rt->width, rt->height);
	mlx_destroy_image(m->init, m->img);
	m->img = mlx_new_image(m->init, rt->width, rt->height);
	m->addr = mlx_get_data_addr(m->img, &m->bpp, &m->line, &m->end);
	run_rt(rt);
	return (0);
}

int	close_cross(t_minirt *rt)
{
	desperation(rt, SUCCESS);
	return (0);
}
