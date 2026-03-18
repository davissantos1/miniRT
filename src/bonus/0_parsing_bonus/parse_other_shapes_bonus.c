/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_other_shapes_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 12:05:35 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/18 18:53:35 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes_bonus.h"
#include "settings.h"
#include "minirt.h"
#include "parsing_bonus.h"

void	parse_paral(t_minirt *rt, char **ent)
{
	t_parallelepiped	*pa;
	char				**p;
	char				**n;

	p = ft_split(ent[1], ',');
	n = ft_split(ent[2], ',');
	pa = gc_calloc(sizeof(t_parallelepiped), rt->gc, GC_DEFAULT);
	if (!check_paral(rt, p, n, ent + 6))
		desperation(rt, ERR_FILE_INVALID);
	if (!is_pos(ent[3]) || !is_pos(ent[4]) || !is_pos(ent[5]))
		desperation(rt, ERR_FILE_INVALID);
	if (!pa)
		desperation(rt, ERR_SYSCALL);
	pa->type = PARALLELEPIPED;
	pa->pos = vec4_init(ft_atod(p[0]), ft_atod(p[1]), ft_atod(p[2]), 1);
	pa->norm = vec4_init(ft_atod(n[0]), ft_atod(n[1]), ft_atod(n[2]), 0);
	pa->norm = vec4_unit_vector(pa->norm);
	pa->height = ft_atod(ent[3]);
	pa->width = ft_atod(ent[4]);
	pa->depth = ft_atod(ent[5]);
	pa->mat = parse_material(rt, ent + 6);
	pa->mat.pattern_const = 2;
	add_object(rt, pa);
	ft_mtxfree(p);
	ft_mtxfree(n);
}

void	parse_rect(t_minirt *rt, char **ent)
{
	t_rectangle	*re;
	char		**p;
	char		**n;

	p = ft_split(ent[1], ',');
	n = ft_split(ent[2], ',');
	re = gc_calloc(sizeof(t_rectangle), rt->gc, GC_DEFAULT);
	if (!check_rect(rt, p, n, ent + 5))
		desperation(rt, ERR_FILE_INVALID);
	if (!is_pos(ent[3]) || !is_pos(ent[4]))
		desperation(rt, ERR_FILE_INVALID);
	if (!re)
		desperation(rt, ERR_SYSCALL);
	re->type = RECTANGLE;
	re->pos = vec4_init(ft_atod(p[0]), ft_atod(p[1]), ft_atod(p[2]), 1);
	re->norm = vec4_init(ft_atod(n[0]), ft_atod(n[1]), ft_atod(n[2]), 0);
	re->norm = vec4_unit_vector(re->norm);
	re->height = ft_atod(ent[3]);
	re->width = ft_atod(ent[4]);
	re->mat = parse_material(rt, ent + 5);
	re->mat.pattern_const = 2;
	re->transform = rectangle_transform(re, &re->inverse);
	add_object(rt, re);
	ft_mtxfree(p);
	ft_mtxfree(n);
}
