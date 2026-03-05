/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:13:59 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/05 19:31:46 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	hook_keys(int keycode, t_minirt *rt)
{
	if (keycode == 0xff1b)
		desperation(rt, SUCCESS);
	else if (keycode == 65363)
		rotate_x(rt->scene->camera, -7);
	else if (keycode == 65361)
		rotate_x(rt->scene->camera, 7);
	else if (keycode == 65362)
		rotate_y(rt->scene->camera, -7);
	else if (keycode == 65364)
		rotate_y(rt->scene->camera, 7);
	else if (keycode == 119)
		rt->scene->camera->pos.y += 0.2;
	else
		return (0);
		//	else if (keycode == 97)
		
		//	else if (keycode == 115)
		
		//	else if (keycode == 100)

	run_rt(rt);
	return (0);
}

int	close_cross(t_minirt *rt)
{
	desperation(rt, SUCCESS);
	return (0);
}
