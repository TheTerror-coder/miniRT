/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmohin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:21:42 by lmohin            #+#    #+#             */
/*   Updated: 2024/02/06 16:19:05 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lightning.h"

int	amb_color(t_amb amb, int obj_color)
{
	int	color;

	color = amb.rgb.r * amb.ratio * ((obj_color >> 16) & 0xFF) / 255;
	color <<= 8;
	color += amb.rgb.g * amb.ratio * ((obj_color >> 8) & 0xFF) / 255;
	color <<= 8;
	color += amb.rgb.b * amb.ratio * (obj_color & 0xFF) / 255;
	return (color);
}

int	enlightened_color(t_vars *v, t_ray light_ray, double scalar)
{
	double	color;
	int		stock;

	if (scalar < 0)
		scalar *= -1;
	scalar /= (1 + light_ray.len);
	scalar *= v->light->ratio;
	color = (v->ray->color >> 16) & 0xFF;
	color *= scalar + v->amb->rgb.r / 255 * v->amb->ratio;
	if (color > 255)
		color = 255;
	stock = color;
	stock <<= 8;
	color = (v->ray->color >> 8) & 0xFF;
	color *= scalar + v->amb->rgb.g / 255 * v->amb->ratio;
	if (color > 255)
		color = 255;
	stock += (int) color;
	stock <<= 8;
	color = v->ray->color & 0xFF;
	color *= scalar + v->amb->rgb.b / 255 * v->amb->ratio;
	if (color > 255)
		color = 255;
	stock += (int) color;
	return (stock);
}
