/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_other_matrix_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 18:55:06 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/18 18:55:44 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtx4.h"
#include "shapes_bonus.h"
#include "pattern_bonus.h"

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
	t_matrix4	scaling;
	t_matrix4	translation;
	double		r;

	r = me->diam / 2.0;
	translation = mtx4_translation(me->pos.x, me->pos.y, me->pos.z);
	scaling = mtx4_scaling(r, me->height / 2.0, r);
	transform = mtx4_times(translation, rotation_calc(me->norm));
	transform = mtx4_times(transform, scaling);
	mtx4_inverse(transform, inv);
	return (transform);
}

t_matrix4	rectangle_transform(t_rectangle *me, t_matrix4 *inv)
{
	t_matrix4	transform;
	t_matrix4	rotations;
	t_matrix4	scaling;
	t_matrix4	translation;

	translation = mtx4_translation(me->pos.x, me->pos.y, me->pos.z);
	rotations = rotation_calc(me->norm);
	scaling = mtx4_scaling(me->width * 0.5, 1, me->height * 0.5);
	transform = mtx4_times(rotations, scaling);
	transform = mtx4_times(translation, transform);
	mtx4_inverse(transform, inv);
	return (transform);
}
