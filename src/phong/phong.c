/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:49:25 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/17 09:34:51 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"
#include "vec4.h"

unsigned int	phong(t_hit hits, t_scene *scene)
{
	t_light	*light;
	t_color	color;
	t_vec4	ambi_color;
	t_vec4	light_dir;

	light = scene->light;
	ambi_color = vec4_scale(scene->alight->ratio, scene->alight->color);
	ambi_color = vec4_times(ambi_color, hits.material.ka);
	color = ambi_color;
	while (light)
	{
		light_dir = vec4_minus(light->pos, hits.hit_point);
		light_dir = vec4_unit_vector(light_dir);
		if (!shadows(scene, light, hits, light_dir))
		{
			color = vec4_plus(color, diffusion(hits, light, light_dir));
			color = vec4_plus(color, specular(hits, light, light_dir));
		}
		light = light->next;
	}
	color = vec4_plus(color, reflections(scene, hits, 0));
	//debug color pae pra ver se as normais estão certas
	  /* t_vec4 n = hits.norm;  */
	  /* (void) scene;  */
	  /* color.x = (n.x + 1) * 0.5;  */
	  /* color.y = (n.y + 1) * 0.5;  */
	  /* color.z = (n.z + 1) * 0.5;  */
	color.x = fmin(1.0, color.x);
	color.y = fmin(1.0, color.y);
	color.z = fmin(1.0, color.z);
	color = vec4_scale(255, color);
	return ((int)color.x << 16 | (int)color.y << 8 | (int)color.z);
}

	// t_vec4 n = hits.norm;
	// (void) scene;
	// // Mapeia de [-1, 1] para [0, 1] para virar cor RGB
	// color.x = (n.x + 1) * 0.5;
	// color.y = (n.y + 1) * 0.5;
	// color.z = (n.z + 1) * 0.5;
