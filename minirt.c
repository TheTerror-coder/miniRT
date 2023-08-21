/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:29:22 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/21 23:53:10 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	ft_minirt(t_vars *v)
{
	int	i;
	int	j;

	j = 0;
	while (j < _SIZE_Y)
	{
		i = 0;
		while (i < _SIZE_X)
		{
			ft_ray(v, i, j);
			ft_sphere(v);
			i++;
		}
		j++;
	}
	return (__TRUE);
}

t_bool	ft_ray(t_vars *v, int i, int j)
{
	t_coord	*origin;
	t_coord	end;

	origin = &v->c->pov;
	end.x = i - _SIZE_X / 2.00;
	end.y = j - _SIZE_Y / 2.00;
	end.z = _SIZE_X /(2.00 * tan(ft_degtorad(v->c->fov) / 2.00));
	v->ray.x = end.x - origin->x;
	v->ray.y = end.y - origin->y;
	v->ray.z = end.z - origin->z;
	return (__TRUE);
}