/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 08:52:46 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/10 09:22:53 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "shapes.h"
#include "vec4.h"
#include <stdbool.h>

static bool	intersection(t_circle *obj, double t, t_hit *hits, t_ray ray);

bool	hit_circle(t_scene *scene, void *me, t_hit *hits, t_ray ray)
{
	t_circle	*obj;
	double		denom;
	double		t;
	t_vec4		oc;
	
	obj = me;
	denom = vec4_dot(obj->norm, ray.dir);
	if (fabs(denom) <= 1e-7)
		return (false);
	oc = vec4_minus(obj->pos, ray.origin);
	t = vec4_dot(oc, obj->norm) / denom;
	if (fabs(t) <= 1e-7)
		return (false);
	return (intersection(obj, t, hits, ray));	
}

static inline bool	intersection(t_circle *obj, double t, t_hit *hits, t_ray ray)
{
	t_point	p;
	t_vec4	v;
	double distance;

	p = ray_pos(ray, t);
	v = vec4_minus(p, obj->pos);
	distance = vec4_squared_len(v);
	if (distance > obj->diam * obj->diam / 4 || t > hits->r1)
		return (false);
	hits->r1 = t;
	hits->num_roots = 1;
	hits->material = obj->material;
	hits->norm = obj->norm;
	hits->hit_point = ray_pos(ray, t);
	return (true);
}
