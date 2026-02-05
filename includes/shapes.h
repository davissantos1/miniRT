/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:16:11 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/05 11:30:51 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

typedef enum e_shape
{
	SPHERE,
	PLANE,
	CYLINDER
}	t_shape;

struct	s_shape
{
	t_shape		type;
};

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

#endif
