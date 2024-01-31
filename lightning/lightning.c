/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmohin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:22:08 by lmohin            #+#    #+#             */
/*   Updated: 2024/01/31 14:30:37 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lightning.h"

t_bool	test1(t_ray	*light_ray)
{
	light_ray->o.z = 8;
	return (__FALSE);
}

t_bool	lightning(t_vars *v, int i, int j)
{
	int	x;
	int	x2;
	int	type2;
	t_ray	light_ray;
	int	color;
	int	color2;
	double	stock;
	double	ray_len;
	t_vec 	new_vec;

	x2 = v->ray->obj.index;
	type2 = v->ray->obj.type;
	ray_len = v->ray->len;
	light_ray.o.x = v->light->pol.x;
	light_ray.o.y = v->light->pol.y;
	light_ray.o.z = v->light->pol.z; 
	light_ray.dir.x = v->cam->pov.x - v->light->pol.x + v->ray->len * v->ray->dir.x;
	light_ray.dir.y = v->cam->pov.y - v->light->pol.y + v->ray->len * v->ray->dir.y;
	light_ray.dir.z = v->cam->pov.z - v->light->pol.z + v->ray->len * v->ray->dir.z;
	ft_vectornormalize(&light_ray.dir, &light_ray.dir);

	x = -1;
	light_ray.len = -1;
	while (v->sp && v->sp[++x])
		ft_ray_inter_sp(&light_ray, v->sp[x], x);
	x = -1;
	while (v->pl && v->pl[++x])
		ft_ray_inter_pl(&light_ray, v->pl[x], x);
	x = -1;
	while (v->cy && v->cy[++x])
		ft_ray_inter_cy(&light_ray, v->cy[x]);
	if ((light_ray.len * light_ray.len - ft_sq(v->cam->pov.x - v->light->pol.x + v->ray->len * v->ray->dir.x) 
		- ft_sq(v->cam->pov.y - v->light->pol.y + v->ray->len * v->ray->dir.y)
		- ft_sq(v->cam->pov.z - v->light->pol.z + v->ray->len * v->ray->dir.z) >= 0.00001) ||
		(light_ray.len * light_ray.len - ft_sq(v->cam->pov.x - v->light->pol.x + v->ray->len * v->ray->dir.x)
 	    - ft_sq(v->cam->pov.y - v->light->pol.y + v->ray->len * v->ray->dir.y)
 	            - ft_sq(v->cam->pov.z - v->light->pol.z + v->ray->len * v->ray->dir.z) <= -0.00001))
	{
		v->ray->color = v->amb->rgb.r * v->amb->ratio;
		v->ray->color<<=8;
		v->ray->color += v->amb->rgb.g * v->amb->ratio;
		v->ray->color<<=8;
		v->ray->color += v->amb->rgb.b * v->amb->ratio;
		my_mlx_pixel_put(v->im, i, j, v->ray->color);
		return (__TRUE);
	}
	if (type2 == 0)
	{
		stock = light_ray.dir.x * v->pl[x2]->normal.x + light_ray.dir.y * v->pl[x2]->normal.y + light_ray.dir.z * v->pl[x2]->normal.z;
		if (stock * (v->ray->dir.x * v->pl[x2]->normal.x + v->ray->dir.y * v->pl[x2]->normal.y + v->pl[x2]->normal.z * v->ray->dir.z) < 0)
		{
			v->ray->color = v->amb->rgb.r * v->amb->ratio;
			v->ray->color <<=8;
			v->ray->color += v->amb->rgb.g * v->amb->ratio;
			v->ray->color <<=8;
			v->ray->color += v->amb->rgb.b * v->amb->ratio;
			my_mlx_pixel_put(v->im, i, j, v->ray->color);
			return (__TRUE);
		}
	//	printf("%f - %f\n", stock, v->ray.dir.x * v->pl[x2]->normal.x + v->ray.dir.y * v->pl[x2]->normal.y + v->pl[x2]->normal.z * v->ray.dir.z);
		if (stock < 0)
			stock *= -1;
		stock /= ft_sq(light_ray.len);
		if (stock > 1)
			stock = 1;
		color = 0;
		color2 = ft_color(&v->pl[x2]->rgb);
		color += ((color2 >> 16) & 0xFF) * stock * v->light->ratio + v->amb->rgb.r * v->amb->ratio;
		color <<= 8;
		color2 = ft_color(&v->pl[x2]->rgb);
		color += ((color2 >> 8) & 0xFF) * stock * v->light->ratio + v->amb->rgb.g * v->amb->ratio;
		color <<= 8;
		color += (ft_color(&v->pl[x2]->rgb) & 0xFF) * stock * v->light->ratio + v->amb->rgb.b * v->amb->ratio;
		v->ray->color = color;
	}
//


//
	if (type2 == 2)
	{
		new_vec.x = v->sp[x2]->o.x - (v->cam->pov.x + v->ray->len * v->ray->dir.x);
		new_vec.y = v->sp[x2]->o.y - (v->cam->pov.y + v->ray->len * v->ray->dir.y);
		new_vec.z = v->sp[x2]->o.z - (v->cam->pov.z + v->ray->len * v->ray->dir.z);
		ft_vectornormalize(&new_vec, &new_vec);
		stock = light_ray.dir.x * new_vec.x + light_ray.dir.y * new_vec.y + light_ray.dir.z * new_vec.z;
		if (stock * (v->ray->dir.x * new_vec.x + v->ray->dir.y * new_vec.y + v->ray->dir.z * new_vec.z) < 0)
		{
			v->ray->color = v->amb->rgb.r * v->amb->ratio;
			v->ray->color <<= 8;
			v->ray->color += v->amb->rgb.g * v->amb->ratio;
			v->ray->color <<= 8;
			v->ray->color += v->amb->rgb.b * v->amb->ratio;
			my_mlx_pixel_put(v->im, i, j, v->ray->color);
			return (__TRUE);
		}
		if (stock < 0)
			stock *= -1;
		stock /= ft_sq(light_ray.len);
		if (stock > 1)
			stock = 1;
		color2 = ft_color(&v->sp[x2]->rgb);
		color = 0;
		color += ((color2 >> 16) & 0xFF) * stock * v->light->ratio + v->amb->rgb.r * v->amb->ratio;
		color2 = ft_color(&v->sp[x2]->rgb);
		color <<= 8;
		color += ((color2 >> 8) & 0xFF) * stock * v->light->ratio + v->amb->rgb.g * v->amb->ratio;
		color <<= 8;
		color += (ft_color(&v->sp[x2]->rgb) & 0xFF) * stock * v->light->ratio + v->amb->rgb.b * v->amb->ratio;
		v->ray->color = color;
	}
//
	my_mlx_pixel_put(v->im, i, j, v->ray->color);
	return (__TRUE);
}
