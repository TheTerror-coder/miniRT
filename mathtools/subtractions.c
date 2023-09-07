/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtractions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:30:44 by TheTerror         #+#    #+#             */
/*   Updated: 2023/09/06 22:01:56 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mathtools.h"

void	ft_pointsdiff(t_coord *end, t_coord *origin, t_vec *res)
{
	t_coord	r;

	r.x = end->x - origin->x;
	r.y = end->y - origin->y;
	r.z = end->z - origin->z;
	res->x = r.x;
	res->y = r.y;
	res->z = r.z;
}
