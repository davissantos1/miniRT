/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 11:00:55 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/25 16:47:01 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "mtx4.h"
#include "shapes_bonus.h"
#include "pattern_bonus.h"

t_matrix4	sphere_transform(t_sphere *me, t_matrix4 *inv)
{
	t_matrix4	transform;
	t_matrix4	translation;
	double		r;

	r = me->diam / 2.0;
	translation = mtx4_translation(me->pos.x, me->pos.y, me->pos.z);
	transform = mtx4_times(translation, mtx4_scaling(r, r, r));
	mtx4_inverse(transform, inv);
	return (transform);
}

t_matrix4	cy_transform(t_cylinder *me, t_matrix4 *inv)
{
	t_matrix4	transform;
	t_matrix4	translation;
	double		r;

	r = me->diam / 2.0;
	translation = mtx4_translation(me->pos.x, me->pos.y, me->pos.z);
	transform = mtx4_times(translation, rotation_calc(me->norm));
	transform = mtx4_times(transform, mtx4_scaling(r, me->height / 2.0, r));
	mtx4_inverse(transform, inv);
	return (transform);
}

t_matrix4	plane_transform(t_plane *me, t_matrix4 *inv)
{
	t_matrix4	transform;
	t_matrix4	rotations;
	t_matrix4	translation;

	translation = mtx4_translation(me->pos.x, me->pos.y, me->pos.z);
	rotations = rotation_calc(me->norm);
	transform = mtx4_times(rotations, mtx4_scaling(1, 1, 1));
	transform = mtx4_times(translation, transform);
	mtx4_inverse(transform, inv);
	return (transform);
}

t_matrix4	disk_transform(t_disk *me, t_matrix4 *inv)
{
	t_matrix4	transform;
	t_matrix4	rotations;
	t_matrix4	translation;
	double		r;

	r = me->diam / 2.0;
	translation = mtx4_translation(me->pos.x, me->pos.y, me->pos.z);
	rotations = rotation_calc(me->norm);
	transform = mtx4_times(rotations, mtx4_scaling(r, r, r));
	transform = mtx4_times(translation, transform);
	mtx4_inverse(transform, inv);
	return (transform);
}

t_matrix4	cone_transform(t_cone *me, t_matrix4 *inv)
{
	t_matrix4	transform;
	t_matrix4	translation;

	translation = mtx4_translation(me->pos.x, me->pos.y, me->pos.z);
	transform = mtx4_times(translation, rotation_calc(me->norm));
	mtx4_inverse(transform, inv);	
	return (transform);
}
