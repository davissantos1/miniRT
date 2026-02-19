/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:20:36 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/19 19:57:44 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// External includes
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
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
# include "ray.h"

//Signatures
t_status	panic(t_status status);
void		real_panic(t_status status);
int			check_filename(char *file);
t_minirt	*start_minirt(char *name);
t_mlx		*start_mlx(t_gc *gc, char *name);
void		desperation(t_minirt *rt, t_status status);

int			check_if_double(char *str);
int			check_number_3mtx(char **num);
int			check_empty(char *line);
int			check_positive(char *num);

void		add_object(t_minirt *rt, void *obj);
void		img_pixel_put(t_mlx *mlx, int x, int y, int color);
void		run_rt(t_minirt	*ctx);

void		set_roots(void *me, double r1, double r2, t_hit *hits);

int			hook_keys(int keycode, t_minirt *rt);
int			close_cross(t_minirt *rt);

void		fxaa(t_mlx *mlx);

#endif
