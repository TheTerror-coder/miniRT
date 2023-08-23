/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:30:44 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/23 18:35:20 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mathtools.h"

double	ft_vectornorm(t_vec *vector)
{
	return (sqrt(ft_vectornormsqr(vector)));
}

void	ft_setvec_coords(t_vec *vector)
{
	t_coord	pt;

	pt = ft_pointsdiff(&vector->e, &vector->o);
	vector->x = pt.x;
	vector->y = pt.y;
	vector->z = pt.z;
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
