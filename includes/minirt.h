/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:20:36 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/05 11:17:56 by dasimoes         ###   ########.fr       */
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

// Macros
# define WIDTH 1080
# define HEIGHT 1080

// Enums
typedef enum e_status
{
	SUCCESS,
	ERR_ARG_NUM,
	ERR_ARG_INVALID,
	ERR_FILE_INVALID,
	ERR_SYSCALL,
	COUNT
}	t_status;

// Structs
typedef struct s_scene
{
	struct s_alight		*alight;
	struct s_camera		*camera;
	struct s_light		*light;
	t_list				*shape;	
}	t_scene;

typedef struct	s_alight
{
	double		ratio;
	t_color		color;
}	t_alight;

typedef struct	s_camera
{
	t_point		pos;
	t_vec4		norm;
	t_color		color;
	int			fov;
}	t_camera;

typedef struct	s_light
{
	t_point		pos;
	double		ratio;
	t_color		color;
}	t_light;

typedef struct s_mlx
{
	void		*init;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line;
	int			end;
}	t_mlx;

typedef struct s_minirt
{
	char	*name;
	t_gc	*gc;
	t_mlx	*mlx;
	t_scene	*scene;
}	t_minirt;

//Prototypes
t_status	panic(t_status status);
void		real_panic(t_status status);
int			check_filename(char *file);
t_minirt	*minirt_start(char *name);
t_mlx		*mlx_start(t_gc *gc, char *name);

#endif
