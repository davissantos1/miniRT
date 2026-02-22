/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 13:43:03 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/21 12:43:59 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_BONUS_H
# define PATTERN_BONUS_H

# include "vec4.h"
# include "shapes_bonus.h"
# include "mtx4.h"

typedef t_color(*t_patterns)(t_point,t_material);

t_color	get_pattern(t_hit hit, t_pattern op);
t_color	striped(t_point p, t_material m);
t_color gradient(t_point p, t_material m);
t_color ring(t_point p, t_material m);
t_color	checker(t_point p, t_material m);

t_matrix4	rotation_calc(t_vec4 norm);

#endif
