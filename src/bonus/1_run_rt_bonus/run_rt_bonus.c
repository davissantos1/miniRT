/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_rt_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:43:25 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/25 14:41:24 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ray.h"
#include "vec4.h"
#include "shapes_bonus.h"
#include "pattern_bonus.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>

static void	paint_pixel(t_minirt *ctx, t_ndc ndc);
static unsigned int	ray_color(t_scene *scene, t_ray ray);

void    run_rt(t_minirt *ctx)
{
    t_camera    *cam;
    t_ndc       ndc;

    cam = ctx->scene->camera;
    ndc.ratio = get_settings()->aspect_ratio;
    ndc.scale = tan(cam->fov * 0.5 * (PI / 180.0));
    ndc.w = vec4_scale(-1, cam->norm);
    ndc.u = vec4_unit_vector(vec4_cross(vec4_init(0, 1, 0, 0), ndc.w));
    ndc.v = vec4_unit_vector(vec4_cross(ndc.w, ndc.u));
    paint_pixel(ctx, ndc);
}


static t_vec4  get_ray_dir(t_ndc ndc, int x, int y)
{
    t_vec4  temp_u;
    t_vec4  temp_v;
    double  px;
    double  py;

    px = (2.0 * ((double)x + 0.5) / WIDTH - 1.0) * ndc.scale * ndc.ratio;
    py = (1.0 - 2.0 * ((double)y + 0.5) / HEIGHT) * ndc.scale;
    temp_u = vec4_scale(px, ndc.u);
    temp_v = vec4_scale(py, ndc.v);
    return(vec4_minus(vec4_plus(temp_u, temp_v), ndc.w));
}


static void	paint_pixel(t_minirt *ctx, t_ndc ndc)
{
	int		x;
	int		y;
	t_ray	ray;

	y = 0;
	ray.origin = ctx->scene->camera->pos;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray.dir = vec4_unit_vector(get_ray_dir(ndc, x, y));
			img_pixel_put(ctx->mlx, x, y, ray_color(ctx->scene, ray));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(ctx->mlx->init, ctx->mlx->win, ctx->mlx->img, 0, 0);
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
	if (hits.mat.pattern != NO_PATTERN)
	{
		hits.mat.color = get_pattern(hits, hits.mat.pattern);
		if (!vec4_is_diff(hits.mat.color, hits.mat.color2))
		{
			hits.mat.ka = hits.mat.ka2;
			hits.mat.ks = hits.mat.ks2;
			hits.mat.kr = hits.mat.kr2;
		}
	}
	color = phong(hits, scene, 4);
	color = vec4_scale(255.0, color);
	return ((int)color.x << 16 | (int)color.y << 8 | (int)color.z);
}
