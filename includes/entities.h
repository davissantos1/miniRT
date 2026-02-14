/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:16:11 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/11 17:57:22 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_H
# define ENTITIES_H

# include "vec4.h"

typedef struct	s_alight
{
	double		ratio;
	t_color		color;
}	t_alight;

typedef struct	s_camera
{
	t_point		pos;
	t_vec4		norm;
	int			fov;
}	t_camera;

typedef struct	s_light
{
	t_point		pos;
	double		ratio;
	t_color		color;
}	t_light;

#endif
