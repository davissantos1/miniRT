/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_material_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:43:54 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/08 14:48:55 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes_bonus.h"
#include "settings.h"
#include "minirt.h"
#include "parsing_bonus.h"

static void fill_material_aux(t_material *m, char ***v)
{
	m->color = vec4_init
				(ft_atod(v[0][0]), ft_atod(v[0][1]), ft_atod(v[0][2]), 0);
	m->color = vec4_scale((double) 1 / 255, m->color);
	if (v[1])
	{
		m->ka = vec4_init
				(ft_atod(v[1][0]), ft_atod(v[1][1]), ft_atod(v[1][2]), 0);
		m->ka = vec4_scale((double) 1 / 255, m->ka);
		m->ks = vec4_init(ft_atod(v[2][0]), ft_atod(v[2][1]), ft_atod(v[2][2]), 0);
		m->ks = vec4_scale((double) 1 / 255, m->ks);
		m->kr = vec4_init(ft_atod(v[3][0]), ft_atod(v[3][1]), ft_atod(v[3][2]), 0);
		m->kr = vec4_scale((double) 1 / 255, m->kr);
	}
}

static void	fill_material(t_minirt *rt, t_material *m, char **ent)
{
	char	***v;
	
	v = get_vars(rt, ent);
	fill_material_aux(m, v);
	if (v[1])
	{
		m->color2 = vec4_init
						(ft_atod(v[7][0]), ft_atod(v[7][1]), ft_atod(v[7][2]), 0);
		m->color2 = vec4_scale((double) 1 / 255, m->color2);
		m->ka2 = vec4_init
					(ft_atod(v[8][0]), ft_atod(v[8][1]), ft_atod(v[8][2]), 0);
		m->ka2 = vec4_scale((double) 1 / 255, m->ka2);
		m->ks2 = vec4_init
					(ft_atod(v[9][0]), ft_atod(v[9][1]), ft_atod(v[9][2]), 0);
		m->ks2 = vec4_scale((double) 1 / 255, m->ks2);
		m->kr2 = vec4_init
					(ft_atod(v[10][0]), ft_atod(v[10][1]), ft_atod(v[10][2]), 0);
		m->kr2 = vec4_scale((double) 1 / 255, m->kr2);
		m->shininess = ft_atod(v[11][0]);
	}
	free_vars(v);
}

static void	fill_pattern_map(t_minirt *rt, t_material *m, char *pat, char *map)
{
	if (!ft_strcmp(pat, "CHECKER"))
		m->pattern = CHECKER;
	else if (!ft_strcmp(pat, "STRIPED"))
		m->pattern = STRIPED;
	else if (!ft_strcmp(pat, "RING"))
		m->pattern = RING;
	else if (!ft_strcmp(pat, "NO_PATTERN"))
		m->pattern = NO_PATTERN;
	else
		desperation(rt, ERR_FILE_INVALID);
	if (!ft_strcmp(map, "BUMP_MAP"))
		m->map_type = BUMP_MAP;
	else if (!ft_strcmp(map, "NORMAL_MAP"))
		m->map_type = NORMAL_MAP;
	else if (!ft_strcmp(map, "NO_TEXTURE"))
		m->map_type = NO_TEXTURE;
	else
		desperation(rt, ERR_FILE_INVALID);
}

t_material	parse_material(t_minirt *rt, char **ent)
{
	char		**c;
	t_material	m;

	if (!ent[1])
	{
		c = ft_split(ent[0], ',');
		if (!c)
			desperation(rt, ERR_SYSCALL);
		m.color = vec4_init(ft_atod(c[0]), ft_atod(c[1]), ft_atod(c[2]), 0);
		m.color = vec4_scale((double) 1 / 255, m.color);
		m.pattern = NO_PATTERN;
		m.map_type = NO_TEXTURE;
		ft_mtxfree(c);
	}
	else
	{
		fill_material(rt, &m, ent);
		fill_pattern_map(rt, &m, ent[4], ent[10]);
		m.texture = load_img(rt, ent[11]);
	}
	return (m);
}
