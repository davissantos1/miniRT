/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:47:59 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/09 13:48:45 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(char *s)
{
	int		i;
	double	point;
	double	whole;
	double	decimal;

	i = 0;
	point = 10;
	decimal = 0;
	whole = (double)ft_atoi(s);
	while (s[i] != '.' && s[i])
		i++;
	if (s[i] == '.')
	{
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			decimal += (s[i] - '0') / point;
			point *= 10;
			i++;
		}
	}
	if (whole < 0)
		return (whole - decimal);
	return (whole + decimal);
}
