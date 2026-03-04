/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_run_rt_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitor <vitor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:43:25 by vitosant          #+#    #+#             */
/*   Updated: 2026/03/03 21:05:28 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vec4.h"
#include "entities.h"
#include "threads_bonus.h"
#include "mlx.h"
#include <math.h>

void	run_rt(t_minirt *ctx)
{
	t_camera	*cam;
	t_ndc		ndc;

	cam = ctx->scene->camera;
	ndc.ratio = get_settings()->aspect_ratio;
	ndc.scale = tan(cam->fov * 0.5 * (PI / 180.0));
	ndc.w = vec4_scale(-1, cam->norm);
	if (fabs(ndc.w.y) > 0.999)
		ndc.u = vec4_unit_vector(vec4_cross(vec4_init(1, 0, 0, 0), ndc.w));
	else
		ndc.u = vec4_unit_vector(vec4_cross(vec4_init(0, 1, 0, 0), ndc.w));
	ndc.v = vec4_unit_vector(vec4_cross(ndc.w, ndc.u));
	create_threads(ctx, ndc);
	mlx_put_image_to_window(ctx->mlx->init, ctx->mlx->win, ctx->mlx->img, 0, 0);
}
