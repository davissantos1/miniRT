/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:18:04 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/18 15:45:00 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	test_parser(t_minirt *rt)
{
	t_list		*shapes;
	t_camera	*cam;
	t_alight	*amb;
	t_light		*lig;
	t_plane		*pl;
	t_sphere	*sp;
	t_cylinder	*cy;

	shapes = rt->scene->shape;
	cam = rt->scene->camera;
	amb = rt->scene->alight;
	lig = rt->scene->light;
	cy = shapes->content;
	shapes = shapes->next;
	sp = shapes->content;
	shapes = shapes->next;
	pl = shapes->content;
	
	printf("TESTING PARSER...\n\n");
	printf("AMBIENT LIGHT\n\n");
	printf("ratio: %f \n", amb->ratio);
	printf("color: x: %f, y: %f, z: %f, w: %f \n\n", amb->color.x, amb->color.y, amb->color.z, amb->color.w);
	printf("CAMERA\n\n");
	printf("position: x: %f, y: %f, z: %f, w: %f \n", cam->pos.x, cam->pos.y, cam->pos.z, cam->pos.w);
	printf("normal: x: %f, y: %f, z: %f, w: %f \n", cam->norm.x, cam->norm.y, cam->norm.z, cam->norm.w);
	printf("fov: %d \n\n", cam->fov);
	printf("LIGHT\n\n");
	printf("position: x: %f, y: %f, z: %f, w: %f \n", lig->pos.x, lig->pos.y, lig->pos.z, lig->pos.w);
	printf("ratio: %f \n", lig->ratio);
	printf("color: x: %f, y: %f, z: %f, w: %f \n\n", lig->color.x, lig->color.y, lig->color.z, lig->color.w);
	printf("PLANE\n\n");
	printf("position: x: %f, y: %f, z: %f, w: %f \n", pl->pos.x, pl->pos.y, pl->pos.z, pl->pos.w);
	printf("normal: x: %f, y: %f, z: %f, w: %f \n", pl->norm.x, pl->norm.y, pl->norm.z, pl->norm.w);
	printf("color: x: %f, y: %f, z: %f, w: %f \n\n", pl->color.x, pl->color.y, pl->color.z, pl->color.w);
	printf("SPHERE\n\n");
	printf("position: x: %f, y: %f, z: %f, w: %f \n", sp->pos.x, sp->pos.y, sp->pos.z, sp->pos.w);
	printf("diameter: %f \n", sp->diam);
	printf("color: x: %f, y: %f, z: %f, w: %f \n\n", sp->color.x, sp->color.y, sp->color.z, sp->color.w);
	printf("CYLINDER\n\n");
	printf("position: x: %f, y: %f, z: %f, w: %f \n", cy->pos.x, cy->pos.y, cy->pos.z, cy->pos.w);
	printf("normal: x: %f, y: %f, z: %f, w: %f \n", cy->norm.x, cy->norm.y, cy->norm.z, cy->norm.w);
	printf("diameter: %f \n", cy->diam);
	printf("height: %f \n", cy->height);
	printf("color: x: %f, y: %f, z: %f, w: %f \n\n", cy->color.x, cy->color.y, cy->color.z, cy->color.w);
}
