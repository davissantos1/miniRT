/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ppm_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:36:18 by vitosant          #+#    #+#             */
/*   Updated: 2026/01/20 18:18:43 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "vec4.h"

#define EPSILON 1e-4

typedef struct	s_projectile
{
	t_point		position;
	t_vec4		velocity;
}	t_projectile;

typedef struct	s_environment
{
	t_vec4	gravity;
	t_vec4	wind;
}	t_environment;

t_projectile tick(t_environment env, t_projectile proj)
{
	proj.position = vec4_plus(proj.position, proj.velocity);
	proj.velocity = vec4_plus(proj.velocity, env.gravity);
	proj.velocity = vec4_plus(proj.velocity, env.wind);
	return (proj);
}

t_projectile	projectile(t_vec4 pos, t_vec4 vel)
{
	t_projectile proj;

	proj.position = pos;
	proj.velocity = vel;
	return (proj);
}

t_environment environment(t_vec4 gravity, t_vec4 wind)
{
	t_environment	env;

	env.wind = wind;
	env.gravity = gravity;
	return (env);
}

int is_painted(int x, int y, t_projectile proj, t_environment env)
{
	double	target_x = (x * 30.34) / 990.0;
	double	target_y = 18.1 - ((y * 18.1) / 550.0); // Y é invertido na tela

	while (proj.position.y >= 0) 
	{
		if (fabs(target_y - proj.position.y) <= 0.3
			&& fabs(target_x - proj.position.x) <= 0.3)
			return (255);
		proj = tick(env, proj);
	}
	return (0);
}

int	main(void)
{
	t_color pallet = {.x = 255.0, .y = 0.0, .z = 0.0, .w = 0.0};
	printf("P3\n900 550\n255\n");
	t_point         pos = {.x = 0.0, .y = 1.0, .z = 0.0, .w = 1.0};
	t_vec4          vel = {.x = 1.0, .y = 1.8, .z = 0.0, .w = 0.0};
	t_vec4      gravity = {.x = 0.0, .y = -0.1, .z = 0.0, .w = 0.0};
	t_vec4      wind = {.x = -0.01, .y = 0.0, .z = 0.0, .w = 0.0};  
	t_projectile proj = projectile(pos, vel);
	t_environment   env = environment(gravity, wind);

	vel = vec4_unit_vector(vel);
	vel = vec4_scale(11.25, vel);
	for (int y = 0; y < 550; y++)
	{
		for (int x = 0; x < 900; x++)
		{
			printf("%i 0 0", is_painted(x, y, proj, env));
			if (y < 550 - 1 || x < 900 - 1)
				printf(" ");
		}
		printf("\n");
	}
	//	while (proj.position.y > 0.0)
		//{
		// printf("X: %lf, Y: %lf\n", proj.position.x, proj.position.y);
				//     proj = tick(env, proj);
				//	}
	return (0);
}
