/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_rt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:43:25 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/14 12:40:14 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx.h"
#include "ray.h"
#include "shapes.h"
#include "vec4.h"
#include <math.h>

#define PI 3.14159265359

static void	paint_pixel(t_minirt *ctx, t_ndc ndc);
static unsigned int	ray_color(t_scene *scene, t_ray ray);

void	run_rt(t_minirt	*ctx)
{
	t_camera	*cam;
	t_ndc		ndc;

	cam = ctx->scene->camera;
	ndc.ratio = (double)WIDTH / (double)HEIGHT;
	ndc.scale = tanh(cam->fov * 0.5 * (PI / 180.0));
	ndc.w = vec4_scale(-1, cam->norm);
	ndc.u = vec4_unit_vector(vec4_cross(vec4_init(0, 1, 0, 0), ndc.w));
	ndc.v = vec4_unit_vector(vec4_cross(ndc.w, ndc.u));
	paint_pixel(ctx, ndc);
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
			ray.dir = get_ray_dir(ndc, x, y);
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
		functions[get_type(lst->content)](scene, lst->content, &hits, ray);
		lst = lst->next;
	}
	if (hits.num_roots)
		return (phong(hits, scene));
	return (0xc9d2ff);
}
/*
//Para compilar o teste
//cc -g -O3 -march=native -ffast-math -I./includes -I./minilibx-linux src/matrix/*.c src/run_rt/*.c src/utils/*.c src/vec4/*.c src/shapes_collision/*.c -lm -L./libft -lft -L./minilibx-linux -lmlx_Linux -lmlx -lXext -lX11 -lm -lz
int	main(void)
{
	t_minirt	ctx;
	t_plane		*plane;
	t_sphere	*sphere;
	t_cylinder	*cylinder;
	t_circle	*circle;

	ctx.gc = gc_init();
	ctx.mlx = mlx_start(ctx.gc, "TESTE");
	ctx.scene = gc_calloc(sizeof(t_scene), ctx.gc, GC_CUSTOM1);
	ctx.scene->camera = gc_calloc(sizeof(t_camera), ctx.gc, GC_CUSTOM1);
	ctx.scene->camera->pos = vec4_init(0, 0, -1, 1);
	ctx.scene->camera->fov = 90;
	ctx.scene->camera->norm = vec4_init(0, 0, -1, 0);
	ctx.scene->light = gc_calloc(sizeof(t_light), ctx.gc, GC_CUSTOM1);
	ctx.scene->light->color = vec4_init(1, 1, 1, 0);
	ctx.scene->light->pos = vec4_init(0, 0, 0, 1);
	ctx.scene->light->ratio = 1;
	ctx.scene->light->next= gc_calloc(sizeof(t_light), ctx.gc, GC_CUSTOM1);
	ctx.scene->light->next->color = vec4_init(1, 1, 1, 0);
	ctx.scene->light->next->pos = vec4_init(0, 1, 0, 1);
	ctx.scene->light->next->ratio = 1;
	ctx.scene->alight = gc_calloc(sizeof(t_alight), ctx.gc, GC_CUSTOM1);
	ctx.scene->alight->ratio = 1;
	ctx.scene->alight->color = vec4_init(1, 1, 1, 0);
	sphere = gc_calloc(sizeof(t_sphere), ctx.gc, GC_CUSTOM1);
	sphere->type = SPHERE;
	sphere->diam = 1;
	sphere->pos = vec4_init(1, 0, -2, 1);
	sphere->material.ambi_reflec = vec4_init(0.3, 0, 0, 0);
	sphere->material.diff_reflec = vec4_init(1, 0, 0, 0);
	sphere->material.spec_reflec = vec4_init(1, 1, 1, 0);
	sphere->material.shininess = 32;
	ft_lstadd_back(&ctx.scene->shape, ft_lstnew(sphere));
	plane = gc_calloc(sizeof(t_plane), ctx.gc, GC_CUSTOM1);
	plane->type = PLANE;
	plane->pos = vec4_init(0, -1, 0, 1);
	plane->norm = vec4_init(0, 1, 0, 0);
	plane->material.diff_reflec = vec4_init(0, 0, 1, 0);
	plane->material.shininess = 42;
	plane->material.spec_reflec = vec4_init(1, 1, 1, 0);
	plane->material.ambi_reflec = vec4_init(0, 0, 0.5, 0);
	//ft_lstadd_back(&ctx.scene->shape, ft_lstnew(plane));
	// sphere = gc_calloc(sizeof(t_sphere), ctx.gc, GC_CUSTOM1);
	// sphere->type = SPHERE;
	// sphere->diam = 0.5;
	// sphere->pos = vec4_init(0, 0, -2, 1);
	// sphere->material.shininess = 42;
	// sphere->material.diff_reflec = vec4_init(1, 0, 1, 0);
	// sphere->material.spec_reflec = vec4_init(1, 1, 1, 0);
	// sphere->material.ambi_reflec = vec4_init(0.3, 0, 0.3, 0);
	// ft_lstadd_back(&ctx.scene->shape, ft_lstnew(sphere));
	// cylinder = gc_calloc(sizeof(t_cylinder), ctx.gc, GC_CUSTOM1);
	// cylinder->diam = 0.1;
	// cylinder->type = CYLINDER;
	// cylinder->height = 1.5;
	// cylinder->pos = vec4_init(0, 0, -1.0, 1);
	// cylinder->norm = vec4_unit_vector(vec4_init(1, 1, 0, 0));
	// cylinder->material.diff_reflec = vec4_init(0, 0, 1, 0);
	// cylinder->material.shininess = 42;
	// cylinder->material.spec_reflec = vec4_init(1, 1, 1, 0);
	// cylinder->material.ambi_reflec = vec4_init(0, 0, 0.3, 0);
	// ft_lstadd_back(&ctx.scene->shape, ft_lstnew(cylinder));
	// circle = gc_calloc(sizeof(t_circle), ctx.gc, GC_CUSTOM1);
	// circle->diam = 1;
	// circle->type = CIRCLE;
	// circle->pos = vec4_init(0, 0, -3, 1);
	// circle->material.shininess = 80;
	// circle->material.diff_reflec = vec4_init(0, 1, 0.45, 0);
	// circle->material.spec_reflec = vec4_init(1, 1, 1, 0);
	// circle->material.ambi_reflec = vec4_init(0, 0.3, 0.15, 0);
	// circle->norm = vec4_unit_vector(vec4_minus(ctx.scene->camera->pos, circle->pos));
	// ft_lstadd_back(&ctx.scene->shape, ft_lstnew(circle));
	run_rt(&ctx);
	mlx_loop(ctx.mlx->init);
	gc_free_all(ctx.gc);
	mlx_destroy_window(ctx.mlx->init, ctx.mlx->win);
	mlx_destroy_display(ctx.mlx->init);
	free(ctx.mlx->init);
	return (0);
}
*/
