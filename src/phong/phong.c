/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:49:25 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/15 14:23:48 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"
#include "vec4.h"

static inline t_vec4	diffusion(t_hit hits, t_light *light, t_vec4 light_dir)
{
	double	angle;
	t_vec4	light_color;
	t_vec4	ret;

	angle = vec4_dot(hits.norm, light_dir);
	if (angle <= 1e-7)
		return ((t_color){0});
	light_color = vec4_scale(light->ratio, light->color);
	ret = vec4_times(light_color, hits.material.color);
	return (vec4_scale(angle, ret));
}

static inline t_vec4	specular(t_hit hits, t_light *light, t_vec4 light_dir)
{
	t_color	intensity;
	t_vec4	color_shine;
	t_vec4	reflection;
	double	dot_ref;
	double	shinin;

	intensity = vec4_scale(light->ratio, light->color);
	dot_ref = vec4_dot(hits.norm, light_dir) * 2.0;
	reflection = vec4_minus(vec4_scale(dot_ref, hits.norm), light_dir);
	shinin = vec4_dot(hits.cam_dir, reflection);
	if (dot_ref < 0 || shinin < 0)
		return ((t_color){0});
	shinin = pow(shinin, hits.material.shininess);
	color_shine = vec4_scale(shinin, hits.material.spec_reflec);
	return (vec4_times(color_shine, intensity));
}

unsigned int	phong(t_hit hits, t_scene *scene)
{
	t_light	*light;
	t_color	color;
	t_vec4	ambi_color;
	t_vec4	light_dir;

	light = scene->light;
	ambi_color = vec4_scale(scene->alight->ratio, scene->alight->color);
	ambi_color = vec4_times(ambi_color, hits.material.ambi_reflec);
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
	//debug color pae pra ver se as normais estão certas
	 /* t_vec4 n = hits.norm; */
	 /* (void) scene; */
	 /* color.x = (n.x + 1) * 0.5; */
	 /* color.y = (n.y + 1) * 0.5; */
	 /* color.z = (n.z + 1) * 0.5; */
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
