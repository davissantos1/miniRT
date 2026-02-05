/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:59:17 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/04 12:00:50 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"

inline t_vec4	vec4_init(double x, double y, double z, double w)
{
	t_vec4	ret;

	ret.w = w;
	ret.z = z;
	ret.y = y;
	ret.x = x;
	return (ret);
}
