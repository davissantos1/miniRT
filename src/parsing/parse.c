/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:31:39 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/05 18:43:07 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_minirt(t_minirt *rt, int fd)
{
	char	*line;
	char	**split;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		split = ft_split(line, ' ');
		
	}	
	if (!sc->alight && !sc->camera && !sc->light && !sc->shape)
		real_panic();
}

void	parse_entity(t_minirt *rt, char **entity)
{
	t_scene				*sc;
	const t_map_shape	*shapes;
	int					index;

	index = -1;
	sc = rt->scene;
	shapes = get_shapes();
	if (!entity || !*entity)
		return ;
	while (shapes[++index])
	{
		if (ft_strcmp(shapes[index].id, *entity) == 0)
		{
			shapes[index].handler(rt, entity);
			return ;
		}
	}
	desperation(rt, ERR_FILE_INVALID);
}

void	parse_alight(t_minirt *rt, char **entity)
{
	t_alight	*alight;

	if (!check_entity(entity))
		desperation(rt, ERR_FILE_INVALID);
	alight = gc_malloc(sizeof(t_alight), rt->gc, GC_DEFAULT);
	if (!alight)
		desperation(rt, ERR_FILE_INVALID);
	alight->ratio = atod(entity[1]);
	

}

void	parse_camera(t_minirt *rt, char **entity)
{

}

void	parse_light(t_minirt *rt, char **entity)
{

}
