/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:47:59 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/21 13:02:02 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(char *s)
{
	int		i;
	double	sign;
	double	point;
	double	res;

	i = 0;
	sign = 1;
	point = 10;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+' || s[i] == '-')
		if (s[i++] == '-')
			sign = -1;
	res = ft_atoi(s + i);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] && s[i++] == '.')
	{
		while (s[i] >= '0' && s[i] <= '9')
		{
			res += (s[i++] - '0') / point;
			point *= 10;
		}
	}
	return (res * sign);
}
