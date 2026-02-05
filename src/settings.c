/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:26:27 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/05 18:05:50 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "settings.h"

static t_settings	g_settings = {
	.width = 1920,
	.height = 1080,
	.aspect_ratio = 1920 / 1080,
	.max_bounces = 5,
	.samples_per_pixel = 1,
	.epsilon = 1e-4,
	.num_threads = 8
};

static t_map_shape	g_shapes[] = {
{"A", &parse_alight},
{"C", &parse_camera},
{"L", &parse_light},
{"pl", &parse_plane},
{"sp", &parse_sphere},
{"cy", &parse_cylinder},
{NULL, NULL}
};

static char	g_msgs[] = {
	[SUCCESS] = "Success",
	[ERR_ARG_NUM] = "only one map supported, type in ./miniRT <.rt file>",
	[ERR_FILE_INVALID] = "format issue found in .rt file, try again!",
	[ERR_ARG_INVALID] = "invalid file! input a valid .rt file path",
}

const t_settings	*get_settings(void)
{
	return (&g_settings);
}

const t_map_shape	*get_shapes(void)
{
	return (&g_shapes);
}

const char	*get_error_msg(t_status status)
{
	if (status < 0 || status >= COUNT)
		return ("unknown internal error");

	return (g_msgs[status]);
}
