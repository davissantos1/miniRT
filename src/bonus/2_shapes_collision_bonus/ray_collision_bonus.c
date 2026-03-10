/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_collision_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 10:17:33 by vitosant          #+#    #+#             */
/*   Updated: 2026/03/10 14:05:56 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "texture_bonus.h"
#include "pattern_bonus.h"
#include "shapes_bonus.h"

inline static t_shape	get_type(t_handle *me)
{
	return (me->type);
}

t_hit	ray_collision(t_scene *scene, t_ray ray)
{
	t_hit				hits;
	t_list				*lst;
	static t_get_hit	functions[SHAPE_COUNT] = {
		hit_sphere,
		hit_plane,
		hit_cylinder,
		hit_disk,
		hit_cone
	};

	hits = (t_hit){0};
	lst = scene->shape;
	while (lst)
	{
		functions[get_type(lst->content)](lst->content, &hits, ray);
		lst = lst->next;
	}
	if (!hits.num_roots)
		return (hits);
	if (hits.mat.pattern != NO_PATTERN)
		get_pattern(&hits, hits.mat.pattern);
	if (hits.mat.map_type != NO_TEXTURE)
		get_texture(&hits);
	hits.ray_dir = ray.dir;
	return (hits);
}
