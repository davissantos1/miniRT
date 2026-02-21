
#include "vec4.h"
#include "shapes.h"
#include "pattern_bonus.h"

t_color	get_pattern(t_point p, t_material m, t_pattern op)
{
	static t_patterns	patterns[] = {checker, gradient, striped, ring};

	return (patterns[op](p, m));
}