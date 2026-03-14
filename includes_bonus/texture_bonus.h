/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 08:21:27 by vitosant          #+#    #+#             */
/*   Updated: 2026/03/14 10:24:59 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_BONUS_H
# define TEXTURE_BONUS_H

# include "structs.h"
# include "vec4.h"

typedef enum e_map_type
{
	BUMP_MAP,
	NORMAL_MAP,
	NO_TEXTURE
}	t_map_type;

typedef struct s_texture
{
	void	*mlx_ptr;
	void	*img;
	char	*addr;
	int		bpp;
	int		width;
	int		height;
	int		line;
	int		end;
}	t_texture;

typedef void	(*t_uv_map)(t_point, double *, double *);

t_texture	load_img(t_minirt *ctx, char *path);

void		uv_sphere(t_point p, double *u, double *v);
void		uv_cylinder(t_point p, double *u, double *v);
void		uv_plane(t_point p, double *u, double *v);
void		uv_disk(t_point p, double *u, double *v);
void		uv_cone(t_point p, double *u, double *v);
void	    uv_rectangle(t_point p, double *u, double *v);

void		destroy_texture(void *content);

#endif
