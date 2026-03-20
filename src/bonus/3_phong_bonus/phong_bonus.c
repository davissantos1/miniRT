/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:49:25 by vitosant          #+#    #+#             */
/*   Updated: 2026/03/20 10:58:01 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "entities.h"
#include "shapes_bonus.h"
#include "settings.h"
#include "vec4.h"
#include <math.h>

static inline double	aces_film(const double x)
{
	static const double	a = 2.51;
	static const double	b = 0.03;
	static const double	c = 2.43;
	static const double	d = 0.59;
	static const double	e = 0.14;

	return (fmin(1.0, (x * (a * x + b)) / (x * (c * x + d) + e)));
}

static inline t_vec4	diffusion(t_hit hits, t_light *light, t_vec4 light_dir)
{
	double	angle;
	t_vec4	light_color;
	t_vec4	ret;

	angle = vec4_dot(hits.norm, light_dir);
	if (angle <= EPSILON)
		return ((t_color){0});
	light_color = vec4_scale(light->ratio, light->color);
	ret = vec4_times(light_color, hits.mat.color);
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
	shinin = pow(shinin, hits.mat.shininess);
	color_shine = vec4_scale(shinin, hits.mat.ks);
	return (vec4_times(color_shine, intensity));
}

static inline t_color	ambi_color(t_alight *alight, t_hit hits)
{
	double	angle;
	t_vec4	ambi_light;
	t_vec4	ret;

	angle = vec4_dot(hits.norm, hits.ambi_norm);
	if (angle <= EPSILON)
		return ((t_color){0});
	ambi_light = vec4_scale(alight->ratio, alight->color);
	ret = vec4_times(ambi_light, hits.mat.color);
	return (vec4_times(vec4_scale(angle, hits.mat.ka), ret));
}

t_color	phong(t_hit hits, t_scene *scene, int depth)
{
	t_light	*light;
	t_color	color;
	t_vec4	light_dir;

	light = scene->light;
	color = ambi_color(scene->alight, hits);
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
	if (vec4_squared_len(hits.mat.kr) > EPSILON)
		color = vec4_plus(color, reflections(scene, hits, depth));
	color.x = aces_film(color.x);
	color.y = aces_film(color.y);
	color.z = aces_film(color.z);
	return (color);
}
