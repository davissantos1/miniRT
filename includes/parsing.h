/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:03:08 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/11 17:54:14 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "structs.h"

// Signatures
void	parse_minirt(t_minirt *rt, int fd);
void	parse_entity(t_minirt *rt, char **entity);
void	parse_alight(t_minirt *rt, char **entity);
void	parse_camera(t_minirt *rt, char **entity);
void	parse_light(t_minirt *rt, char **entity);

void	parse_plane(t_minirt *rt, char **entity);
void	parse_sphere(t_minirt *rt, char **entity);
void	parse_cylinder(t_minirt *rt, char **entity);

int		check_alight(char *ratio, char **color);
int		check_camera(char **pos, char **norm, char *fov);
int		check_light(char **pos, char *ratio, char **color);

int		check_plane(char **pos, char **norm, char **color);
int		check_sphere(char **pos, char *diam, char **color);
int		check_cylinder(char **pos, char **norm, char **color);

int		check_pos(char **pos);
int		check_norm(char **norm);
int		check_ratio(char *ratio);
int		check_fov(char *fov);
int		check_color(char **color);

#endif
