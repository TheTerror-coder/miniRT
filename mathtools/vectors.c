/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:30:44 by TheTerror         #+#    #+#             */
/*   Updated: 2023/09/06 22:25:46 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mathtools.h"

double	ft_vectornorm(t_vec *vector)
{
	return (sqrt(ft_vectornormsqr(vector)));
}

void	ft_setvec_coords(t_vec *vector)
{
	ft_pointsdiff(&vector->e, &vector->o, vector);
}

double	ft_vectornormsqr(t_vec *vector)
{
	double	x2;
	double	y2;
	double	z2;
	double	res;

	x2 = vector->x * vector->x;
	y2 = vector->y * vector->y;
	z2 = vector->z * vector->z;
	res = x2 + y2 + z2;
	return (res);
}

void	ft_vectornormalize(t_vec *vec, t_vec *normvec)
{
	double	norm;
	t_vec	res;

	norm = ft_vectornorm(vec);
	if (!norm)
		norm = 1;
	res.x = vec->x / norm;
	res.y = vec->y / norm;
	res.z = vec->z / norm;
	normvec->x = res.x;
	normvec->y = res.y;
	normvec->z = res.z;
}
