
#include "vec4.h"
#include "shapes_bonus.h"
#include "pattern_bonus.h"
#include "mtx4.h"
#include "settings.h"

void	get_pattern(t_hit *hit, t_pattern op)
{
	static t_patterns	patterns[3] = {checker, striped, ring};
	t_point	p;

	p = vec4_multi_mtx4(hit->inverse, hit->hit_point);
	p.x += EPSILON;
	p.y += EPSILON;
	p.z += EPSILON;
	p = vec4_scale(hit->mat.pattern_const, p);
	hit->mat.color = patterns[op](p, hit->mat);
	if (!vec4_is_diff(hit->mat.color, hit->mat.color2))
	{
		hit->mat.ka = hit->mat.ka2;
		hit->mat.ks = hit->mat.ks2;
		hit->mat.kr = hit->mat.kr2;
	}
}
