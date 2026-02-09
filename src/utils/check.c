/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:06:47 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/09 19:52:29 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

int	check_if_double(char *str)
{
	int	len;
	int	i;
	int	p;

	i = 0;
	len = ft_strlen(str);
	if (str[0] == '.' || str[len -1] == '.')
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '.')	
			return (0);
		if (str[i] == '.')
			p++;
		i++;
	}
	if (p > 1)
		return (0);
	return (1);
}

int	check_number_3mtx(char **num)
{
	if (!num || !num[0] || !num[1] || !num[2] || num[3])
		return (0);
	if (!check_if_double(num[0]))
		return (0);
	if (!check_if_double(num[1]))
		return (0);
	if (!check_if_double(num[2]))
		return (0);
	return (1);
}

int	check_filename(char *file)
{
	size_t len;

	len = ft_strlen(file);
	if (len < 4)
		return (0);
	if (ft_strcmp(file + len - 3, ".rt") == 0)
		return (1);
	return (0);
}

int	check_empty(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (!ft_isspace(line[i]))
			return (0);
	}
	return (1);
}

int	check_positive(char *num)
{
	double	number;

	if (!check_if_double(num))
		return (0);
	number = ft_atod(num);
	if (number <= 0.0f)
		return (0);
	return (1);
}
