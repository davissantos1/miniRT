/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasimoes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:20:36 by dasimoes          #+#    #+#             */
/*   Updated: 2026/01/15 13:19:18 by dasimoes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// External includes
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <sys/time.h>
# include <stdlib.h>

// Local includes
# include "../libft/libft.h"

// Enums
typedef enum e_status
{
	SUCCESS,
	ERR_ARG_NUM,
	ERR_ARG_INVALID,
	ERR_SYSCALL,
	COUNT
}	t_status;

// Macros

// Structs

//Prototypes

#endif
