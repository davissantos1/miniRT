/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:59:13 by dasimoes          #+#    #+#             */
/*   Updated: 2026/02/09 20:03:36 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_object(t_minirt *rt, void *obj)
{
	t_list	*new;

	new = ft_lstnew(obj);
	ft_lstaddfront(&(rt->scene->shape), new);
}
