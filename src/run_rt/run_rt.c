/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_rt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:43:25 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/18 21:25:53 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "ray.h"
#include "shapes.h"
#include "vec4.h"
#include <math.h>
#include <stdio.h>

#define PI 3.14159265359

static void	paint_pixel(t_minirt *ctx, t_ndc ndc);
static unsigned int	ray_color(t_scene *scene, t_ray ray);

void    run_rt(t_minirt *ctx)
{
    t_camera    *cam;
    t_ndc       ndc;

    cam = ctx->scene->camera;
    ndc.ratio = (double)WIDTH / (double)HEIGHT;
    ndc.scale = tanh(cam->fov * 0.5 * (PI / 180.0));
    ndc.w = vec4_scale(-1, cam->norm);
    ndc.u = vec4_unit_vector(vec4_cross(vec4_init(0, 1, 0, 0), ndc.w));
    ndc.v = vec4_unit_vector(vec4_cross(ndc.w, ndc.u));
    paint_pixel(ctx, ndc);
    mlx_loop(ctx->mlx->init);
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
	t_color color;

	hits = ray_collision(scene, ray);
	if (!hits.num_roots)
		return (0);
	hits.cam_dir = vec4_minus(scene->camera->pos, hits.hit_point);
	hits.cam_dir = vec4_unit_vector(hits.cam_dir);
	color = phong(hits, scene, 4);
	color = vec4_scale(255.0, color);
	return ((int)color.x << 16 | (int)color.y << 8 | (int)color.z);
}

