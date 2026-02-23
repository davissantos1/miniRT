/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 11:36:11 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/22 20:46:59 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"
#include "settings.h"

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
	hits->num_roots += fabs(formula.r2 - formula.r1) > EPSILON;
	point = ray_pos(ray, formula.r1);
	hits->hit_point = point;
	norm = vec4_minus(point, obj->pos);
	hits->norm = vec4_scale(2 / obj->diam, norm);
	hits->mat = obj->mat;
}

bool	hit_sphere(void *me, t_hit *hits, t_ray ray)
{
	t_sphere	*obj;
	t_vec4		oc;
	t_formula	formula;
	double		delt;

	obj = me;
	oc = vec4_minus(obj->pos, ray.origin);
	formula.h = vec4_dot(ray.dir, oc);
	formula.c = vec4_squared_len(oc) - obj->diam * obj->diam / 4.0;
	delt = formula.h * formula.h - formula.c;
	if (delt < EPSILON)
		return (false);
	delt = sqrt(delt);
	formula.r1 = formula.h - delt;
	formula.r2 = formula.h + delt;
	if (formula.r2 < EPSILON && formula.r1 < EPSILON)
		return (false);
	if (formula.r1 < EPSILON || formula.r2 < formula.r1)
		formula.r1 = formula.r2;
	fill_hits(obj, hits, formula, ray);
	return (true);
}
