/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:03:17 by vitosant          #+#    #+#             */
/*   Updated: 2026/03/18 20:10:47 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture_bonus.h"
#include "vec4.h"
#include "shapes_bonus.h"

void	get_texture(t_hit *hit)
{
	static t_texture_map	options[2] = {bump_map, normal_map};
	static t_uv_map			maps[SHAPE_COUNT] = {uv_sphere, uv_plane,
		uv_cylinder, uv_disk, uv_cone, uv_rectangle};
	t_point					p;

	p = vec4_multi_mtx4(hit->inverse, hit->hit_point);
	options[hit->mat.map_type](hit, maps, p);
}
