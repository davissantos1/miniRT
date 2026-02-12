/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_rt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:43:25 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/10 11:01:06 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "mlx.h"
#include "ray.h"
#include "shapes.h"
#include "vec4.h"

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
			ray.dir.w = 0;
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
	functions[CYLINDER] = hit_cylinder;
	functions[CIRCLE] = hit_circle;
}

static unsigned int	ray_color(t_scene *scene, t_list *lst, t_ray ray)
{
	static t_get_hit	functions[SHAPE_COUNT];
	t_hit				hits;

	hits.num_roots = 0;
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

//Para compilar o teste
//cc -g -O3 -march=native -ffast-math -I./includes -I./minilibx-linux src/matrix/*.c src/run_rt/*.c src/utils/*.c src/vec4/*.c src/shapes_collision/*.c -lm -L./libft -lft -L./minilibx-linux -lmlx_Linux -lmlx -lXext -lX11 -lm -lz
int	main(void)
{
	t_minirt	ctx;
	t_sphere	*sphere;
	t_cylinder	*cylinder;
	t_circle	*circle;

	ctx.gc = gc_init();
	ctx.mlx = mlx_start(ctx.gc, "TESTE");
	ctx.scene = gc_calloc(sizeof(t_scene), ctx.gc, GC_CUSTOM1);
	ctx.scene->camera = gc_calloc(sizeof(t_camera), ctx.gc, GC_CUSTOM1);
	ctx.scene->camera->pos = vec4_init(0, 0, 0, 1);
	ctx.scene->light = gc_calloc(sizeof(t_light), ctx.gc, GC_CUSTOM1);
	ctx.scene->light->color = vec4_init(1, 1, 1, 0);
	ctx.scene->light->pos = vec4_init(0, 1, 0, 1);
	ctx.scene->light->ratio = 1;
	ctx.scene->alight = gc_calloc(sizeof(t_alight), ctx.gc, GC_CUSTOM1);
	ctx.scene->alight->ratio = 1;
	ctx.scene->alight->color = vec4_init(1, 1, 1, 0);
	sphere = gc_calloc(sizeof(t_sphere), ctx.gc, GC_CUSTOM1);
	sphere->type = SPHERE;
	sphere->diam = 1;
	sphere->pos = vec4_init(0, 0, -1, 1);
	sphere->material.ambi_reflec = vec4_init(0.3, 0, 0, 0);
	sphere->material.diff_reflec = vec4_init(1, 0, 0, 0);
	sphere->material.spec_reflec = vec4_init(0.5, 0.5, 0.5, 0);
	sphere->material.shininess = 20;
	ft_lstadd_back(&ctx.scene->shape, ft_lstnew(sphere));
	/*
	sphere = gc_calloc(sizeof(t_sphere), ctx.gc, GC_CUSTOM1);
	sphere->type = SPHERE;
	sphere->diam = 0.5;
	sphere->material.diff_reflec = vec4_init(1, 0, 1, 0);
	sphere->pos = vec4_init(0, 0, -2, 1);
	sphere->material.shininess = 80;
	sphere->material.spec_reflec = vec4_init(1, 1, 1, 0);
	ft_lstadd_back(&ctx.scene->shape, ft_lstnew(sphere));
	cylinder = gc_calloc(sizeof(t_cylinder), ctx.gc, GC_CUSTOM1);
	cylinder->diam = 0.1;
	cylinder->type = CYLINDER;
	cylinder->height = 1.5;
	cylinder->pos = vec4_init(0, 0, -1.5, 1);
	cylinder->norm = vec4_unit_vector(vec4_init(1, 1, 0, 0));
	cylinder->material.diff_reflec = vec4_init(0, 0, 1, 0);
	cylinder->material.shininess = 80;
	cylinder->material.spec_reflec = vec4_init(1, 1, 1, 0);
	ft_lstadd_back(&ctx.scene->shape, ft_lstnew(cylinder));
	circle = gc_calloc(sizeof(t_circle), ctx.gc, GC_CUSTOM1);
	circle->diam = 1;
	circle->type = CIRCLE;
	circle->pos = vec4_init(0, 0, -3, 1);
	circle->material.shininess = 80;
	circle->material.diff_reflec = vec4_init(0, 1, 0.45, 0);
	circle->material.spec_reflec = vec4_init(1, 1, 1, 0);
	circle->norm = vec4_unit_vector(vec4_minus(ctx.scene->camera->pos, cylinder->pos));
	ft_lstadd_back(&ctx.scene->shape, ft_lstnew(circle));
	*/
	run_rt(&ctx);
	mlx_loop(ctx.mlx->init);
	gc_free_all(ctx.gc);
	mlx_destroy_window(ctx.mlx->init, ctx.mlx->win);
	mlx_destroy_display(ctx.mlx->init);
	free(ctx.mlx->init);
	return (0);
}
