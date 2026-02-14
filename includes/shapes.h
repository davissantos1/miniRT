/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:16:11 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/14 12:44:15 by vitosant         ###    ########.fr      */
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
	t_vec4	ambi_reflec;
	t_vec4	spec_reflec;
	t_vec4	diff_reflec;
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
	t_material	material;
}	t_hit;

typedef struct	s_sphere
{
	t_shape		type;
	t_point		pos;
	t_color		color;
	t_material	material;
	double		diam;
}	t_sphere;

typedef struct	s_plane
{
	t_shape		type;
	t_point		pos;
	t_vec4		norm;
	t_color		color;
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
	t_color		color;
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
typedef bool	(*t_get_hit)(t_scene*, void*, t_hit*, t_ray);

// prototypes
bool	hit_sphere(t_scene *scene, void *me, t_hit *hits, t_ray ray);
bool	hit_cylinder(t_scene *scene, void *me, t_hit *hits, t_ray ray);
bool	hit_circle(t_scene *scene, void *me, t_hit *hits, t_ray ray);
bool	hit_plane(t_scene *scene, void *me, t_hit *hits, t_ray ray);

void	set_roots(void *obj, double r1, double r2, t_hit *hits);

unsigned int	phong(t_hit hits, t_scene *scene);

#endif
