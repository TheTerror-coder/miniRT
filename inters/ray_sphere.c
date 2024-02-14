/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:19:01 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/13 17:57:31 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inters.h"

double	ray_inter_sp_op(t_ray *ray, t_sp *sp);

t_bool	ray_inter_sp(t_ray *ray, t_sp *sp, int x)
{
	double	s;

	(void) x;
	s = ray_inter_sp_op(ray, sp);
	if (assess_color(ray, s))
	{
		ray->obj.type = __SPHERE;
		ray->obj.index = x;
		return (ray->color = compute_color(&sp->rgb), __TRUE);
	}
	return (__FALSE);
}

t_bool	assess_color(t_ray *ray, double len_found)
{
	if (ray->len < 0)
	{
		if (len_found >= 0)
		{
			ray->len = len_found;
			return (__TRUE);
		}
	}
	if (len_found >= 0)
	{
		if (len_found - ray->len <= -0.00000000001)
		{
			ray->len = len_found;
			return (__TRUE);
		}
	}
	return (__FALSE);
}

double	ray_inter_sp_op(t_ray *ray, t_sp *sp)
{
	t_spvars	vars;

	vars.a = __sq(ray->dir.x) + __sq(ray->dir.y) + __sq(ray->dir.z);
	vars.b = 2.00 * ray->dir.x * (ray->o.x - sp->o.x) + \
		2.00 * ray->dir.y * (ray->o.y - sp->o.y) + \
		2.00 * ray->dir.z * (ray->o.z - sp->o.z);
	vars.c = __sq(ray->o.x - sp->o.x) + \
		__sq(ray->o.y - sp->o.y) + \
		__sq(ray->o.z - sp->o.z) - \
		__sq(sp->d / 2.00);
	vars.delta = __sq(vars.b) - (4 * vars.a * vars.c);
	if (vars.delta < 0)
		return (vars.delta);
	vars.s1 = (-vars.b - __sqrt(vars.delta)) / (2 * vars.a);
	vars.s2 = (-vars.b + __sqrt(vars.delta)) / (2 * vars.a);
	return (assess_the_solution(vars.s1, vars.s2));
}

double	assess_the_solution(double s1, double s2)
{
	if (s1 >= 0 && s2 >= 0)
	{
		if (s1 < s2)
			return (s1);
		else
			return (s2);
	}
	if (s1 >= s2)
		return (s1);
	return (s2);
}
