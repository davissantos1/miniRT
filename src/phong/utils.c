/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 17:09:13 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/15 21:39:51 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"

t_vec4	reflec_dir(t_vec4 norm, t_vec4 dir)
{
	double	dot;

	dot = vec4_dot(norm, dir) * 2.0;
	return (vec4_minus(dir, vec4_scale(dot, norm)));
}
