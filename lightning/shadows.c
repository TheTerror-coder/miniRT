/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmohin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 06:28:58 by lmohin            #+#    #+#             */
/*   Updated: 2024/02/06 17:18:04 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lightning.h"

t_bool	is_shadows(t_vars *v, t_ray *light_ray, int i, int j)
{
	long long int	x;
	double	dist;
	int	color;
//	int	type1;
//	int	index1;
	t_bool	inter;

	x = -1;
	light_ray->len = -1;
	inter = __FALSE;
	while (v->sp && v->sp[++x])
	{
		dist = light_ray->len;
		light_ray->len = -1;
		ft_ray_inter_sp(light_ray, v->sp[x], x);
		if (light_ray->len != -1 && (dist - light_ray->len >= -0.0000000001) && (dist - light_ray->len <= 0.0000000001))
			inter = __TRUE;
		else if (light_ray->len < dist && light_ray->len != -1)
			inter = __FALSE;
		else if (dist != -1)
		{
			light_ray->len = dist;
		}
	}
	x = -1;
	while (v->pl && v->pl[++x])
	{
		dist = light_ray->len;
		light_ray->len = -1;
		ft_ray_inter_pl(light_ray, v->pl[x], x);
		if (light_ray->len != -1 && ((dist - light_ray->len) >= -0.0000000001) && ((dist - light_ray->len) <= 0.0000000001))
			inter = __TRUE;
		else if (light_ray->len < dist && light_ray->len != -1)
			inter = __FALSE;
		else if (dist != -1)
		{
			light_ray->len = dist;
		}
	}
	x = -1;
	while (v->cy && v->cy[++x])
	{
		dist = light_ray->len;
		light_ray->len = -1;
		ft_ray_inter_cy(light_ray, v->cy[x]);
		if (light_ray->len != -1 && (dist - light_ray->len >= -0.0000000001) && (dist - light_ray->len <= 0.0000000001))
			inter = __TRUE;
		else if (light_ray->len < dist && light_ray->len != -1)
			inter = __FALSE;
		else if (dist != -1)
		{
			light_ray->len = dist;
		}
	}
/*	dist = light_ray->len;
	type1 = light_ray->obj.type;
	index1 = light_ray->obj.index;
	light_ray->len = -1;
	x = -1;
	inter = __FALSE;
	while (v->sp && v->sp[++x])
	{
		if (x != index1 || type1 != __SPHERE)
			ft_ray_inter_sp(light_ray, v->sp[x], x);
		if (((light_ray->len - dist <= 0.000001) && (light_ray->len - dist >= -0.000001)) && (x != index1 || type1 != __SPHERE))
			inter = __TRUE;
	}
	x = -1;
	while (v->pl && v->pl[++x])
	{
		if (x != index1 || type1 != __PLANE)
			ft_ray_inter_pl(light_ray, v->pl[x], x);
		if (((light_ray->len - dist <= 0.000001) && (light_ray->len - dist >= -0.000001)) && (x != index1 || type1 != __PLANE))
			inter = __TRUE;
	}
	x = - 1;
	while (v->cy && v->cy[++x])
	{
		if (x != index1 || type1 != __CYLINDER)
			ft_ray_inter_cy(light_ray, v->cy[x]);
		if (((light_ray->len - dist <= 0.000001) && (light_ray->len - dist >= -0.000001)) && (x != index1 || type1 != __CYLINDER))
			inter = __TRUE;
	}
	light_ray->len = dist;*/
	dist = ft_sq(light_ray->len)
		- ft_sq(v->cam->pov.x - v->light->pol.x + v->ray->len * v->ray->dir.x)
		- ft_sq(v->cam->pov.y - v->light->pol.y + v->ray->len * v->ray->dir.y)
		- ft_sq(v->cam->pov.z - v->light->pol.z + v->ray->len * v->ray->dir.z);
	if (dist >= 0.0000000001 || dist <= -0.0000000001 || (inter == __TRUE && v->ray->len != -1))
	{
		color = amb_color(*v->amb, v->ray->color);
		my_mlx_pixel_put(v->im, i, j, color);
		return (__TRUE);
	}
	else
	{
		return (__FALSE);
	}
	(void) inter;
}
