/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmohin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:22:08 by lmohin            #+#    #+#             */
/*   Updated: 2024/02/04 03:58:54 by lmohin           ###   ########.fr       */
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
	int	x2;
	t_ray	light_ray;
	int	color;
	int	color2;
	double	stock;
	t_vec 	new_vec;

	x2 = v->ray->obj.index;
	set_light_ray(v, &light_ray);
	if (is_shadows(v, &light_ray, i, j))
		return (__TRUE);
	if (v->ray->obj.type == __PLANE)
		return (plane_lightning(v, light_ray, i, j));
//


//
	if (v->ray->obj.type == __SPHERE)
	{
		new_vec.x = v->sp[x2]->o.x - (v->cam->pov.x + v->ray->len * v->ray->dir.x);
		new_vec.y = v->sp[x2]->o.y - (v->cam->pov.y + v->ray->len * v->ray->dir.y);
		new_vec.z = v->sp[x2]->o.z - (v->cam->pov.z + v->ray->len * v->ray->dir.z);
		ft_vectornormalize(&new_vec, &new_vec);
		stock = light_ray.dir.x * new_vec.x + light_ray.dir.y * new_vec.y + light_ray.dir.z * new_vec.z;
		if (stock * (v->ray->dir.x * new_vec.x + v->ray->dir.y * new_vec.y + v->ray->dir.z * new_vec.z) < 0)
		{
			color2 = ft_color(&v->sp[x2]->rgb);
			v->ray->color = v->amb->rgb.r * v->amb->ratio * ((color2 >> 16) & 0xFF) / 255;
			v->ray->color <<= 8;
			v->ray->color += v->amb->rgb.g * v->amb->ratio * ((color2 >> 8) & 0xFF) / 255;
			v->ray->color <<= 8;
			v->ray->color += v->amb->rgb.b * v->amb->ratio * (color2 & 0xFF) / 255;
			my_mlx_pixel_put(v->im, i, j, v->ray->color);
			return (__TRUE);
		}
		if (stock < 0)
			stock *= -1;
		stock /= (1 + light_ray.len);
		stock *= v->light->ratio;
		color2 = ft_color(&v->sp[x2]->rgb);
		color = (((color2 >> 16) & 0xFF) * stock + ((color2 >> 16 & 0xFF) * v->amb->rgb.r / 255) * v->amb->ratio);
		if (color > 255)
			color = 255;
		v->ray->color = color;
		v->ray->color <<= 8;
		color = (((color2 >> 8) & 0xFF) * stock + ((color2 >> 8 & 0xFF) * v->amb->rgb.g / 255) * v->amb->ratio);
		if (color > 255)
			color = 255;
		v->ray->color += color;
		v->ray->color <<= 8;
		color = ((color2 & 0xFF) * stock + ((color2 & 0xFF) * v->amb->rgb.b / 255) * v->amb->ratio);
		if (color > 255)
			color = 255;
		v->ray->color += color;
	}
//
	my_mlx_pixel_put(v->im, i, j, v->ray->color);
	return (__TRUE);
}
