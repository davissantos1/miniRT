/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:26:27 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/20 22:52:17 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static const t_settings		g_settings = {
	.width = WIDTH,
	.height = HEIGHT,
	.aspect_ratio = WIDTH / HEIGHT,
	.max_bounces = MAX_BOUNCES,
	.samples_per_pixel = SAMPLES,
	.epsilon = EPSILON,
	.num_threads = THREADS
};

static const t_map_shape	g_shapes[] = {
{"A", &parse_alight},
{"C", &parse_camera},
{"L", &parse_light},
{"pl", &parse_plane},
{"sp", &parse_sphere},
{"cy", &parse_cylinder},
{NULL, NULL}
};

static const char			*g_msgs[] = {
[SUCCESS] = "Success",
[ERR_ARG_NUM] = "wrong argument number, type in ./miniRT <.rt file>",
[ERR_FILE_INVALID] = "format issue found in .rt file, try again!",
[ERR_ARG_INVALID] = "invalid file! input a valid .rt file path",
};

const t_settings	*get_settings(void)
{
	return (&g_settings);
}

const t_map_shape	*get_shapes(void)
{
	return (g_shapes);
}

const char	*get_error_msg(t_status status)
{
	if (status < 0 || status >= COUNT)
		return ("unknown internal error");
	return (g_msgs[status]);
}
