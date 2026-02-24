#include "shapes_bonus.h"
#include "vec4.h"
#include "pattern_bonus.h"
#include <math.h>

t_color	striped(t_point p, t_material m)
{
	int		x;
	t_vec4	colors[2];

	colors[0] = m.color;
	colors[1] = m.color2;
	x = (int)floor(p.x * 3.0);
	return (colors[abs(x) % 2]);
}

t_color ring(t_point p, t_material m)
{
	double		sqrt_x;
	double		sqrt_z;
	int			result;
	t_vec4		colors[2];

	colors[0] = m.color;
	colors[1] = m.color2;
	sqrt_z = p.z * p.z * 10;
	sqrt_x = p.x * p.x * 10;
	result = (int)floor(sqrt(sqrt_x + sqrt_z));
	return (colors[result % 2]);
}

t_color	checker(t_point p, t_material m)
{
	int		result;
	t_vec4	colors[2];

	colors[0] = m.color;
	colors[1] = m.color2;
	result = (int)(floor(p.x) + floor(p.y) + floor(p.z));
	return (colors[abs(result) % 2]);
}