/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:31:39 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/13 15:26:02 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_minirt(t_minirt *rt, int fd)
{
	t_scene	*sc;
	char	*line;
	char	**split;

	sc = rt->scene;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (check_empty(line))
			continue ;
		line[ft_strlen(line) - 1] = '\0';
		split = ft_split(line, ' ');
		if (!split)
			desperation(rt->gc, ERR_SYSCALL);
		parse_entity(rt, split);
	}	
	if (!sc->alight || !sc->camera || !sc->light || !sc->shape)
		desperation(rt->gc, ERR_FILE_INVALID);
	if (!gc_addlst(rt->scene->shape, rt->gc, GC_DEFAULT))
		desperation(rt->gc, ERR_SYSCALL);
}

void	parse_entity(t_minirt *rt, char **entity)
{
	const t_map_shape		*shapes;
	int						index;

	index = -1;
	shapes = get_shapes();
	if (!entity || !*entity)
		return ;
	while (shapes[++index].id)
	{
		if (ft_strcmp(shapes[index].id, *entity) == 0)
		{
			shapes[index].handler(rt, entity);
			return ;
		}
	}
	desperation(rt->gc, ERR_FILE_INVALID);
}

void	parse_alight(t_minirt *rt, char **entity)
{
	t_alight	*amb;
	char		**c;

	if (rt->scene->alight)
		desperation(rt->gc, ERR_FILE_INVALID);
	c = ft_split(entity[2], ',');
	if (!check_alight(entity[1], c))
		desperation(rt->gc, ERR_FILE_INVALID);
	amb = gc_malloc(sizeof(t_alight), rt->gc, GC_DEFAULT);
	if (!amb)
		desperation(rt->gc, ERR_FILE_INVALID);
	amb->ratio = ft_atod(entity[1]);
	amb->color = vec4_init(ft_atod(c[0]), ft_atod(c[1]), ft_atod(c[2]), 0);
	amb->color = vec4_scale(1/255, amb->color);
	rt->scene->alight = amb;
	free(c);
}

void	parse_camera(t_minirt *rt, char **entity)
{
	t_camera	*cam;
	char		**p;
	char		**n;

	if (rt->scene->camera)
		desperation(rt->gc, ERR_FILE_INVALID);
	p = ft_split(entity[1], ',');
	n = ft_split(entity[2], ',');
	if (!check_camera(p, n, entity[3]))
		desperation(rt->gc, ERR_FILE_INVALID);
	cam = gc_malloc(sizeof(t_camera), rt->gc, GC_DEFAULT);
	if (!cam)
		desperation(rt->gc, ERR_FILE_INVALID);
	cam->pos = vec4_init(ft_atod(p[0]), ft_atod(p[1]), ft_atod(p[2]), 1);
	cam->norm = vec4_init(ft_atod(n[0]), ft_atod(n[1]), ft_atod(n[2]), 1);
	cam->fov = ft_atoi(entity[3]);
	rt->scene->camera = cam;
	free(p);
	free(n);
}

void	parse_light(t_minirt *rt, char **entity)
{
	t_light		*lig;
	char		**c;
	char		**p;

	if (rt->scene->light)
		desperation(rt->gc, ERR_FILE_INVALID);
	c = ft_split(entity[3], ',');
	p = ft_split(entity[1], ',');
	if (!check_light(p, entity[2], c))
		desperation(rt->gc, ERR_FILE_INVALID);
	lig = gc_malloc(sizeof(t_light), rt->gc, GC_DEFAULT);
	if (!lig)
		desperation(rt->gc, ERR_FILE_INVALID);
	lig->pos = vec4_init(ft_atod(p[0]), ft_atod(p[1]), ft_atod(p[2]), 1);
	lig->color = vec4_init(ft_atod(c[0]), ft_atod(c[1]), ft_atod(c[2]), 0);
	lig->color = vec4_scale(1/255, lig->color);
	lig->ratio = ft_atod(entity[2]);
	rt->scene->light = lig;
	free(c);
	free(p);
}
