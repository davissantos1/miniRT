/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_rt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:43:25 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/14 13:29:10 by vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "ray.h"
#include "shapes.h"
#include "vec4.h"
#include <math.h>

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

inline static t_shape	get_type(t_wildcard *me)
{
	return (me->type);
}

static void	fill_functions(t_get_hit *functions)
{
	functions[SPHERE] = hit_sphere;
	functions[CYLINDER] = hit_cylinder;
	functions[CIRCLE] = hit_circle;
	functions[PLANE] = hit_plane;
}

static unsigned int	ray_color(t_scene *scene, t_ray ray)
{
	static t_get_hit	functions[SHAPE_COUNT];
	t_hit				hits;
	t_list				*lst;

	hits.num_roots = 0;
	lst = scene->shape;
	if (!functions[SPHERE])
		fill_functions(functions);
	while (lst)
	{
		functions[get_type(lst->content)](lst->content, &hits, ray);
		lst = lst->next;
	}
	if (hits.num_roots)
		return (phong(hits, scene));
	return (0xc9d2ff);
}

