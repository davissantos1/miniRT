/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_rt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:43:25 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/08 17:28:57 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx.h"
#include "ray.h"
#include "shapes.h"
#include "vec4.h"
#include <stdio.h>

static void	paint_pixel(t_minirt *ctx, t_vec4 delt_u, t_vec4 delt_v, t_vec4 ul);
static unsigned int	ray_color(t_scene *scene, t_list *lst, t_ray ray);

void	run_rt(t_minirt	*ctx)
{
	t_vec4	viewport_v;
	t_vec4	viewport_u;
	t_vec4	upper_left;
	t_vec4	delta_u;
	t_vec4	delta_v;

	viewport_u = vec4_init(2 * (double) WIDTH / HEIGHT, 0, 0, 0);
	viewport_v = vec4_init(0, -2.0, 0, 0);
	upper_left = vec4_scale(0.5, vec4_plus(viewport_u, viewport_v));
	upper_left = vec4_scale(-1, vec4_plus(vec4_init(0, 0, 1, 0), upper_left));
	delta_u = vec4_scale(1.0 / WIDTH, viewport_u);
	delta_v = vec4_scale(1.0 / HEIGHT, viewport_v);
	paint_pixel(ctx, delta_u, delta_v, upper_left);
}

static void	paint_pixel(t_minirt *ctx, t_vec4 delt_u, t_vec4 delt_v, t_vec4 ul)
{
	t_ray			ray;
	t_vec4			pixel00;
	t_vec4			pixel_center;
	int				y;
	int				x;

	y = 0;
	pixel00 = vec4_scale(0.5, vec4_plus(delt_u, delt_v));
	pixel00 = vec4_plus(pixel00, ul);
	ray.origin = ctx->scene->camera->pos;
	ray.dir = pixel00;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_center = vec4_plus(pixel00, vec4_scale(x, delt_u));
			pixel_center = vec4_plus(pixel_center, vec4_scale(y, delt_v));
			ray.dir = vec4_minus(pixel_center, ctx->scene->camera->pos);
			img_pixel_put(ctx->mlx, x, y, ray_color(ctx->scene, ctx->scene->shape, ray));
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
}

static unsigned int	ray_color(t_scene *scene, t_list *lst, t_ray ray)
{
	static t_get_hit	functions[SHAPE_COUNT];
	t_hit				hits;

	hits.num_roots = 0;
	if (!functions[SPHERE])
		fill_functions(functions);
	while (lst && !hits.num_roots)
	{
		if (functions[get_type(lst->content)](scene, lst->content, &hits, ray))
			return (hits.color);
		lst = lst->next;
	}
	return (0xc9d2ff);
}

int	main(void)
{
	t_minirt	ctx;
	t_sphere	*sphere;

	ctx.gc = gc_init();
	ctx.mlx = mlx_start(ctx.gc, "TESTE");
	ctx.scene = gc_calloc(sizeof(t_scene), ctx.gc, GC_CUSTOM1);
	ctx.scene->camera = gc_calloc(sizeof(t_camera), ctx.gc, GC_CUSTOM1);
	ctx.scene->camera->pos = vec4_init(0, 0, 0, 1);
	sphere = gc_calloc(sizeof(t_sphere), ctx.gc, GC_CUSTOM1);
	sphere->diam = 1.0;
	sphere->color = vec4_init(255, 0, 84, 0);
	sphere->color = vec4_unit_vector(sphere->color);
	sphere->pos = vec4_init(0,0, -1, 1);
	ctx.scene->shape = ft_lstnew(sphere);
	run_rt(&ctx);
	mlx_loop(ctx.mlx->init);
	gc_free_all(ctx.gc);
	mlx_destroy_window(ctx.mlx->init, ctx.mlx->win);
	mlx_destroy_display(ctx.mlx->init);
	free(ctx.mlx->init);
	return (0);
}
