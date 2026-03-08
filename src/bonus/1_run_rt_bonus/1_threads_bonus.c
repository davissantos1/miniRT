/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_threads_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:41:36 by vitosant          #+#    #+#             */
/*   Updated: 2026/03/08 16:10:42 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads_bonus.h"
#include "settings.h"
#include "structs.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static void	start_routine(t_thread *param, int total);

void	create_threads(t_minirt *ctx, t_ndc ndc)
{
	t_thread	*thread_param;
	int			i;
	int			tot_threads;

	i = 0;
	tot_threads = (int)sysconf(_SC_NPROCESSORS_ONLN);
	thread_param = ft_calloc(sizeof(*thread_param), tot_threads);
	while (i < tot_threads)
	{
		thread_param[i].ctx = ctx;
		thread_param[i].ndc = ndc;
		thread_param[i].num = i;
		thread_param[i].px_count = WIDTH / tot_threads;
		thread_param[i].px_extra += (i == tot_threads - 1)
			* get_settings()->width % tot_threads;
		i++;
	}
	start_routine(thread_param, tot_threads);
	free(thread_param);
}

static void	start_routine(t_thread *param, int total)
{
	int	i;

	i = 0;
	while (i < total)
	{
		pthread_create(&param[i].thread_id, NULL, routine, &param[i]);
		i++;
	}
	i = 0;
	while (i < total)
	{
		(void)pthread_join(param[i].thread_id, NULL);
		i++;
	}
}
