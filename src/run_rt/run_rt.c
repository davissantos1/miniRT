/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_rt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:43:25 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/19 18:13:08 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ray.h"
#include "shapes.h"
#include "vec4.h"
#include <math.h>
#include <stdio.h>

static void	paint_pixel(t_minirt *ctx, t_ndc ndc);
static unsigned int	ray_color(t_scene *scene, t_ray ray);

void	print_material(t_material *m)
{
	(void)m;
	//	printf("===MATERIAL===\n color: %.1lf %.1lf %.1lf\n ks:  %.1lf %.1lf %.1lf\n ka:  %.1lf %.1lf %.1lf\n==============\n", m->color.x, m->color.y, m->color.z, m->spec_reflec.x, m->spec_reflec.y, m->spec_reflec.z, m->ambi_reflec.x, m->ambi_reflec.y, m->ambi_reflec.z);
}

void	print_cylinder(t_cylinder *obj)
{
	printf("cylinder pos: %.1lf %.1lf %.1lf  %.1lf height:%.1lf diameter: %1.lf  norm: %.1lf %.1lf %.1lf %.1lf\n", obj->pos.x, obj->pos.y, obj->pos.z, obj->pos.w, obj->height, obj->diam, obj->norm.x, obj->norm.y, obj->norm.z, obj->norm.w);
	print_material(&obj->material);
}

void	print_sphere(t_sphere *obj)
{
	printf("sphere pos: %.1lf %.1lf %.1lf %.1lf diam:%.1lf\n", obj->pos.x, obj->pos.y, obj->pos.z, obj->pos.w, obj->diam);
	print_material(&obj->material);
}

void	print_plane(t_plane *obj)
{
	obj->pos.y = -obj->pos.y;
	printf("plane pos: %.1lf %.1lf %.1lf %.1lf norm: %.1lf %.1lf %.1lf %.1lf\n", obj->pos.x, obj->pos.y, obj->pos.z, obj->pos.w, obj->norm.x, obj->norm.y, obj->norm.z, obj->norm.w);
	print_material(&obj->material);
}

void	print_camera(t_camera *obj)
{
	printf("camera pos: %.1lf %.1lf %.1lf %.1lf norm: %.1lf %.1lf %.1lf  %.1lf angle: %i\n", obj->pos.x, obj->pos.y, obj->pos.z, obj->pos.w, obj->norm.x, obj->norm.y, obj->norm.z, obj->norm.w, obj->fov);
}

void    run_rt(t_minirt *ctx)
{
    t_camera    *cam;
    t_ndc       ndc;
	int			i = 0;

	print_camera(ctx->scene->camera);
	t_list	*lst = ctx->scene->shape;
	while (lst)
	{
		if (((t_wildcard *)lst->content)->type == SPHERE)
			print_sphere(lst->content);
		else if (((t_wildcard *)lst->content)->type == PLANE)
			print_plane(lst->content);
		else
			print_cylinder(lst->content);
		i++;
		lst = lst->next;
	}
	printf("%i\n", i);
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
	fxaa(ctx->mlx);
	mlx_put_image_to_window(ctx->mlx->init, ctx->mlx->win, ctx->mlx->img, 0, 0);
}

static unsigned int	ray_color(t_scene *scene, t_ray ray)
{
	t_hit				hits;

	hits = ray_collision(scene, ray);
	if (!hits.num_roots)
		return (0xc9d2ff);
	hits.cam_dir = vec4_minus(scene->camera->pos, hits.hit_point);
	hits.cam_dir = vec4_unit_vector(hits.cam_dir);
	return (phong(hits, scene));
}
