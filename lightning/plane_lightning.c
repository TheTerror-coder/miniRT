/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_lightning.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmohin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:27:38 by lmohin            #+#    #+#             */
/*   Updated: 2024/02/06 17:19:26 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lightning.h"

t_bool	plane_lightning(t_vars *v, t_ray light_ray, int i, int j)
{
	t_pl	*plane;
	int		color;
	double	stock_product;

	plane = (v->pl[v->ray->obj.index]);
	if ((ft_vecdotvec(&light_ray.dir, &plane->normal)
			* ft_vecdotvec(&v->ray->dir, &plane->normal) < 0))
	{
		color = amb_color(*v->amb, ft_color(&plane->rgb));
		my_mlx_pixel_put(v->im, i, j, color);
		return (__TRUE);
	}
	stock_product = ft_vecdotvec(&light_ray.dir, &plane->normal);
	color = enlightened_color(v, light_ray, stock_product);
	my_mlx_pixel_put(v->im, i, j, color);
	return (__TRUE);
}
