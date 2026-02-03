/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:06:47 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/02 20:11:14 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minirt.h"

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
