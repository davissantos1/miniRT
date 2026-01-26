/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx4_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:41:15 by vitosant          #+#    #+#             */
/*   Updated: 2026/01/26 11:18:42 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "mtx4.h"


inline int	mtx4_is_diff(t_matrix4 m1, t_matrix4 m2)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (m1.data[i] != m2.data[i])
			return (1);
	}
	return (0);
}

inline t_matrix4	mtx4_times(t_matrix4 m1, t_matrix4 m2)
{
	t_matrix4	ret;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ret.mtx[i][j] = m1.mtx[i][0] * m2.mtx[0][j]
				+ m1.mtx[i][1] * m2.mtx[1][j]
				+ m1.mtx[i][2] * m2.mtx[2][j]
				+ m1.mtx[i][3] * m2.mtx[3][j];
			j++;
		}
		i++;
	}
	return (ret);
}

inline t_matrix4	mtx4_identity(void)
{
	t_matrix4	ret;
	int			i;

	i = 0;
	ret = (t_matrix4) {0};
	while (i < 4)
	{
		ret.mtx[i][i] = 1.0;
		i++;
	}
	return (ret);
}

inline t_matrix4 mtx4_transpos(t_matrix4 m)
{
	t_matrix4	ret;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ret.mtx[i][j] = m.mtx[j][i];
			j++;
		}
		i++;
	}
	return (ret);
}
