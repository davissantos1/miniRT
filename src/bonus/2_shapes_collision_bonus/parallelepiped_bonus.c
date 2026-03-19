/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallelepiped_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 10:50:11 by vitosant          #+#    #+#             */
/*   Updated: 2026/03/19 20:17:10 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "shapes_bonus.h"
#include "vec4.h"
#include <math.h>
#include <stdbool.h>

static inline
bool	y_faces(t_parallelepiped *obj, t_rectangle rec, t_hit *hits, t_ray ray)
{
	bool	hit_any;
	double	distance;

	distance = obj->height * 0.5;
	rec.height = obj->depth;
	rec.width = obj->width;
	rec.norm = obj->norm;
	rec.pos = ray_pos(ray_init(obj->pos, obj->norm), distance);
	rec.transform = rectangle_transform(&rec, &rec.inverse);
	hit_any = hit_rectangle(&rec, hits, ray);
	rec.pos = ray_pos(ray_init(obj->pos, obj->norm), -distance);
	rec.transform = rectangle_transform(&rec, &rec.inverse);
	hit_any |= hit_rectangle(&rec, hits, ray);
	return (hit_any);
}

static inline
bool	x_faces(t_parallelepiped *obj, t_rectangle rec, t_hit *hits, t_ray ray)
{
	bool	hit_any;
	t_vec4	normal;
	double	distance;

	distance = obj->width * 0.5;
	rec.height = obj->height;
	rec.width = obj->depth;
	if (fabs(obj->norm.y) > 0.9999)
		normal = vec4_init(1 * obj->norm.y, 0, 0, 0);
	else
		normal = vec4_cross(obj->norm, vec4_init(0, 1, 0, 0));
	normal = vec4_unit_vector(normal);
	rec.norm = normal;
	rec.pos = ray_pos(ray_init(obj->pos, normal), distance);
	rec.transform = rectangle_transform(&rec, &rec.inverse);
	hit_any = hit_rectangle(&rec, hits, ray);
	rec.pos = ray_pos(ray_init(obj->pos, obj->norm), -distance);
	rec.transform = rectangle_transform(&rec, &rec.inverse);
	hit_any |= hit_rectangle(&rec, hits, ray);
	return (hit_any);
}

static inline
bool	z_faces(t_parallelepiped *obj, t_rectangle rec, t_hit *hits, t_ray ray)
{
	bool	hit_any;
	t_vec4	normal;
	double	distance;

	distance = obj->depth * 0.5;
	rec.height = obj->height;
	rec.width = obj->width;
	if (fabs(obj->norm.y) > 0.9999)
		normal = vec4_init(1 * obj->norm.y, 0, 0, 0);
	else
		normal = vec4_cross(obj->norm, vec4_init(0, 1, 0, 0));
	normal = vec4_cross(normal, obj->norm);
	normal = vec4_unit_vector(normal);
	rec.norm = normal;
	rec.pos = ray_pos(ray_init(obj->pos, normal), distance);
	rec.transform = rectangle_transform(&rec, &rec.inverse);
	hit_any = hit_rectangle(&rec, hits, ray);
	rec.pos = ray_pos(ray_init(obj->pos, obj->norm), -distance);
	rec.transform = rectangle_transform(&rec, &rec.inverse);
	hit_any |= hit_rectangle(&rec, hits, ray);
	return (hit_any);
}

bool	hit_parallelepiped(void *me, t_hit *hits, t_ray ray)
{
	t_parallelepiped	*obj;
	t_rectangle			rec;
	bool				hit_any;

	obj = me;
	rec.type = RECTANGLE;
	rec.mat = obj->mat;
	hit_any = y_faces(obj, rec, hits, ray);
	hit_any |= x_faces(obj, rec, hits, ray);
	hit_any |= z_faces(obj, rec, hits, ray);
	return (hit_any);
}
