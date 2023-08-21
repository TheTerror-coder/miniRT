/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtractions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:30:44 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/18 18:43:09 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mathtools.h"

t_coord	*ft_pointsdiff(t_coord *end, t_coord *origin)
{
	t_coord	res;

	res.x = end->x - origin->x;
	res.y = end->y - origin->y;
	res.z = end->z - origin->z;
	return (&res);
}
