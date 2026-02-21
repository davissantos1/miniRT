/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 23:10:27 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/20 23:15:20 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*get_name(char *name)
{
	char	*slash;

	name[ft_strlen(name) - 3] = '\0';
	slash = ft_strrchr(name, '/');
	if (slash)
		return (slash + 1);
	return (name);
}
