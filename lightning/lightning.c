/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmohin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:22:08 by lmohin            #+#    #+#             */
/*   Updated: 2024/02/08 17:26:19 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lightning.h"

t_bool	set_light_ray(t_vars *v, t_ray	*light_ray)
{
	light_ray->o.x = v->light->pol.x;
	light_ray->o.y = v->light->pol.y;
	light_ray->o.z = v->light->pol.z;
	light_ray->dir.x = v->cam->pov.x - v->light->pol.x;
	light_ray->dir.x += v->ray->len * v->ray->dir.x;
	light_ray->dir.y = v->cam->pov.y - v->light->pol.y;
	light_ray->dir.y += v->ray->len * v->ray->dir.y;
	light_ray->dir.z = v->cam->pov.z - v->light->pol.z;
	light_ray->dir.z += v->ray->len * v->ray->dir.z;
	ft_vectornormalize(&light_ray->dir, &light_ray->dir);
	return (__TRUE);
}

t_bool	lightning(t_vars *v, int i, int j)
{
	t_ray	light_ray;

	set_light_ray(v, &light_ray);
	if (is_shadows(v, &light_ray, i, j))
		return (__TRUE);
	if (v->ray->obj.type == __PLANE)
		return (plane_lightning(v, light_ray, i, j));
	if (v->ray->obj.type == __SPHERE)
	{
		return (sphere_lightning(v, light_ray, i, j));
	}
	if (v->ray->obj.type == __CYLINDER)
		return (cylinder_lightning(v, light_ray, i, j));
	my_mlx_pixel_put(v->im, i, j, v->ray->color);
	return (__TRUE);
}
