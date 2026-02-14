/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:20:36 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/14 12:47:39 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// External includes
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include <sys/time.h>
# include <stdlib.h>

// Local includes
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "settings.h"
# include "structs.h"
# include "parsing.h"
# include "entities.h"
# include "shapes.h"
# include "vec4.h"

void		img_pixel_put(t_mlx *mlx, int x, int y, int color);
t_vec4		get_ray_dir(t_ndc ndc, int x, int y);

//Signatures
t_status	panic(t_status status);
void		real_panic(t_status status);
int			check_filename(char *file);
t_minirt	*start_minirt(char *name);
t_mlx		*start_mlx(t_gc *gc, char *name);
void		desperation(t_gc *gc, t_status status);

int			check_if_double(char *str);
int			check_number_3mtx(char **num);
int			check_empty(char *line);
int			check_positive(char *num);

void		add_object(t_minirt *rt, void *obj);

#endif
