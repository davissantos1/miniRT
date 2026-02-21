/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 08:52:46 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/20 10:16:53 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	intersection(t_disk *obj, double t, t_hit *hits, t_ray ray);

bool	hit_disk(void *me, t_hit *hits, t_ray ray)
{
	t_disk	*obj;
	double		denom;
	double		t;
	t_vec4		oc;
	
	obj = me;
	denom = vec4_dot(obj->norm, ray.dir);
	if (fabs(denom) <= EPSILON)
		return (false);
	oc = vec4_minus(obj->pos, ray.origin);
	t = vec4_dot(oc, obj->norm) / denom;
	if (fabs(t) <= EPSILON)
		return (false);
	return (intersection(obj, t, hits, ray));	
}

static inline bool	intersection(t_disk *obj, double t, t_hit *hits, t_ray ray)
{
	t_point	p;
	t_vec4	v;
	double distance;

	p = ray_pos(ray, t);
	v = vec4_minus(p, obj->pos);
	distance = vec4_squared_len(v);
	if (distance > obj->diam * obj->diam / 4 || (t > hits->r1 && hits->num_roots))
		return (false);
	hits->r1 = t;
	hits->num_roots = 1;
	hits->mat = obj->mat;
	hits->norm = obj->norm;
	hits->hit_point = p;
	hits->me = obj;
	return (true);
}
