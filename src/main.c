/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:13:55 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/01 09:19:46 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "parsing_bonus.h"
#include "minirt.h"
#include "shapes_bonus.h"
#include "structs.h"
#include "texture_bonus.h"
#include "vec4.h"
#include "mlx.h"

t_minirt meu_teste(void);

int	main(int ac, char **av)
{
	/* t_minirt	*rt; */
	/* int			fd; */

	/* if (ac != 2) */
	/* 	return (panic(ERR_ARG_NUM)); */
	/* else */
	/* { */
	/* 	if (!check_filename(av[1])) */
	/* 		return (panic(ERR_ARG_INVALID)); */
	/* 	fd = open(av[1], O_RDONLY); */
	/* 	if (fd < 0) */
	/* 		return (panic(ERR_SYSCALL)); */
	/* 	rt = start_minirt(get_name(av[1])); */
	/* 	parse_minirt(rt, fd); */
	/* 	if (!gc_addlst(rt->scene->shape, rt->gc, GC_DEFAULT)) */
	/* 		desperation(rt, ERR_SYSCALL); */
	/* 	run_rt(rt); */
	/* 	if (close(fd) == -1) */
	/* 		desperation(rt, ERR_SYSCALL); */
	/* } */
	/* mlx_loop(rt->mlx->init); */
	 (void) ac;
	 (void) av;
	 t_minirt teste = meu_teste();
	 run_rt(&teste);
	 mlx_loop(teste.mlx->init);
	return (SUCCESS);
}

