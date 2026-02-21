#include "shapes.h"
#include "vec4.h"
#include "pattern_bonus.h"


static inline t_color	get_complementary(t_color color)
{
	return (vec4_minus((t_vec4){1.0, 1.0, 1.0, 0.0}, color));
}

t_color	striped(t_point p, t_material m)
{
	int	x;

	x = (int)floor(p.x);
	if (abs(x) % 2 == 0)
		return (m.color);
	return (get_complementary(m.color));
}

t_color gradient(t_point p, t_material m)
{
	t_color	result;
	t_color	other;
	double	t;

	t = (p.x + 1.0) / 2.0;
	t = fmax(0, fmin(1.0, t));
	other = vec4_minus(get_complementary(m.color), m.color);
	result = vec4_plus(m.color, vec4_scale(t, other));
	return (result);
}

t_color ring(t_point p, t_material m)
{
	double	sqrt_x;
	double	sqrt_z;
	int		result;

	sqrt_z = p.z * p.z * 10;
	sqrt_x = p.x * p.x * 10;
	result = (int)floor(sqrt(sqrt_x + sqrt_z));
	if (result % 2 == 0)
		return(m.color);
	return (get_complementary(m.color));
}

t_color	checker(t_point p, t_material m)
{
	int	result;

	result = (int)(floor(p.x) + floor(p.y) + floor(p.z));
	if (result % 2 == 0)
		return (m.color);
	return (get_complementary(m.color));
}