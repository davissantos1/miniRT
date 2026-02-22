
#include "vec4.h"
#include "shapes_bonus.h"
#include "pattern_bonus.h"
#include "mtx4.h"
#include <stdio.h>

t_color	get_pattern(t_hit hit, t_pattern op)
{
	static t_patterns	patterns[4] = {checker, gradient, striped, ring};
	t_point	p;

	p = hit.hit_point;
	return (patterns[op](p, hit.mat));
}
