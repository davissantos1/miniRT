/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:36:11 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/15 15:14:07 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "shapes.h"
#include "ray.h"
#include "vec4.h"
#include <math.h>
#include <stdbool.h>

static inline
void	fill_hits(t_sphere *obj, t_hit *hits, t_formula formula, t_ray ray);

bool	hit_sphere(void *me, t_hit *hits, t_ray ray)
{
	t_sphere	*obj;
	t_vec4		oc;
	t_formula	formula;
	double		delt;

	obj = me;
	oc = vec4_minus(obj->pos, ray.origin);
	formula.a = vec4_squared_len(ray.dir);
	formula.h = vec4_dot(ray.dir, oc);
	formula.c = vec4_squared_len(oc) - obj->diam * obj->diam / 4.0;
	delt = formula.h * formula.h - formula.a * formula.c;
	if (delt < 1e-7)
		return (false);
	delt = sqrt(delt);
	formula.r1 = formula.h - delt / formula.a;
	formula.r2 = formula.h + delt / formula.a;
	fill_hits(obj, hits, formula, ray);
	return (true);
}

static inline
void	fill_hits(t_sphere *obj, t_hit *hits, t_formula formula, t_ray ray)
{
	t_point	point;
	t_vec4	norm;

	if (hits->num_roots && formula.r1 > hits->r1)
		return ;
	hits->num_roots = 1;
	hits->r1 = formula.r1;
	hits->r2 = formula.r2;
	hits->num_roots += fabs(formula.r2 - formula.r1) > 1e-7;
	point = ray_pos(ray, formula.r1);
	hits->hit_point = point;
	norm = vec4_minus(point, obj->pos);
	hits->norm = vec4_scale(2 / obj->diam, norm);
	hits->material = obj->material;
	hits->me = obj;
}
