/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 08:39:24 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/28 09:27:42 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "settings.h"
#include "texture_bonus.h"
#include "mlx.h"

t_texture	load_img(t_minirt *ctx, char *path)
{
	t_texture	ret;

	ret.img = mlx_xpm_file_to_image(ctx->mlx->init, path,
			&ret.width, &ret.height);
	if (!ret.img)
		desperation(ctx, ERR_SYSCALL);
	ret.addr = mlx_get_data_addr(ret.img, &ret.bpp,
			&ret.line, &ret.end);
	if (!ret.addr)
		desperation(ctx, ERR_SYSCALL);
	return (ret);
}
