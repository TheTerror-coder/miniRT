/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmohin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 06:28:58 by lmohin            #+#    #+#             */
/*   Updated: 2024/02/02 07:48:21 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lightning.h"

t_bool	is_shadows(t_vars *v, t_ray *light_ray, int i, int j)
{
	long long int	x;
	double	dist;
	int	color;

	x = -1;
	light_ray->len = -1;
	while (v->sp && v->sp[++x])
		ft_ray_inter_sp(light_ray, v->sp[x], x);
	x = -1;
	while (v->pl && v->pl[++x])
		ft_ray_inter_pl(light_ray, v->pl[x], x);
	x = -1;
	while (v->cy && v->cy[++x])
		ft_ray_inter_cy(light_ray, v->cy[x]);
	dist = ft_sq(light_ray->len)
		- ft_sq(v->cam->pov.x - v->light->pol.x + v->ray->len * v->ray->dir.x)
		- ft_sq(v->cam->pov.y - v->light->pol.y + v->ray->len * v->ray->dir.y)
		- ft_sq(v->cam->pov.z - v->light->pol.z + v->ray->len * v->ray->dir.z);
	if (dist >= 0.0000000001 || dist <= -0.0000000001)
	{
		color = v->ray->color;
		v->ray->color = (v->amb->rgb.r + ((color >> 16) & 0xFF)) * v->amb->ratio / 2;
		v->ray->color <<= 8;
		v->ray->color += (v->amb->rgb.g + ((color >> 8) & 0xFF)) * v->amb->ratio / 2;
		v->ray->color <<= 8;
		v->ray->color += (v->amb->rgb.b + (color & 0xFF)) * v->amb->ratio / 2;
		my_mlx_pixel_put(v->im, i, j, v->ray->color);
		return (__TRUE);
	}
	return (__FALSE);
}
