/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_lightning.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmohin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:06:58 by lmohin            #+#    #+#             */
/*   Updated: 2024/02/08 17:04:27 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lightning.h"

t_bool	is_cylinder_bottom(t_cy cylinder, t_ray main_ray, t_vec *normal_cy)
{
	double	dist_center;

	dist_center = ft_sq(main_ray.o.x + main_ray.len * main_ray.dir.x - (cylinder.o.x + cylinder.h / 2 * (-1) * cylinder.axis.x));
	dist_center += ft_sq(main_ray.o.y + main_ray.len * main_ray.dir.y - (cylinder.o.y + cylinder.h / 2 * (-1) * cylinder.axis.y));
	dist_center += ft_sq(main_ray.o.z + main_ray.len * main_ray.dir.z - (cylinder.o.z + cylinder.h / 2 * (-1) * cylinder.axis.z));
	if (dist_center <= ft_sq(cylinder.r))
	{
		normal_cy->x = -1 * cylinder.axis.x;
		normal_cy->y = -1 * cylinder.axis.y;
		normal_cy->z = -1 * cylinder.axis.z;
		return (__TRUE);
	}
	return (__FALSE);
}

t_bool	is_cylinder_top(t_cy cylinder, t_ray main_ray, t_vec *normal_cy)
{
	double	dist_top_center;

	dist_top_center = ft_sq(main_ray.o.x + main_ray.len * main_ray.dir.x - (cylinder.o.x + cylinder.h / 2 * cylinder.axis.x));
	dist_top_center += ft_sq(main_ray.o.y + main_ray.len * main_ray.dir.y - (cylinder.o.y + cylinder.h / 2 * cylinder.axis.y));
	dist_top_center += ft_sq(main_ray.o.z + main_ray.len * main_ray.dir.z - (cylinder.o.z + cylinder.h / 2 * cylinder.axis.z));
	if (dist_top_center <= ft_sq(cylinder.r))
	{
		normal_cy->x = cylinder.axis.x;
		normal_cy->y = cylinder.axis.y;
		normal_cy->z = cylinder.axis.z;
		return (__TRUE);
	}
	return (__FALSE);
}

t_vec	get_normal_cylinder(t_cy cylinder, t_ray main_ray)
{
	t_vec	normal_cy;
	double	dist_center;

	if (is_cylinder_bottom(cylinder, main_ray, &normal_cy))
		return (normal_cy);
	dist_center = ft_sq(main_ray.o.x + main_ray.len 
			* main_ray.dir.x - (cylinder.o.x + cylinder.h / 2 * (-1) * cylinder.axis.x));
	dist_center += ft_sq(main_ray.o.y + main_ray.len 
			* main_ray.dir.y - (cylinder.o.y + cylinder.h / 2 * (-1) * cylinder.axis.y));
	dist_center += ft_sq(main_ray.o.z + main_ray.len 
			* main_ray.dir.z - (cylinder.o.z + cylinder.h / 2 * (-1) * cylinder.axis.z));
	if (is_cylinder_top(cylinder, main_ray, &normal_cy))
		return (normal_cy);
	normal_cy.x = main_ray.o.x + main_ray.len * main_ray.dir.x;
	normal_cy.x -= cylinder.o.x + sqrt(dist_center - ft_sq(cylinder.r)) * cylinder.axis.x;
	normal_cy.y = main_ray.o.y + main_ray.len * main_ray.dir.y;
	normal_cy.y -= cylinder.o.y + sqrt(dist_center - ft_sq(cylinder.r)) * cylinder.axis.y;
	normal_cy.z = main_ray.o.z + main_ray.len * main_ray.dir.z;
	normal_cy.z -= cylinder.o.z + sqrt(dist_center - ft_sq(cylinder.r)) * cylinder.axis.z;
	ft_vectornormalize(&normal_cy, &normal_cy);
	return (normal_cy);
}

t_bool	cylinder_lightning(t_vars *v, t_ray light_ray, int i, int j)
{
	t_vec	normal_vec;	
	double	scalar;
	int		color;

	normal_vec = get_normal_cylinder(*v->cy[v->ray->obj.index], *v->ray);
	scalar = ft_vecdotvec(&light_ray.dir, &normal_vec);
	if (!light_side_test(normal_vec, *v->ray, light_ray))
	{
		color = amb_color(*v->amb, ft_color(&v->cy[v->ray->obj.index]->rgb));
		my_mlx_pixel_put(v->im, i, j, color);
		return (__TRUE);
	}
	color = enlightened_color(v, light_ray, scalar);
	my_mlx_pixel_put(v->im, i, j, color);
	return (__TRUE);
}
