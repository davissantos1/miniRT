/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx4_scaling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 09:47:18 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/21 09:50:29 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "mtx4.h"

inline t_matrix4	mtx4_scaling(double x, double y, double z)
{
	t_matrix4	ret;

	ret = (t_matrix4){0};
	ret.data[0] = x;
	ret.data[5] =  y;
	ret.data[10] = z;
	ret.data[15] = 1.0;
	return (ret);
}
