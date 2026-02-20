/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx4_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 18:22:08 by vitosant          #+#    #+#             */
/*   Updated: 2026/01/30 21:45:12 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "mtx4.h"
#include <stdio.h>

void	print_mtx(t_matrix4 m)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i % 4 == 0 && i != 0)
			printf("\n");
		printf("%.2f ", m.data[i]);
		i++;
	}
	printf("\n");
}

inline double	dabs(double det)
{
	return ((det < 0) * -det + (det > 0) * det);
}
