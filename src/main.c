/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:13:55 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/13 16:03:55 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_minirt meu_teste(void);

int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	// t_minirt	*rt;
	// int			fd;

	// if (ac != 2)
	// 	return (panic(ERR_ARG_NUM));
	// else
	// {
	// 	if (!check_filename(av[1]))
	// 		return (panic(ERR_ARG_INVALID));
	// 	fd = open(av[1], O_RDONLY);
	// 	if (fd < 0)
	// 		return (panic(ERR_SYSCALL));
	// 	rt = start_minirt(av[1]);
	// 	parse_minirt(rt, fd);
	// 	run_rt(&ctx);
	// 	if (close(fd) == -1)
	// 		desperation(rt->gc, ERR_SYSCALL);
	// }
	// mlx_destroy_image(rt->mlx->init, rt->mlx->img);
	// mlx_destroy_window(rt->mlx->init, rt->mlx->win);
	// mlx_destroy_display(rt->mlx->init);
	// free(rt->mlx->init);
	// gc_free_all(rt->gc);
	t_minirt	ctx = meu_teste();
	run_rt(&ctx);
	return (SUCCESS);
}

t_minirt meu_teste(void)
{
	t_minirt	ctx;
	t_plane		*plane;
	t_sphere	*sphere;
	t_cylinder	*cylinder;
	t_circle	*circle;

	(void)plane;
	(void)sphere;
	(void)cylinder;
	(void)circle;
	ctx.gc = gc_init();
	ctx.mlx = start_mlx(ctx.gc, "TESTE");
	ctx.scene = gc_calloc(sizeof(t_scene), ctx.gc, GC_CUSTOM1);
	ctx.scene->camera = gc_calloc(sizeof(t_camera), ctx.gc, GC_CUSTOM1);
	ctx.scene->camera->pos = vec4_init(0, 0, 0, 1);
	ctx.scene->camera->fov = 90;
	ctx.scene->camera->norm = vec4_init(0, 0, -1, 1);
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
	sphere->pos = vec4_init(1, 0, -1, 1);
	sphere->material.ambi_reflec = vec4_init(0.3, 0, 0, 0);
	sphere->material.color = vec4_init(1, 0, 0, 0);
	sphere->material.spec_reflec = vec4_init(1, 1, 1, 0);
	sphere->material.shininess = 32;
	ft_lstadd_back(&ctx.scene->shape, ft_lstnew(sphere));
	plane = gc_calloc(sizeof(t_plane), ctx.gc, GC_CUSTOM1);
	plane->type = PLANE;
	plane->pos = vec4_init(0, -1, 0, 1);
	plane->norm = vec4_init(0, 1, 0, 0);
	plane->material.color = vec4_init(0, 0, 1, 0);
	plane->material.shininess = 42;
	plane->material.spec_reflec = vec4_init(1, 1, 1, 0);
	plane->material.ambi_reflec = vec4_init(0, 0, 0.5, 0);
	ft_lstadd_back(&ctx.scene->shape, ft_lstnew(plane));
	sphere = gc_calloc(sizeof(t_sphere), ctx.gc, GC_CUSTOM1);
	sphere->type = SPHERE;
	sphere->diam = 0.5;
	sphere->pos = vec4_init(0, 0, -2, 1);
	sphere->material.shininess = 42;
	sphere->material.color = vec4_init(1, 0, 1, 0);
	sphere->material.spec_reflec = vec4_init(1, 1, 1, 0);
	sphere->material.ambi_reflec = vec4_init(0.3, 0, 0.3, 0);
	ft_lstadd_back(&ctx.scene->shape, ft_lstnew(sphere));
	cylinder = gc_calloc(sizeof(t_cylinder), ctx.gc, GC_CUSTOM1);
	cylinder->diam = 0.1;
	cylinder->type = CYLINDER;
	cylinder->height = 1.5;
	cylinder->pos = vec4_init(0, 0, -1.0, 1);
	cylinder->norm = vec4_unit_vector(vec4_init(1, 1, 0, 0));
	cylinder->material.color = vec4_init(0, 0, 1, 0);
	cylinder->material.shininess = 42;
	cylinder->material.spec_reflec = vec4_init(1, 1, 1, 0);
	cylinder->material.ambi_reflec = vec4_init(0, 0, 0.3, 0);
	ft_lstadd_back(&ctx.scene->shape, ft_lstnew(cylinder));
	circle = gc_calloc(sizeof(t_circle), ctx.gc, GC_CUSTOM1);
	circle->diam = 1;
	circle->type = CIRCLE;
	circle->pos = vec4_init(0, 0, -3, 1);
	circle->material.shininess = 80;
	circle->material.color = vec4_init(0, 1, 0.45, 0);
	circle->material.spec_reflec = vec4_init(1, 1, 1, 0);
	circle->material.ambi_reflec = vec4_init(0, 0.3, 0.15, 0);
	circle->norm = vec4_unit_vector(vec4_minus(ctx.scene->camera->pos, circle->pos));
	ft_lstadd_back(&ctx.scene->shape, ft_lstnew(circle));
	return (ctx);
}
