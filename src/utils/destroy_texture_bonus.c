/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_texture_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 13:33:01 by vitosant          #+#    #+#             */
/*   Updated: 2026/03/01 16:28:38 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "shapes_bonus.h"
#include "texture_bonus.h"
#include "mlx.h"

static inline t_shape	get_type(t_handle *content)
{
	return (content->type);
}

static t_texture handle_texture(t_shape type, void *content)
{
	if (type == SPHERE)
		return (((t_sphere *)content)->mat.texture);
	if (type == PLANE)
		return (((t_plane *)content)->mat.texture);
	if (type == DISK)
		return (((t_disk *)content)->mat.texture);
	if (type == CYLINDER)
		return (((t_cylinder *)content)->mat.texture);
	return (((t_cone *)content)->mat.texture);
}

void	destroy_texture(void *content)
{
	t_texture tex;

	tex = handle_texture(get_type(content), content);
	if (tex.img)
		mlx_destroy_image(tex.mlx_ptr, tex.img);
	//free(content);
}
