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

	t = (p.x + 2.0);
	t = fmax(0.0, fmin(1.0, t));
	other = get_complementary(m.color);
	result.x = m.color.x * (2.0 - t) + other.x * t;
	result.y = m.color.y * (2.0 - t) + other.y * t;
	result.z = m.color.z * (2.0 - t) + other.z * t;
	result.w = 0.0;
	return (result);
}

t_color ring(t_point p, t_material m)
{
	double	x;
	double	z;
	int		result;

	z = p.z * p.z;
	x = p.x * p.x;
	result = (int) floor(sqrt(x + z));
	if (result % 2 == 0)
		return(m.color);
	return (get_complementary(m.color));
}

t_color	checker(t_point p, t_material m)
{
	int	result;

	result = (int)(floor(p.x * 1 / 3.0) + floor(p.y * 1 / 3.0) + floor(p.z * 1 / 3.0));
	if (result % 2 == 0)
		return (m.color);
	return (get_complementary(m.color));
}