t_minirt meu_teste(void)
{
	t_minirt	ctx;
	t_plane		*plane;
	t_sphere	*sphere;
	t_cylinder	*cylinder;
	t_disk		*circle;
	t_cone		*cone;

	(void)plane;
	(void)sphere;
	(void)cylinder;
	(void)circle;
 	(void)cone;
	ctx.gc = gc_init();
	ctx.mlx = start_mlx(ctx.gc, "TESTE");
	ctx.scene = gc_calloc(sizeof(t_scene), ctx.gc, GC_CUSTOM1);
	ctx.scene->camera = gc_calloc(sizeof(t_camera), ctx.gc, GC_CUSTOM1);
	ctx.scene->camera->pos = vec4_init(0, 0, 0, 1);
	ctx.scene->camera->fov = 90;
	ctx.scene->camera->norm = vec4_unit_vector(vec4_init(0, 0, -1, 0));
	ctx.scene->light = gc_calloc(sizeof(t_light), ctx.gc, GC_CUSTOM1);
	ctx.scene->light->color = vec4_init(1, 1, 1, 0);
	ctx.scene->light->pos = vec4_init(0, 1, 0, 1);
	ctx.scene->light->ratio = 1;
	//ctx.scene->light->next= gc_calloc(sizeof(t_light), ctx.gc, GC_CUSTOM1);
	//ctx.scene->light->next->color = vec4_init(1, 1, 1, 0);
	//ctx.scene->light->next->pos = vec4_init(0, 1, 0, 1);
	//ctx.scene->light->next->ratio = 1;
	ctx.scene->alight = gc_calloc(sizeof(t_alight), ctx.gc, GC_CUSTOM1);
	ctx.scene->alight->ratio = 1;
	ctx.scene->alight->color = vec4_init(1, 1, 1, 0);
	sphere = gc_calloc(sizeof(t_sphere), ctx.gc, GC_CUSTOM1);
	sphere->type = SPHERE;
	sphere->diam = 1;
	sphere->pos = vec4_init(0, 0, -1, 1);
	sphere->mat.color = vec4_init(1, 0, 0, 0);
	sphere->mat.ka = vec4_init(0.3, 0, 0, 0);
	sphere->mat.ks = vec4_init(1, 1, 1, 0);
	sphere->mat.kr = vec4_init(0.2, 0.2, 0.2, 0);
	sphere->mat.shininess = 32;
	sphere->mat.color2 = vec4_init(0, 1, 1, 0);
	sphere->mat.ka2 = vec4_init(0, 0.3, 0.3, 0);
	sphere->mat.ks2 = vec4_init(1, 1, 1, 0);
	sphere->mat.kr2 = vec4_init(0.2, 0.2, 0.2, 0);
	sphere->mat.pattern = CHECKER;
	sphere->mat.pattern_const = 2;
	sphere->mat.texture = load_img(&ctx, "./normal_map/earth.xpm");
	sphere->mat.map_type = NORMAL_MAP;
	sphere->transform = sphere_transform(sphere, &sphere->inverse);
	ft_lstadd_back(&ctx.scene->shape, ft_lstnew(sphere));
	/* plane = gc_calloc(sizeof(t_plane), ctx.gc, GC_CUSTOM1); */
	/* plane->type = PLANE; */
	/* plane->pos = vec4_init(0, -1, 0, 1); */
	/* plane->norm = vec4_init(0, 1, 0, 0); */
	/* plane->mat.shininess = 42; */
	/* plane->mat.pattern_const = 1; */
	/* plane->mat.color = vec4_init(0.5, 0, 0.5, 0); */
	/* plane->mat.ks = vec4_init(0, 0, 0, 0); */
	/* plane->mat.ka = vec4_init(0.4, 0, 0.4, 0); */
	/* plane->mat.kr = vec4_init(0, 0, 0, 0); */
	/* plane->mat.color2 = vec4_init(0.5, 1, 0.5, 0); */
	/* plane->mat.ks2 = vec4_init(0, 0, 0, 0); */
	/* plane->mat.ka2 = vec4_init(0.4, 0.8, 0.4, 0); */
	/* plane->mat.kr2 = vec4_init(0, 0, 0, 0); */
	/* plane->mat.pattern = CHECKER; */
	/* plane->transform = plane_transform(plane, &plane->inverse); */
	/* ft_lstadd_back(&ctx.scene->shape, ft_lstnew(plane)); */
	cone = gc_calloc(sizeof(t_cone), ctx.gc, GC_CUSTOM1);
	cone->type = CONE;
	cone->pos = vec4_init(1, 0, -1, 1);
	cone->norm = vec4_init(0, 0, -1, 0);
	cone->diam = 0.4;
	cone->height = 0.4;
	cone->mat.shininess = 32;
	cone->mat.pattern_const = 2;
	cone->mat.color = vec4_init(0.8, 0, 0.5, 0);
	cone->mat.ks = vec4_init(1, 1, 1, 0);
	cone->mat.ka = vec4_init(0.4, 0, 0.4, 0);
	cone->mat.kr = vec4_init(0, 0, 0, 0);
	cone->mat.color2 = vec4_init(0.5, 1, 0.5, 0);
	cone->mat.ks2 = vec4_init(0.2, 0.2, 0.2, 0);
	cone->mat.ka2 = vec4_init(0.4, 0.8, 0.4, 0);
	cone->mat.kr2 = vec4_init(0, 0, 0, 0);
	cone->mat.pattern = RING;
	cone->transform = cone_transform(cone, &cone->inverse);
	//	ft_lstadd_back(&ctx.scene->shape, ft_lstnew(cone));


/* 	cone = gc_calloc(sizeof(t_cone), ctx.gc, GC_CUSTOM1); */
/* 	cone->type = CONE; */
/* 	cone->pos = vec4_init(-1, 0, -1, 1); */
/* 	cone->norm = vec4_init(0, 1, 0, 0); */
/* 	cone->diam = 0.4; */
/* 	cone->height = 0.4; */
/* 	cone->mat.shininess = 32; */
/* 	cone->mat.pattern_const = 2; */
/* 	cone->mat.color = vec4_init(0.8, 0, 0.5, 0); */
/* 	cone->mat.ks = vec4_init(1, 1, 1, 0); */
/* 	cone->mat.ka = vec4_init(0.4, 0, 0.4, 0); */
/* 	cone->mat.kr = vec4_init(0, 0, 0, 0); */
/* 	cone->mat.color2 = vec4_init(0.5, 1, 0.5, 0); */
/* 	cone->mat.ks2 = vec4_init(0.2, 0.2, 0.2, 0); */
/* 	cone->mat.ka2 = vec4_init(0.4, 0.8, 0.4, 0); */
/* 	cone->mat.kr2 = vec4_init(0, 0, 0, 0); */
/* 	cone->mat.pattern = RING; */
/* 	cone->transform = cone_transform(cone, &cone->inverse); */
/* 	ft_lstadd_back(&ctx.scene->shape, ft_lstnew(cone)); */
/* 	/\* sphere = gc_calloc(sizeof(t_sphere), ctx.gc, GC_CUSTOM1); *\/ */
/* 	/\* sphere->type = SPHERE; *\/ */
/* 	/\* sphere->diam = 0.7; *\/ */
/* 	/\* sphere->pos = vec4_init(-0.6, 0, -1, 1); *\/ */
/* 	/\* sphere->mat.shininess = 42; *\/ */
/* 	/\* sphere->mat.color = vec4_init(0, 0, 1, 0); *\/ */
/* 	/\* sphere->mat.ks = vec4_init(1, 1, 1, 0); *\/ */
/* 	/\* sphere->mat.ka = vec4_init(0, 0, 0.3, 0); *\/ */
/* 	/\* sphere->mat.kr = vec4_init(0.3, 0.3, 0.3, 0); *\/ */
/* 	/\* sphere->mat.pattern = GRADIENT; *\/ */
/* 	/\* ft_lstadd_back(&ctx.scene->shape, ft_lstnew(sphere)); *\/ */
/* 	/\* circle = gc_calloc(sizeof(t_circle), ctx.gc, GC_CUSTOM1); *\/ */
/* 	/\* circle->diam = 1; *\/ */
/* 	/\* circle->type = CIRCLE; *\/ */
/* 	/\* circle->pos = vec4_init(0, 0, -3, 1); *\/ */
/* 	/\* circle->mat.shininess = 80; *\/ */
/* 	/\* circle->mat.color = vec4_init(0, 1, 0.45, 0); *\/ */
/* 	/\* circle->mat.ks = vec4_init(1, 1, 1, 0); *\/ */
/* 	/\* circle->mat.ka = vec4_init(0, 0.3, 0.15, 0); *\/ */
/* 	/\* circle->norm = vec4_unit_vector(vec4_minus(ctx.scene->camera->pos, circle->pos)); *\/ */
/* 	/\* ft_lstadd_back(&ctx.scene->shape, ft_lstnew(circle)); *\/ */
/* 	cylinder = gc_calloc(sizeof(t_cylinder), ctx.gc, GC_CUSTOM1); */
/* 	cylinder->type = CYLINDER;  */
/* 	cylinder->diam = 0.4;  */
/* 	cylinder->height = 2; */
/* 	cylinder->pos = vec4_init(2, 0, -3, 1);  */
/* 	cylinder->norm = vec4_unit_vector(vec4_init(1, 1, 0, 0));  */
/* 	cylinder->mat.shininess = 42;  */
/* 	cylinder->mat.color = vec4_init(0, 0, 0.9, 0); */
/* 	cylinder->mat.ks = vec4_init(1, 1, 1, 0); */
/* 	cylinder->mat.ka = vec4_init(0, 0, 0.4, 0); */
/* 	cylinder->mat.kr = vec4_init(0, 0, 0, 0); */
/* 	cylinder->mat.color2 = vec4_init(1, 1, 0.1, 0);  */
/* 	cylinder->mat.ks2 = vec4_init(1, 1, 1, 0);   */
/* 	cylinder->mat.ka2 = vec4_init(0.4, 0.4, 0.04, 0);   */
/* 	cylinder->mat.kr2 = vec4_init(0, 0, 0, 0);   */
/* 	cylinder->mat.pattern = CHECKER; */
/* 	cylinder->transform = cy_transform(cylinder, &cylinder->inverse); */
/*  	ft_lstadd_back(&ctx.scene->shape, ft_lstnew(cylinder));  */
 	return (ctx);
}
