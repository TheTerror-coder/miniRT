/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmohin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 06:28:58 by lmohin            #+#    #+#             */
/*   Updated: 2024/02/09 14:19:33 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lightning.h"

t_bool	is_shadows(t_vars *v, t_ray *light_ray, int i, int j)
{
	int		x;
	double	dist;
	int		color;
	t_bool	inter;
	t_vec	normal;

	x = -1;
	light_ray->len = -1;
	inter = __FALSE;
	while (v->sp && v->sp[++x])
	{
		dist = light_ray->len;
		light_ray->len = -1;
		ft_ray_inter_sp(light_ray, v->sp[x], x);
		if (light_ray->len != -1 && (dist - light_ray->len >= -0.0000000001) && (dist - light_ray->len <= 0.0000000001))
		{
			if (!light_side_test(get_normal_sphere(*v->sp[x], *light_ray), *light_ray, *v->ray))
			{
				normal = get_normal_sphere(*v->sp[x], *light_ray);
				inter = __TRUE;
			}
			else if (light_side_test(normal, *light_ray, *v->ray))
				inter = __TRUE;
		}
		else if (light_ray->len < dist && light_ray->len != -1)
		{
			inter = __FALSE;
			normal = get_normal_sphere(*v->sp[x], *light_ray);
		}
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
		{
			if (!light_side_test(v->pl[x]->normal, *light_ray, *v->ray))
			{
				normal = v->pl[x]->normal;
				inter = __TRUE;
			}
			else if (!light_side_test(normal, *light_ray, *v->ray))
				inter = __TRUE;
		}
		else if (light_ray->len < dist && light_ray->len != -1)
		{
			inter = __FALSE;
			normal = v->pl[x]->normal;
		}
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
		ft_ray_inter_cy(light_ray, v->cy[x], x);
		if (light_ray->len != -1 && (dist - light_ray->len >= -0.0000000001) && (dist - light_ray->len <= 0.0000000001))
		{
			if (!light_side_test(get_normal_cylinder(*v->cy[x], *light_ray), *light_ray, *v->ray))
			{
				normal = get_normal_cylinder(*v->cy[x], *light_ray);
				inter = __TRUE;
			}
			else if (!light_side_test(normal, *light_ray, *v->ray))
				inter = __TRUE;
		}
		else if (light_ray->len < dist && light_ray->len != -1)
		{
			inter = __FALSE;
			normal = get_normal_cylinder(*v->cy[x], *light_ray);
		}
		else if (dist != -1)
		{
			light_ray->len = dist;
		}
	}
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
}
