/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:20:36 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/22 07:42:19 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// Local includes
# include "../libft/libft.h"
# include "settings.h"
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
void		img_pixel_put(t_mlx *mlx, int x, int y, int color);
void		run_rt(t_minirt	*ctx);

int			hook_keys(int keycode, t_minirt *rt);
int			close_cross(t_minirt *rt);
void		test_parser(t_minirt *rt);
char		*get_name(char *name);

#endif
