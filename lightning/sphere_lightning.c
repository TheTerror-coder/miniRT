/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_lightning.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmohin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:24:07 by lmohin            #+#    #+#             */
/*   Updated: 2024/02/07 10:44:37 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lightning.h"

t_vec	get_normal_sphere(t_sp sphere, t_ray main_ray)
{
	t_vec	normal_sp;

	normal_sp.x = sphere.o.x - (main_ray.o.x + main_ray.len * main_ray.dir.x);
	normal_sp.y = sphere.o.y - (main_ray.o.y + main_ray.len * main_ray.dir.y);
	normal_sp.z = sphere.o.z - (main_ray.o.z + main_ray.len * main_ray.dir.z);
	ft_vectornormalize(&normal_sp, &normal_sp);
	return (normal_sp);
}

t_bool	light_side_test(t_vec normal_obj, t_ray light_ray, t_ray main_ray)
{
	if (ft_vecdotvec(&normal_obj, &light_ray.dir)
		* ft_vecdotvec(&normal_obj, &main_ray.dir) < 0)
	{
		return (__FALSE);
	}
	return (__TRUE);
}

t_bool	sphere_lightning(t_vars *v, t_ray light_ray, int i, int j)
{
	t_vec	normal_vec;
	double	scalar;
	int		color;

	normal_vec = get_normal_sphere(*v->sp[v->ray->obj.index], *v->ray);
	scalar = ft_vecdotvec(&light_ray.dir, &normal_vec);
	if (!light_side_test(normal_vec, *v->ray, light_ray))
	{
		color = amb_color(*v->amb, ft_color(&v->sp[v->ray->obj.index]->rgb));
		my_mlx_pixel_put(v->im, i, j, color);
		return (__TRUE);
	}
	color = enlightened_color(v, light_ray, scalar);
	my_mlx_pixel_put(v->im, i, j, color);
	return (__TRUE);
}
