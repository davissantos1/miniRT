/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:13:59 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/07 18:30:50 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include "minirt.h"

int	hook_keys(int keycode, t_minirt *rt)
{
	t_camera	*cam;

	cam = rt->scene->camera;
	if (keycode == 0xff1b)
		desperation(rt, SUCCESS);
	else if (keycode == 65363)
		rotate_x(cam, -7);
	else if (keycode == 65361)
		rotate_x(cam, 7);
	else if (keycode == 65362)
		rotate_y(cam, 7);
	else if (keycode == 65364)
		rotate_y(cam, -7);
	else if (keycode == 119)
		cam->pos = vec4_plus(cam->pos, vec4_scale(0.3, cam->norm));
	else if (keycode == 115)
		cam->pos = vec4_plus(cam->pos, vec4_scale(-0.3, cam->norm));
	else
		return (0);
	run_rt(rt);
	return (0);
}

int	close_cross(t_minirt *rt)
{
	desperation(rt, SUCCESS);
	return (0);
}
