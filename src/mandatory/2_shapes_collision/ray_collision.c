/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_collision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 10:17:33 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/20 23:08:03 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

inline static t_shape	get_type(t_handle *me)
{
	return (me->type);
}

t_hit	ray_collision(t_scene *scene, t_ray ray)
{
	static t_get_hit	functions[3] = {hit_sphere, hit_plane, hit_cylinder};
	t_hit				hits;
	t_list				*lst;

	hits = (t_hit){0};
	lst = scene->shape;
	while (lst)
	{
		functions[get_type(lst->content)](lst->content, &hits, ray);
		lst = lst->next;
	}
	return (hits);
}
