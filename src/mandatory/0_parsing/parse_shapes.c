/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 10:45:34 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/20 18:09:34 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shapes.h"
#include "parsing.h"

static void	fill_material(t_material *m, char **c)
{
	m->color = vec4_init(ft_atod(c[0]), ft_atod(c[1]), ft_atod(c[2]), 0);
	m->color = vec4_scale((double) 1 / 255, m->color);
	m->ks = vec4_init(0.9, 0.9, 0.9, 0);
	m->ka = vec4_scale(1.0 / 3.0, m->color);
	m->shininess = 32.0;
}

void	parse_plane(t_minirt *rt, char **ent)
{
	t_plane		*pl;
	char		**p;
	char		**n;
	char		**c;

	p = ft_split(ent[1], ',');
	n = ft_split(ent[2], ',');
	c = ft_split(ent[3], ',');
	pl = gc_malloc(sizeof(t_plane), rt->gc, GC_DEFAULT);
	if (!check_plane(p, n, c) || !pl || ft_mtxlen(ent) > 4)
		desperation(rt, ERR_FILE_INVALID);
	pl->type = PLANE;
	pl->pos = vec4_init(ft_atod(p[0]), ft_atod(p[1]), ft_atod(p[2]), 1);
	pl->norm = vec4_init(ft_atod(n[0]), ft_atod(n[1]), ft_atod(n[2]), 0);
	pl->norm = vec4_unit_vector(pl->norm);
	fill_material(&pl->mat, c);
	add_object(rt, pl);
	ft_mtxfree(p);
	ft_mtxfree(n);
	ft_mtxfree(c);
}

void	parse_sphere(t_minirt *rt, char **ent)
{
	t_sphere	*sp;
	char		**p;
	char		**c;

	p = ft_split(ent[1], ',');
	c = ft_split(ent[3], ',');
	if (!check_sphere(p, ent[2], c) || ft_mtxlen(ent) > 4)
		desperation(rt, ERR_FILE_INVALID);
	sp = gc_malloc(sizeof(t_sphere), rt->gc, GC_DEFAULT);
	if (!sp)
		desperation(rt, ERR_FILE_INVALID);
	sp->type = SPHERE;
	sp->pos = vec4_init(ft_atod(p[0]), ft_atod(p[1]), ft_atod(p[2]), 0);
	fill_material(&sp->mat, c);
	sp->pos = vec4_init(ft_atod(p[0]), ft_atod(p[1]), ft_atod(p[2]), 1);
	sp->diam = ft_atod(ent[2]);
	add_object(rt, sp);
	ft_mtxfree(p);
	ft_mtxfree(c);
}

void	parse_cylinder(t_minirt *rt, char **ent)
{
	t_cylinder	*cy;
	char		**p;
	char		**n;
	char		**c;

	p = ft_split(ent[1], ',');
	n = ft_split(ent[2], ',');
	c = ft_split(ent[5], ',');
	cy = gc_malloc(sizeof(t_cylinder), rt->gc, GC_DEFAULT);
	if (!check_cylinder(p, n, c) || !is_pos(ent[3]) || !is_pos(ent[4]) || !cy)
		desperation(rt, ERR_FILE_INVALID);
	if (ft_mtxlen(ent) > 6)
		desperation(rt, ERR_FILE_INVALID);
	cy->type = CYLINDER;
	cy->pos = vec4_init(ft_atod(p[0]), ft_atod(p[1]), ft_atod(p[2]), 1);
	cy->norm = vec4_init(ft_atod(n[0]), ft_atod(n[1]), ft_atod(n[2]), 0);
	cy->norm = vec4_unit_vector(cy->norm);
	fill_material(&cy->mat, c);
	cy->diam = ft_atod(ent[3]);
	cy->height = ft_atod(ent[4]);
	add_object(rt, cy);
	ft_mtxfree(p);
	ft_mtxfree(n);
	ft_mtxfree(c);
}
