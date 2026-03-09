/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:20:49 by vitosant          #+#    #+#             */
/*   Updated: 2026/03/08 20:05:17 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_BONUS_H
# define THREADS_BONUS_H

# include "structs.h"
# include <bits/pthreadtypes.h>
# include <pthread.h>

typedef struct s_thread
{
	pthread_t	thread_id;
	t_minirt	*ctx;
	t_ndc		ndc;
	int			num;
	int			px_count;
	int			px_extra;
}	t_thread;

void	create_threads(t_minirt *ctx, t_ndc ndc);
void	*routine(void *info);

#endif
