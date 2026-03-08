/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 10:45:34 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/08 15:29:21 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes_bonus.h"
#include "settings.h"
#include "minirt.h"
#include "parsing_bonus.h"

void	parse_plane(t_minirt *rt, char **ent)
{
	t_plane		*pl;
	char		**p;
	char		**n;

	p = ft_split(ent[1], ',');
	n = ft_split(ent[2], ',');
	if (!check_plane(rt, p, n, ent + 3))
		desperation(rt, ERR_FILE_INVALID);
	pl = gc_calloc(sizeof(t_plane), rt->gc, GC_DEFAULT);
	if (!pl)
		desperation(rt, ERR_FILE_INVALID);
	pl->type = PLANE;
	pl->pos = vec4_init(ft_atod(p[0]), ft_atod(p[1]), ft_atod(p[2]), 1);
	pl->norm = vec4_init(ft_atod(n[0]), ft_atod(n[1]), ft_atod(n[2]), 0);
	pl->mat = parse_material(rt, ent + 3);
	pl->mat.pattern_const = 1;
	add_object(rt, pl);
	ft_mtxfree(p);
	ft_mtxfree(n);
}

void	parse_sphere(t_minirt *rt, char **ent)
{
	t_sphere	*sp;
	char		**p;

	p = ft_split(ent[1], ',');
	if (!check_sphere(rt, p, ent[2], ent + 3))
		desperation(rt, ERR_FILE_INVALID);
	sp = gc_calloc(sizeof(t_sphere), rt->gc, GC_DEFAULT);
	if (!sp)
		desperation(rt, ERR_FILE_INVALID);
	sp->type = SPHERE;
	sp->pos = vec4_init(ft_atod(p[0]), ft_atod(p[1]), ft_atod(p[2]), 1);
	sp->diam = ft_atod(ent[2]);
	sp->mat = parse_material(rt, ent + 3);
	sp->mat.pattern_const = 2;
	add_object(rt, sp);
	ft_mtxfree(p);
}

void	parse_cylinder(t_minirt *rt, char **ent)
{
	t_cylinder	*cy;
	char		**p;
	char		**n;

	p = ft_split(ent[1], ',');
	n = ft_split(ent[2], ',');
	cy = gc_calloc(sizeof(t_cylinder), rt->gc, GC_DEFAULT);
	if (!check_cylinder(rt, p, n, ent + 5))
		desperation(rt, ERR_FILE_INVALID);
	if (!is_pos(ent[3]) || !is_pos(ent[4]))
		desperation(rt, ERR_FILE_INVALID);
	if (!cy)
		desperation(rt, ERR_SYSCALL);
	cy->type = CYLINDER;
	cy->pos = vec4_init(ft_atod(p[0]), ft_atod(p[1]), ft_atod(p[2]), 1);
	cy->norm = vec4_init(ft_atod(n[0]), ft_atod(n[1]), ft_atod(n[2]), 0);
	cy->diam = ft_atod(ent[3]);
	cy->height = ft_atod(ent[4]);
	cy->mat = parse_material(rt, ent + 5);
	cy->mat.pattern_const = 2;
	add_object(rt, cy);
	ft_mtxfree(p);
	ft_mtxfree(n);
}

void	parse_cone(t_minirt *rt, char **ent)
{
	t_cone		*co;
	char		**p;
	char		**n;

	p = ft_split(ent[1], ',');
	n = ft_split(ent[2], ',');
	co = gc_calloc(sizeof(t_cone), rt->gc, GC_DEFAULT);
	if (!check_cone(rt, p, n, ent + 5) || !is_pos(ent[3]) || !is_pos(ent[4]))
		desperation(rt, ERR_FILE_INVALID);
	if (!co)
		desperation(rt, ERR_SYSCALL);
	co->type = CONE;
	co->pos = vec4_init(ft_atod(p[0]), ft_atod(p[1]), ft_atod(p[2]), 1);
	co->norm = vec4_init(ft_atod(n[0]), ft_atod(n[1]), ft_atod(n[2]), 0);
	co->diam = ft_atod(ent[3]);
	co->height = ft_atod(ent[4]);
	co->mat = parse_material(rt, ent + 5);
	co->mat.pattern_const = 7;
	add_object(rt, co);
	ft_mtxfree(p);
	ft_mtxfree(n);
}

void	parse_disk(t_minirt *rt, char **ent)
{
	t_disk		*di;
	char		**p;
	char		**n;

	p = ft_split(ent[1], ',');
	n = ft_split(ent[2], ',');
	di = gc_calloc(sizeof(t_disk), rt->gc, GC_DEFAULT);
	if (!check_disk(rt, p, n, ent + 4) || !is_pos(ent[3]))
		desperation(rt, ERR_FILE_INVALID);
	if (!di)
		desperation(rt, ERR_SYSCALL);
	di->type = DISK;
	di->pos = vec4_init(ft_atod(p[0]), ft_atod(p[1]), ft_atod(p[2]), 1);
	di->norm = vec4_init(ft_atod(n[0]), ft_atod(n[1]), ft_atod(n[2]), 0);
	di->diam = ft_atod(ent[3]);
	di->mat = parse_material(rt, ent + 4);
	di->mat.pattern_const = 2;
	add_object(rt, di);
	ft_mtxfree(p);
	ft_mtxfree(n);
}
