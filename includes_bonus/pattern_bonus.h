/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:43:03 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/20 13:43:05 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_BONUS_H
# define PATTERN_BONUS_H

# include "vec4.h"
# include "shapes.h"

typedef t_color(*t_patterns)(t_point,t_material);

t_color	get_pattern(t_point p, t_material m, t_pattern op);
t_color	striped(t_point p, t_material m);
t_color gradient(t_point p, t_material m);
t_color ring(t_point p, t_material m);
t_color	checker(t_point p, t_material m);

#endif