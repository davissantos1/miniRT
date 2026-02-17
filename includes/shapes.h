/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:16:11 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/17 09:41:41 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "vec4.h"
# include "ray.h"
# include "minirt.h"

// enums
typedef enum e_shape
{
	SPHERE,
	PLANE,
	CYLINDER,
	CIRCLE,
	SHAPE_COUNT
}	t_shape;

//structs

typedef struct	s_material
{
	t_vec4	ka;
	t_vec4	ks;
	t_vec4	kr;
	t_vec4	color;
	double	shininess;
}	t_material;

typedef struct	s_shape
{
	t_shape		type;
}	t_wildcard;

typedef struct	s_hit
{
	int			num_roots;
	double		r1;
	double		r2;
	void		*me;
	t_vec4		norm;
	t_vec4		cam_dir;
	t_point		hit_point;
	t_vec4		ray_dir;
	t_material	material;
}	t_hit;

typedef struct	s_sphere
{
	t_shape		type;
	t_point		pos;
	t_material	material;
	double		diam;
}	t_sphere;

typedef struct	s_plane
{
	t_shape		type;
	t_point		pos;
	t_vec4		norm;
	t_material	material;
}	t_plane;

typedef struct	s_cylinder
{
	t_shape		type;
	t_point		pos;
	t_vec4		norm;
	t_material	material;
	double		diam;
	double		height;
}	t_cylinder;


typedef struct	s_circle
{
	t_shape		type;
	t_point		pos;
	t_vec4		norm;
	t_material	material;
	double		diam;
}	t_circle;

typedef struct	s_quadratic
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
bool	hit_circle(void *me, t_hit *hits, t_ray ray);
bool	hit_plane(void *me, t_hit *hits, t_ray ray);

unsigned int	phong(t_hit hits, t_scene *scene);
t_vec4			specular(t_hit hits, t_light *light, t_vec4 light_dir);
t_vec4			diffusion(t_hit hits, t_light *light, t_vec4 light_dir);

bool			shadows(t_scene *scene,
						t_light *light, t_hit hit, t_vec4 light_dir);
t_color			reflections(t_scene *scene, t_hit hits, int depth);
t_vec4			reflec_dir(t_vec4 norm, t_vec4 dir);

#endif
