/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:36:11 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/09 13:41:52 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shapes.h"
#include "ray.h"
#include "vec4.h"
#include <math.h>
#include <stdbool.h>

bool	hit_sphere(t_scene *scene, void *me, t_hit *hits, t_ray ray)
{
	t_sphere	*obj;
	double		a;
	double		h;
	double		c;
	double		delt;

	obj = me;
	a = vec4_squared_len(ray.dir);
	h = vec4_dot(ray.dir, vec4_minus(obj->pos, ray.origin));
	c = vec4_squared_len(vec4_minus(obj->pos, ray.origin)) - obj->diam * obj->diam / 4.0;
	delt = h * h - a * c;
	if (delt < 0)
		return (false);
	set_roots(obj, (h - sqrt(delt)) / a, (h + sqrt(delt)) / a, hits);
	return (true);
}
