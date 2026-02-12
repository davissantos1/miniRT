/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:49:25 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/12 15:49:27 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

void	print_vec(t_vec4 vec, char *name)
{
	printf("vec: %s x: %.0lf y: %.0lf z: %.0lf w: %.0lf\n", name, vec.x, vec.y, vec.z, vec.w);
}

static inline t_vec4	diffusion(t_hit hits, t_light *light, t_vec4 light_dir)
{
	double	dot;
	t_vec4	light_color;
	t_vec4	ret;

	dot = vec4_dot(hits.norm, light_dir);
	if (dot < 0)
		return ((t_color){0});
	light_color = vec4_scale(light->ratio, light_color);
	ret = vec4_times(light_color, hits.material.diff_reflec);
	return (vec4_scale(dot, ret));
}

static inline t_vec4	specular(t_hit hits, t_light *light, t_vec4 light_dir)
{
	t_color	intensity;
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
	return (vec4_times(vec4_scale(shinin, hits.material.spec_reflec), intensity));
}

unsigned int	phong(t_hit hits, t_scene *scene)
{
	t_light *light;
	t_color	color = (t_color){0};
	t_vec4	ambi_color;
	t_vec4	light_dir;

	light = scene->light;
	hits.cam_dir = vec4_minus(scene->camera->pos, hits.hit_point);
	hits.cam_dir = vec4_unit_vector(hits.cam_dir);
	ambi_color = vec4_scale(scene->alight->ratio, scene->alight->color);
	ambi_color = vec4_times(ambi_color, hits.material.ambi_reflec);
	while (light)
	{
		light_dir = vec4_minus(light->pos, hits.hit_point);
		light_dir = vec4_unit_vector(light_dir);
		color = vec4_plus(ambi_color, diffusion(hits, light, light_dir));
		color = vec4_plus(color, specular(hits, light, light_dir));
		light = NULL;
	}
	color.x = fmin(1.0, color.x);
	color.y = fmin(1.0, color.y);
	color.z = fmin(1.0, color.z);
	color = vec4_scale(255, color);
	return ((int)color.x << 16 | (int)color.y << 8 | (int)color.z);
}