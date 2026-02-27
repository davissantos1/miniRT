/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 09:59:18 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/27 17:40:04 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "shapes_bonus.h"
#include "texture_bonus.h"
#include "vec4.h"
#include <math.h>

static t_color	get_texture_color(t_texture texture, int x, int y)
{
	t_color			color;
	unsigned int	raw_color;

	raw_color = *(unsigned int *)(texture.addr + (x * (texture.bpp >> 3))
								  + (y * (texture.line)));
	color.z = (raw_color & 0xff);
	color.y = ((raw_color >> 8) & 0xff);
	color.x = ((raw_color >> 16) & 0xff);
	color.w = 0;
	return (vec4_scale(1.0 / 255.0, color));
}

static void get_tan_bitan(t_hit *hit, t_vec4 *wtan, t_vec4 *wbitan)
{
	t_vec4	tan;
	t_vec4	bitan;
	t_vec4	norm;

	norm = vec4_multi_mtx4(hit->inverse, hit->norm);
	if (fabs(norm.y) > 0.999)
	{
		tan = vec4_init(1, 0, 0, 0);
		bitan = vec4_init(0, 0, -1, 0);
	}
	else
	{
		tan = vec4_unit_vector(vec4_cross(vec4_init(0, 1, 0, 0), norm));
		bitan = vec4_unit_vector(vec4_cross(norm, tan));
	}
	*wtan = vec4_multi_mtx4(hit->transform, tan);
	*wbitan = vec4_multi_mtx4(hit->transform, bitan);
}
static void get_magnitude(t_hit *hit, double *mags, double u, double v)
{
	t_color	color[3];
	double	base_px;
	double	mag_u;
	double	mag_v;
	
	color[0] = get_texture_color(hit->mat.texture, (int)(u * (hit->mat.texture.width - 1)),
								 (int)(v * (hit->mat.texture.height - 1)));
	color[1] = get_texture_color(hit->mat.texture,
								 (int)(u * (hit->mat.texture.width - 1)),
								 (int)(v * (hit->mat.texture.height - 1) + 1)
								 % hit->mat.texture.height);
	color[2] = get_texture_color(hit->mat.texture,
								 (int)(u * (hit->mat.texture.width - 1) + 1)
								 % hit->mat.texture.width,
								 (int) (v * (hit->mat.texture.height - 1)));
	base_px = (color[0].x + color[0].y + color[0].z) * 0.33 ;
	mag_v = (color[1].x + color[1].y + color[1].z) * 0.33 - base_px;
	mag_u = (color[2].x + color[2].y + color[2].z) * 0.33 - base_px;
	mags[0] = mag_v * 2;
	mags[1] = mag_u * 1.5;
}

void	normal_map(t_hit *hit, uv_map *maps, t_point p)
{
	t_vec4	tan;
	t_vec4	bitan;
	double	u;
	double	v;

	maps[hit->type](p, &u, &v);
	hit->mat.color = get_texture_color(hit->mat.texture, (int)(u * (hit->mat.texture.width - 1)), (int)(v * (hit->mat.texture.height - 1)));
	hit->mat.ka = vec4_scale(0.6, hit->mat.color);
	get_tan_bitan(hit, &tan, &bitan);
	tan = vec4_scale(hit->mat.color.x, tan);
	bitan = vec4_scale(hit->mat.color.y, bitan);
	hit->norm = vec4_scale(hit->mat.color.z, hit->norm);
	hit->norm = vec4_plus(vec4_plus(tan, bitan), hit->norm);
	hit->norm = vec4_unit_vector(hit->norm);
}



void bump_map(t_hit *hit, uv_map *maps, t_point p)
{
	t_vec4	tan;
	t_vec4	bitan;
	double	u;
	double	v;
	double	mags[2];

	maps[hit->type](p, &u, &v);
	get_tan_bitan(hit, &tan, &bitan);
	get_magnitude(hit, mags, u, v);
	tan = vec4_scale(mags[0], tan);
	bitan = vec4_scale(mags[1], bitan);
	hit->norm = vec4_minus(vec4_minus(hit->norm, tan), bitan);
}
