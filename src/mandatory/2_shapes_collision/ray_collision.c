/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 10:17:33 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/15 10:33:06 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

inline static t_shape	get_type(t_handle *me)
{
	return (me->type);
}

static void	fill_functions(t_get_hit *functions)
{
	functions[SPHERE] = hit_sphere;
	functions[CYLINDER] = hit_cylinder;
	functions[DISK] = hit_disk;
	functions[PLANE] = hit_plane;
}

t_hit	ray_collision(t_scene *scene, t_ray ray)
{
	static t_get_hit	functions[SHAPE_COUNT];
	t_hit				hits;
	t_list				*lst;

	hits = (t_hit){0};
	lst = scene->shape;
	if (!functions[SPHERE])
		fill_functions(functions);
	while (lst)
	{
		functions[get_type(lst->content)](lst->content, &hits, ray);
		lst = lst->next;
	}
	hits.ray_dir = ray.dir;
	return (hits);
}

