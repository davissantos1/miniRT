/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 13:13:59 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/19 14:08:10 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	hook_keys(int keycode, t_minirt *rt)
{
	if (keycode == 0xff1b)
		desperation(rt, SUCCESS);
	return (0);
}

int	close_cross(t_minirt *rt)
{
	desperation(rt, SUCCESS);
	return (0);
}
