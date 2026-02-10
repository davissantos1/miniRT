/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:16:11 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/10 09:24:06 by vitosant         ###    ########.fr      */
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
typedef struct	s_shape
{
	t_shape		type;
}	t_wildcard;

typedef struct	s_hit
{
	int				num_roots;
	double			r1;
	double			r2;
	unsigned int	color;
}	t_hit;

typedef struct	s_sphere
{
	t_shape		type;
	t_point		pos;
	t_color		color;
	double		diam;
}	t_sphere;

typedef struct	s_plane
{
	t_shape		type;
	t_point		pos;
	t_vec4		norm;
	t_color		color;
	double		diam;
}	t_plane;

typedef struct	s_cylinder
{
	t_shape		type;
	t_point		pos;
	t_vec4		norm;
	t_color		color;
	double		diam;
	double		height;
}	t_cylinder;


typedef struct	s_circle
{
	t_shape		type;
	t_point		pos;
	t_vec4		norm;
	t_color		color;
	double		diam;
}	t_circle;

typedef struct	s_quadratic
{
	double	a;
	double	h;
	double	c;
}	t_quadratic;

// functions array
typedef bool	(*t_get_hit)(t_scene*, void*, t_hit*, t_ray);

// prototypes
bool	hit_sphere(t_scene *scene, void *me, t_hit *roots, t_ray ray);
bool	hit_cylinder(t_scene *scene, void *me, t_hit *hits, t_ray ray);
bool	hit_circle(t_scene *scene, void *me, t_hit *hit, t_ray ray);

void	set_roots(void *obj, double r1, double r2, t_hit *hits);

#endif
