/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 10:45:34 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/14 13:18:02 by vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_plane(t_minirt *rt, char **entity)
{
	t_plane		*pl;
	char		**p;
	char		**n;
	char		**c;

	p = ft_split(entity[1], ',');
	n = ft_split(entity[2], ',');
	c = ft_split(entity[3], ',');
	if (!check_plane(p, n, c))
		desperation(rt->gc, ERR_FILE_INVALID);
	pl = gc_malloc(sizeof(t_plane), rt->gc, GC_DEFAULT);
	if (!pl)
		desperation(rt->gc, ERR_FILE_INVALID);
	pl->type = PLANE;
	pl->pos = vec4_init(ft_atod(p[0]), ft_atod(p[1]), ft_atod(p[2]), 0);
	pl->norm = vec4_init(ft_atod(n[0]), ft_atod(n[1]), ft_atod(n[2]), 0);
	pl->material.color = vec4_init(ft_atod(c[0]), ft_atod(c[1]), ft_atod(c[2]), 0);
	pl->material.color = vec4_scale(1 / 255, pl->material.color);
	pl->material.ks = vec4_init(0.9, 0.9, 0.9, 0);
	pl->material.ka = vec4_scale(1.0 / 3.0, pl->material.color);
	pl->material.shininess = 32.0;
	add_object(rt, pl);
	free(p);
	free(n);
	free(c);
}

void	parse_sphere(t_minirt *rt, char **entity)
{
	t_sphere	*sp;
	char		**p;
	char		**c;

	p = ft_split(entity[1], ',');
	c = ft_split(entity[3], ',');
	if (!check_sphere(p, entity[2], c))
		desperation(rt->gc, ERR_FILE_INVALID);
	sp = gc_malloc(sizeof(t_sphere), rt->gc, GC_DEFAULT);
	if (!sp)
		desperation(rt->gc, ERR_FILE_INVALID);
	sp->type = SPHERE;
	sp->pos = vec4_init(ft_atod(p[0]), ft_atod(p[1]), ft_atod(p[2]), 0);
	sp->material.color = vec4_init(ft_atod(c[0]), ft_atod(c[1]), ft_atod(c[2]), 0);
	sp->material.color = vec4_scale(1 / 255, sp->material.color);
	sp->material.ks = vec4_init(0.9, 0.9, 0.9, 0);
	sp->material.ka = vec4_scale(1.0 / 3.0, sp->material.color);
	sp->diam = ft_atod(entity[2]);
	sp->material.shininess = 32.0;
	add_object(rt, sp);
	free(p);
	free(c);
}

void	parse_cylinder(t_minirt *rt, char **entity)
{
	t_cylinder	*cy;
	char		**p;
	char		**n;
	char		**c;

	p = ft_split(entity[1], ',');
	n = ft_split(entity[2], ',');
	c = ft_split(entity[5], ',');
	if (!check_cylinder(p, n, c))
		desperation(rt->gc, ERR_FILE_INVALID);
	if (!check_positive(entity[3]) || !check_positive(entity[4]))
		desperation(rt->gc, ERR_FILE_INVALID);
	cy = gc_malloc(sizeof(t_cylinder), rt->gc, GC_DEFAULT);
	if (!cy)
		desperation(rt->gc, ERR_FILE_INVALID);
	cy->type = CYLINDER;
	cy->pos = vec4_init(ft_atod(p[0]), ft_atod(p[1]), ft_atod(p[2]), 0);
	cy->norm = vec4_init(ft_atod(n[0]), ft_atod(n[1]), ft_atod(n[2]), 0);
	cy->material.color = vec4_init(ft_atod(c[0]), ft_atod(c[1]), ft_atod(c[2]), 0);
	cy->material.color = vec4_scale(1 / 255, cy->material.color);
	cy->material.ks = vec4_init(0.9, 0.9, 0.9, 0);
	cy->material.ka = vec4_scale(1.0 / 3.0, cy->material.color);
	cy->diam = ft_atod(entity[3]);
	cy->height = ft_atod(entity[4]);
	add_object(rt, cy);
	cy->material.shininess = 32.0;
	free(p);
	free(n);
	free(c);
}
