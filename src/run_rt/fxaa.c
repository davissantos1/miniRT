/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fxaa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 15:23:05 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/19 18:40:24 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "settings.h"
#include "structs.h"
#include "vec4.h"
#include <stdlib.h>

static inline void get_color(t_mlx *mlx, t_vec4 *vec, int x, int y)
{
	unsigned int	pixel;

	pixel = *(unsigned int *)(mlx->addr + (y * mlx->line + x * (mlx->bpp / 8)));
	vec->x += (double)((pixel >> 16) & 0xFF);
	vec->y +=  (double)((pixel >> 8) & 0xFF);
	vec->z += (double)((pixel) & 0xFF);
}

static inline void	fxaa_pixel(t_mlx *mlx, char *pixels, int x, int y)
{
	t_color	color;

	color = vec4_init(0, 0, 0, 0);
	if (x == 0 && y == 0)
	{
		get_color(mlx, &color, x, y);
		color = vec4_scale(4, color);
		get_color(mlx, &color, x + 1, y);
		get_color(mlx, &color, x, y + 1);
		color = vec4_scale(1.0 / 6.0, color);
	}
	else if (x == 0 && y == HEIGHT - 1)
	{
		get_color(mlx, &color, x, y);
		color = vec4_scale(4, color);
		get_color(mlx, &color, x, y - 1);
		get_color(mlx, &color, x + 1, y);
		color = vec4_scale(1.0 / 6.0, color);
	}
	else if (x == WIDTH - 1 && y == 0)
	{
		get_color(mlx, &color, x, y);
		color = vec4_scale(4, color);
		get_color(mlx, &color, x, y + 1);
		get_color(mlx, &color, x - 1, y);
		color = vec4_scale(1.0 / 6.0, color);
	}
	else if (x == WIDTH - 1 && y == HEIGHT -1)
	{
		get_color(mlx, &color, x, y);
		color = vec4_scale(4, color);
		get_color(mlx, &color, x, y - 1);
		get_color(mlx, &color, x - 1, y);
		color = vec4_scale(1.0 / 6.0, color);;
	}
	else if (x == 0)
	{
		get_color(mlx, &color, x, y);
		color = vec4_scale(4, color);
		get_color(mlx, &color, x, y - 1);
		get_color(mlx, &color, x, y + 1);
		get_color(mlx, &color, x + 1, y);
		color = vec4_scale(1.0 / 7.0, color);
	}
	else if (x == WIDTH - 1)
	{
		get_color(mlx, &color, x, y);
		color = vec4_scale(4, color);
		get_color(mlx, &color, x, y - 1);
		get_color(mlx, &color, x, y + 1);
		get_color(mlx, &color, x - 1, y);
		color = vec4_scale(1.0 / 7.0, color);
	}
	else if (y == 0)
	{
		get_color(mlx, &color, x, y);
		color = vec4_scale(4, color);
		get_color(mlx, &color, x - 1, y);
		get_color(mlx, &color, x + 1, y);
		get_color(mlx, &color, x, y + 1);
		color = vec4_scale(1.0 /7.0, color);
	}
	else if (y == HEIGHT - 1)
	{
		get_color(mlx, &color, x, y);
		color = vec4_scale(4, color);
		get_color(mlx, &color, x - 1, y);
		get_color(mlx, &color, x + 1, y);
		get_color(mlx, &color, x, y - 1);
		color = vec4_scale(1.0 / 7.0, color);
	}
	else
	{
		get_color(mlx, &color, x, y);
		color = vec4_scale(4, color);
		get_color(mlx, &color, x - 1, y);
		get_color(mlx, &color, x + 1, y);
		get_color(mlx, &color, x, y + 1);
		get_color(mlx, &color, x, y - 1);
		color = vec4_scale(1.0 / 8.0, color);
	}
	*(int *)(pixels + (x * (mlx->bpp / 8) + y * mlx->line)) = ((int)color.x << 16 | (int)color.y << 8 | (int)color.z);
}

void	fxaa(t_mlx *mlx)
{
	char	*pixels;
	int		x;
	int		y;

	y = 0;
	pixels = malloc(WIDTH * HEIGHT * (mlx->bpp / 8));
	if (!pixels)
		return ;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			fxaa_pixel(mlx, pixels, x, y);
			x++;
		}
		y++;
	}
	ft_memcpy(mlx->addr, pixels, WIDTH * HEIGHT * sizeof(int));
	free(pixels);
}
