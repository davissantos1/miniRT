/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 08:21:27 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/28 13:51:21 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# include "structs.h"

typedef enum e_map_type
{
	BUMP_MAP,
	NORMAL_MAP,
	NO_TEXTURE
}	t_map_type;

typedef struct	s_texture
{
	void	*img;
	char	*addr;
	int		bpp;
	int		width;
	int		height;
	int		line;
	int		end;
}	t_texture;

typedef void (*uv_map)(t_point, double *, double *);
	
t_texture	load_img(t_minirt *ctx, char *path);

void	uv_sphere(t_point p, double *u, double *v);
void	uv_cylinder(t_point p, double *u, double *v);
void	uv_plane(t_point p, double *u, double *v);
void	uv_disk(t_point p, double *u, double *v);
void	uv_cone(t_point p, double *u, double *v);

void	destroy_texture(void *content);

#endif
