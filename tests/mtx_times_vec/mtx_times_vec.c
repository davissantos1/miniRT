
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_times_vec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:20:01 by vitosant          #+#    #+#             */
/*   Updated: 2026/02/04 11:22:06 by vitosant         ###    ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mtx4.h"
#include "vec4.h"

int main(void)
{
	t_matrix4	transf;
	t_vec4		vec;
	t_vec4		result;

	vec.x = -3;
	vec.y = 4;
	vec.z = 5;
	vec.w = 0;
	transf = mtx4_identity();
	transf.mtx[0][3] = 5;
	transf.mtx[1][3] = -3;
	transf.mtx[2][3] = 2;
	result = vec4_multi_mtx4(transf, vec);
	printf("====MULTIPLICANDO VETORES E MATRIZES====\n");
	printf("%.2lf\n", vec.x);
	printf("%.2lf\n", vec.y);
	printf("%.2lf\n", vec.z);
	printf("%.2lf\n", vec.w);
	printf("===========MULTIPLICANDO MATRIZES========\n");
	t_matrix4	fac1;
	t_matrix4	fac2;
	t_matrix4	prod;

	fac2 = mtx4_identity();
	for (int i = 0; i < 16; i++)
		fac1.data[i] = 3;
	fac1.data[2] = 2;
	fac1.data[3] = 2;
	fac1.data[7] = 2;
	fac1.data[15] = 2;
	prod = mtx4_times(fac1, fac2);
	print_mtx(fac1);
	printf("X\n");
	print_mtx(fac2);
	printf(" =\n");
	print_mtx(prod);
	return (0);
}
