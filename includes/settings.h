/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:26:53 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/05 18:08:18 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

typedef enum e_status
{
	SUCCESS,
	ERR_ARG_NUM,
	ERR_ARG_INVALID,
	ERR_FILE_INVALID,
	ERR_SYSCALL,
	COUNT
}	t_status;

typedef struct s_settings
{
	int		width;
	int		height;
	double	aspect_ratio;
	int		max_bounces;
	int		samples_per_pixel;
	double	epsilon;
	int		num_threads;
}	t_settings;

typedef struct s_map_shape
{
	char	*id;
	void	(*handler)(t_minirt *, char **);
}	t_map_shape;

const t_settings	*get_settings(void);
const t_map_shape	*get_shapes(void);
const char			*get_error_msg(t_status status);

#endif
