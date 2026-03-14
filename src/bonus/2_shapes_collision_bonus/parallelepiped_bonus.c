/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallelepiped_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 10:50:11 by vitosant          #+#    #+#             */
/*   Updated: 2026/03/14 12:09:47 by vitosant         ###    ########.fr      */
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
	rec.pos = ray_pos((t_ray){.origin = obj->pos, obj->norm}, distance);
	rec.width = obj->width;
	rec.height = obj->depth;
	rec.norm = obj->norm;
	rec.transform = rectangle_transform(&rec, &rec.inverse);
	hit_any = hit_rectangle(&rec, hits, ray);
	rec.pos = ray_pos((t_ray){.origin = obj->pos, obj->norm}, -distance);
	rec.transform = rectangle_transform(&rec, &rec.inverse);
	hit_any |= hit_rectangle(&rec, hits, ray);
	return (hit_any);
}

static inline
bool	x_faces(t_parallelepiped *obj, t_rectangle rec, t_hit *hits, t_ray ray)
{
	t_vec4	norm;
	bool	hit_any;
	double	distance;

	if (fabs(obj->norm.y) > 0.99999)
		norm = vec4_cross(obj->norm, (t_vec4){1 * obj->norm.y, 0, 0, 0});
	else
		norm = vec4_unit_vector(vec4_cross(obj->norm, (t_vec4){0, 1, 0, 0}));
	distance = obj->depth * 0.5;
	rec.pos = ray_pos((t_ray){.origin = obj->pos, norm}, distance);
	rec.width = obj->width;
	rec.height = obj->height;
	rec.norm = vec4_unit_vector(norm);
	rec.transform = rectangle_transform(&rec, &rec.inverse);
	hit_any = hit_rectangle(&rec, hits, ray);
	rec.pos = ray_pos((t_ray){.origin = obj->pos, norm}, -distance);
	rec.transform = rectangle_transform(&rec, &rec.inverse);
	hit_any |= hit_rectangle(&rec, hits, ray);
	return (hit_any);
}


static inline
bool	z_faces(t_parallelepiped *obj, t_rectangle rec, t_hit *hits, t_ray ray)
{
	t_vec4	norm;
	bool	hit_any;
	double	distance;

	if (fabs(obj->norm.y) > 0.99999)
		norm = vec4_cross(obj->norm, (t_vec4){1 * obj->norm.y, 0, 0, 0});
	else
		norm = vec4_cross(obj->norm, (t_vec4){0, 1, 0, 0});
	norm = vec4_unit_vector(vec4_cross(norm, obj->norm));
	distance = obj->width * 0.5;
	rec.pos = ray_pos((t_ray){.origin = obj->pos, norm}, distance);
	rec.width = obj->depth;
	rec.height = obj->height;
	rec.norm = norm;
	rec.transform = rectangle_transform(&rec, &rec.inverse);
	hit_any = hit_rectangle(&rec, hits, ray);
	rec.pos = ray_pos((t_ray){.origin = obj->pos, norm}, -distance);
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
