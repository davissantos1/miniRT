/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:02:12 by vitosant          #+#    #+#             */
/*   Updated: 2026/01/20 11:43:34 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "vec4.h"
#include <stdio.h>

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

int	main(void)
{
	t_point		pos = {.x = 0.0, .y = 1.0, .z = 0.0, .w = 1.0};
	t_vec4		vel = {.x = 1.0, .y = 1.0, .z = 0.0, .w = 0.0};
	t_vec4      gravity = {.x = 0.0, .y = -0.1, .z = 0.0, .w = 0.0};
	t_vec4      wind = {.x = -0.01, .y = 0.0, .z = 0.0, .w = 0.0};	
	t_projectile proj = projectile(pos, vel);
	t_environment	env = environment(gravity, wind);

	while (proj.position.y > 0.0)
	{
		printf("X: %lf, Y: %lf\n", proj.position.x, proj.position.y);
		proj = tick(env, proj);
	}
	return (0);
}
