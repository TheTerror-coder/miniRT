/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmohin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 06:28:58 by lmohin            #+#    #+#             */
/*   Updated: 2024/02/13 02:19:28 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lightning.h"

t_bool	set_inter(t_vec *normal, t_ray light_ray, t_vec normal_obj, t_ray ray)
{
	if (!light_side_test(normal_obj, light_ray, ray))
	{
		*normal = normal_obj;
		return (__TRUE);
	}
	else if (!light_side_test(*normal, light_ray, ray))
		return (__TRUE);
	return (__FALSE);
}

void	is_sp_shadow(t_vars *v, t_ray *light_ray, t_bool *inter, t_vec *normal)
{
	size_t	x;
	double	dist;

	x = 0;
	while (v->sp && v->sp[x])
	{
		dist = light_ray->len;
		light_ray->len = -1;
		ray_inter_sp(light_ray, v->sp[x], x);
		if (light_ray->len != -1 && (dist - light_ray->len >= -0.0000000001)
			&& (dist - light_ray->len <= 0.0000000001))
		{
			if (set_inter(normal, *light_ray,
					get_normal_sphere(*v->sp[x], *light_ray), *v->ray))
				*inter = __TRUE;
		}
		else if ((light_ray->len < dist || dist == -1) && light_ray->len != -1)
		{
			*inter = __FALSE;
			*normal = get_normal_sphere(*v->sp[x], *light_ray);
		}
		else if (dist != -1)
			light_ray->len = dist;
		x++;
	}
}

void	is_pl_shadow(t_vars *v, t_ray *light_ray, t_bool *inter, t_vec *normal)
{
	size_t		x;
	double		dist;

	x = 0;
	while (v->pl && v->pl[x])
	{
		dist = light_ray->len;
		light_ray->len = -1;
		ray_inter_pl(light_ray, v->pl[x], x);
		if (light_ray->len != -1 && ((dist - light_ray->len) >= -0.0000000001)
			&& ((dist - light_ray->len) <= 0.0000000001))
		{
			if (set_inter(normal, *light_ray, v->pl[x]->normal, *v->ray))
				*inter = __TRUE;
		}
		else if ((light_ray->len < dist || dist == -1) && light_ray->len != -1)
		{
			*inter = __FALSE;
			*normal = v->pl[x]->normal;
		}
		else if (dist != -1)
			light_ray->len = dist;
		x++;
	}
}

void	is_cy_shadow(t_vars *v, t_ray *light_ray, t_bool *inter, t_vec *normal)
{
	size_t	x;
	double	dist;

	x = 0;
	while (v->cy && v->cy[x])
	{
		dist = light_ray->len;
		light_ray->len = -1;
		ray_inter_cy(light_ray, v->cy[x], x);
		if (light_ray->len != -1 && (dist - light_ray->len >= -0.0000000001)
			&& (dist - light_ray->len <= 0.0000000001))
		{
			if (set_inter(normal, *light_ray,
					get_normal_cylinder(*v->cy[x], *light_ray), *v->ray))
				*inter = __TRUE;
		}
		else if ((light_ray->len < dist || dist == -1) && light_ray->len != -1)
		{
			*inter = __FALSE;
			*normal = get_normal_cylinder(*v->cy[x], *light_ray);
		}
		else if (dist != -1)
			light_ray->len = dist;
		x++;
	}
}

t_bool	is_shadows(t_vars *v, t_ray *light_ray, int i, int j)
{
	double	dist;
	int		color;
	t_bool	inter;
	t_vec	normal;

	light_ray->len = -1;
	inter = __FALSE;
	is_sp_shadow(v, light_ray, &inter, &normal);
	is_pl_shadow(v, light_ray, &inter, &normal);
	is_cy_shadow(v, light_ray, &inter, &normal);
	dist = __sq(light_ray->len)
		- __sq(v->cam->pov.x - v->light->pol.x + v->ray->len * v->ray->dir.x)
		- __sq(v->cam->pov.y - v->light->pol.y + v->ray->len * v->ray->dir.y)
		- __sq(v->cam->pov.z - v->light->pol.z + v->ray->len * v->ray->dir.z);
	if (dist >= 0.0000001 || dist <= -0.0000001
		|| (inter == __TRUE && v->ray->len != -1))
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
