/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_routine_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:28:53 by vitosant          #+#    #+#             */
/*   Updated: 2026/03/20 09:03:30 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "threads_bonus.h"
#include "shapes_bonus.h"
#include "settings.h"
#include "ray.h"
#include "minirt.h"

static t_vec4	get_ray_dir(t_ndc ndc, int x, int y)
{
	t_vec4	temp_u;
	t_vec4	temp_v;
	double	px;
	double	py;

	px = (2.0 * ((double)x + 0.5) / WIDTH - 1.0) * ndc.scale * ndc.ratio;
	py = (1.0 - 2.0 * ((double)y + 0.5) / HEIGHT) * ndc.scale;
	temp_u = vec4_scale(px, ndc.u);
	temp_v = vec4_scale(py, ndc.v);
	return (vec4_minus(vec4_plus(temp_u, temp_v), ndc.w));
}

static unsigned int	ray_color(t_scene *scene, t_ray ray)
{
	t_hit	hits;
	t_color	color;

	hits = ray_collision(scene, ray);
	if (!hits.num_roots)
		return (0);
	hits.cam_dir = vec4_minus(scene->camera->pos, hits.hit_point);
	hits.cam_dir = vec4_unit_vector(hits.cam_dir);
	color = phong(hits, scene, 4);
	color = vec4_scale(255.0, color);
	return ((int)color.x << 16 | (int)color.y << 8 | (int)color.z);
}

static void	paint_pixel(t_thread *info)
{
	int		x;
	int		y;
	t_ray	ray;
	int		px;

	y = 0;
	px = info->num * info->px_count;
	ray.origin = info->ctx->scene->camera->pos;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < info->px_count + info->px_extra)
		{
			ray.dir = vec4_unit_vector(get_ray_dir(info->ndc, x + px, y));
			img_pixel_put(info->ctx->mlx, x + px, y,
				ray_color(info->ctx->scene, ray));
			x++;
		}
		y++;
	}
}

void	*routine(void *info)
{
	t_thread	*me;

	me = info;
	paint_pixel(me);
	return (NULL);
}
