
#include "vec4.h"
#include "shapes_bonus.h"
#include "pattern_bonus.h"
#include "mtx4.h"
#include "settings.h"

t_color	get_pattern(t_hit hit, t_pattern op)
{
	static t_patterns	patterns[3] = {checker, striped, ring};
	t_point	p;

	p = vec4_multi_mtx4(hit.inverse, hit.hit_point);
	p.x += EPSILON;
	p.y += EPSILON;
	p.z += EPSILON;
	p = vec4_scale(hit.mat.pattern_const, p);
	return (patterns[op](p, hit.mat));
}
