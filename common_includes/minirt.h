/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:20:36 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/18 19:57:51 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// Local includes
# include "../libft/libft.h"
# include "settings.h"
# include "entities.h"
# include "structs.h"

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
int			is_pos(char *num);

void		add_object(t_minirt *rt, void *obj);
void		add_light(t_minirt *rt, t_light *l);
void		img_pixel_put(t_mlx *mlx, int x, int y, int color);
void		run_rt(t_minirt	*ctx);

int			hook_keys(int keycode, t_minirt *rt);
int			close_cross(t_minirt *rt);
void		test_parser(t_minirt *rt);
char		*get_name(char *name);
void		rm_newline(char **line);
int			rt_redraw(t_minirt *rt);

// rotate camera
void		rotate_x(t_camera *cam, double angle);
void		rotate_y(t_camera *cam, double angle);

#endif
