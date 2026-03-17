/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:03:08 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/17 12:19:10 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_BONUS_H
# define PARSING_BONUS_H

# include "structs.h"
# include "shapes_bonus.h"

// Signatures
void		parse_minirt(t_minirt *rt, int fd);
void		parse_entity(t_minirt *rt, char **ent);
void		parse_alight(t_minirt *rt, char **ent);
void		parse_camera(t_minirt *rt, char **ent);
void		parse_light(t_minirt *rt, char **ent);

void		parse_plane(t_minirt *rt, char **ent);
void		parse_sphere(t_minirt *rt, char **ent);
void		parse_cylinder(t_minirt *rt, char **ent);
void		parse_cone(t_minirt *rt, char **ent);
void		parse_disk(t_minirt *rt, char **ent);
void		parse_paral(t_minirt *rt, char **ent);
void		parse_rect(t_minirt *rt, char **ent);

int			check_alight(char *ratio, char **color);
int			check_camera(char **pos, char **norm, char *fov);
int			check_light(char **pos, char *ratio, char **color);

int			check_plane(t_minirt *rt, char **pos, char **norm, char **ent);
int			check_sphere(t_minirt *rt, char **pos, char *diam, char **ent);
int			check_cylinder(t_minirt *rt, char **pos, char **norm, char **ent);
int			check_cone(t_minirt *rt, char **pos, char **norm, char **ent);
int			check_disk(t_minirt *rt, char **pos, char **norm, char **ent);
int			check_paral(t_minirt *rt, char **pos, char **norm, char **ent);
int			check_rect(t_minirt *rt, char **pos, char **norm, char **ent);

int			check_pos(char **pos);
int			check_norm(char **norm);
int			check_ratio(char *ratio);
int			check_fov(char *fov);
int			check_color(char **color);

char		***get_vars(t_minirt *rt, char **ent);
void		free_vars(char ***vars);
t_material	parse_material(t_minirt *rt, char **ent);

#endif
