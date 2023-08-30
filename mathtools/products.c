/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   products.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:30:44 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/25 20:56:02 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mathtools.h"

t_vec	ft_vecdotconst(t_vec *vector, const double k)
{
	t_vec	res;

	res.x = vector->x * k;
	res.y = vector->y * k;
	res.z = vector->z * k;
	return (res);
}

t_vec	ft_vecdotpt(t_vec *vector, t_coord *point)
{
	t_vec	res;

	res.x = vector->x * point->x;
	res.y = vector->y * point->y;
	res.z = vector->z * point->z;
	return (res);
}

double	ft_vecdotvec(t_vec *vec1, t_vec *vec2)
{
	double	res;

	res = (vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z);
	return (res);
}
