/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_lightning.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmohin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:27:38 by lmohin            #+#    #+#             */
/*   Updated: 2024/02/04 03:50:38 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lightning.h"

t_bool	plane_lightning(t_vars *v, t_ray light_ray, int i, int j)
{
	t_pl	*plane;
	int	color;
	double	stock_product;
	int	color_stok;

	plane = (v->pl[v->ray->obj.index]);
	if ((ft_vecdotvec(&light_ray.dir, &plane->normal)
			* ft_vecdotvec(&v->ray->dir, &plane->normal) < 0))
	{
		color = ft_color(&plane->rgb);
		v->ray->color = ((color >> 16) & 0xFF) * v->amb->rgb.r * v->amb->ratio / 255;
		v->ray->color <<= 8;
		v->ray->color += ((color >> 8) & 0xFF) * v->amb->rgb.g * v->amb->ratio / 255;
		v->ray->color <<= 8;
		v->ray->color += (color & 0xFF) * v->amb->rgb.b * v->amb->ratio / 255;
		my_mlx_pixel_put(v->im, i, j, v->ray->color);
		return (__TRUE);
	}
	stock_product = ft_vecdotvec(&light_ray.dir, &plane->normal);
	if (stock_product < 0)
		stock_product *= -1;
	stock_product /= (1 + (light_ray.len));
	stock_product *= v->light->ratio;
	color = ft_color(&plane->rgb);
	color_stok = ((color >> 16) & 0xFF) * stock_product + (v->amb->ratio * (v->amb->rgb.r) * ((color >> 16) & 0xFF)) / 255;
	if (color_stok > 255)
		color_stok = 255;
	v->ray->color = color_stok;
	v->ray->color <<= 8;
	color_stok = ((color >> 8) & 0xFF) * stock_product + (v->amb->ratio * (v->amb->rgb.g) * ((color >> 8) & 0xFF)) / 255;
	if (color_stok > 255)
		color_stok = 255;
	v->ray->color += color_stok;
	v->ray->color <<= 8;
	color_stok = (color & 0xFF) * stock_product + (v->amb->ratio * (v->amb->rgb.b) * (color & 0xFF)) / 255;
	if (color_stok > 255)
		color_stok = 255;
	v->ray->color += color_stok;
	my_mlx_pixel_put(v->im,i,j,v->ray->color);
	return (__TRUE);
}
