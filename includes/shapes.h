/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:16:11 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/20 22:48:19 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include <math.h>
# include "vec4.h"
# include "ray.h"
# include "structs.h"
# include "entities.h"

# define PI 3.14159265359
# define EPSILON 1e-7

// enums
typedef enum e_shape
{
	SPHERE,
	PLANE,
	CYLINDER,
	DISK,
	SHAPE_COUNT
}	t_shape;

typedef enum e_pattern
{
	CHECKER,
	GRADIENT,
	STRIPED,
	RING,
	COUNT_PATTERNS,
	NO_PATTERN
}	t_pattern;


//structs
typedef struct	s_material
{
	t_pattern	pattern;
	t_vec4		ka;
	t_vec4		ks;
	t_vec4		kr;
	t_vec4		color;
	double		shininess;
}	t_material;

typedef struct s_handle
{
	t_shape		type;
}	t_handle;

typedef struct s_hit
{
	int			num_roots;
	double		r1;
	double		r2;
	void		*me;
	t_vec4		norm;
	t_vec4		cam_dir;
	t_point		hit_point;
	t_vec4		ray_dir;
	t_material	mat;
}	t_hit;

typedef struct s_sphere
{
	t_shape		type;
	t_point		pos;
	t_material	mat;
	double		diam;
}	t_sphere;

typedef struct s_plane
{
	t_shape		type;
	t_point		pos;
	t_vec4		norm;
	t_material	mat;
}	t_plane;

typedef struct s_cylinder
{
	t_shape		type;
	t_point		pos;
	t_vec4		norm;
	t_material	mat;
	double		diam;
	double		height;
}	t_cylinder;

typedef struct s_disk
{
	t_shape		type;
	t_point		pos;
	t_vec4		norm;
	t_material	mat;
	double		diam;
}	t_disk;

typedef struct s_quadratic
{
	double	a;
	double	h;
	double	c;
	double	r1;
	double	r2;
}	t_formula;

// functions array
typedef bool	(*t_get_hit)(void*, t_hit*, t_ray);

// prototypes
t_hit	ray_collision(t_scene *scene, t_ray ray);
bool	hit_sphere(void *me, t_hit *hits, t_ray ray);
bool	hit_cylinder(void *me, t_hit *hits, t_ray ray);
bool	hit_disk(void *me, t_hit *hits, t_ray ray);
bool	hit_plane(void *me, t_hit *hits, t_ray ray);

t_color	phong(t_hit hits, t_scene *scene, int depth);
bool	shadows(t_scene *sc, t_light *lig, t_hit hit, t_vec4 light_dir);
t_color	reflections(t_scene *scene, t_hit hits, int depth);
#endif
