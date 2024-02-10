/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_lightning.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:27:38 by lmohin            #+#    #+#             */
/*   Updated: 2024/02/10 16:57:31 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lightning.h"

t_bool	plane_lightning(t_vars *v, t_ray light_ray, int i, int j)
{
	t_pl	*plane;
	int		color;
	double	stock_product;

	plane = (v->pl[v->ray->obj.index]);
	if ((vecdotvec(&light_ray.dir, &plane->normal)
			* vecdotvec(&v->ray->dir, &plane->normal) < 0))
	{
		color = amb_color(*v->amb, compute_color(&plane->rgb));
		my_mlx_pixel_put(v->im, i, j, color);
		return (__TRUE);
	}
	stock_product = vecdotvec(&light_ray.dir, &plane->normal);
	color = enlightened_color(v, light_ray, stock_product);
	my_mlx_pixel_put(v->im, i, j, color);
	return (__TRUE);
}
