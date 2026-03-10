/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <dasimoes@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:59:13 by dasimoes          #+#    #+#             */
/*   Updated: 2026/03/10 17:49:40 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	add_object(t_minirt *rt, void *obj)
{
	t_list	*new;

	new = ft_lstnew(obj);
	ft_lstadd_front(&(rt->scene->shape), new);
}

void	add_light(t_minirt *rt, t_light *l)
{
	t_light	*ptr;

	if (!rt->scene->light)
		return ;
	ptr = rt->scene->light;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = l;
}
