/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:52:38 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/20 22:05:51 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../libft/libft.h"
# include "vec4.h"

typedef struct s_scene
{
	struct s_alight		*alight;
	struct s_camera		*camera;
	struct s_light		*light;
	t_list				*shape;	
}	t_scene;

typedef struct s_mlx
{
	void	*init;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		end;
}	t_mlx;

typedef struct s_minirt
{
	char	*name;
	t_gc	*gc;
	t_mlx	*mlx;
	t_scene	*scene;
}	t_minirt;

typedef struct s_ndc
{
	t_vec4	u;
	t_vec4	v;
	t_vec4	w;
	double	ratio;
	double	scale;
}	t_ndc;

#endif
