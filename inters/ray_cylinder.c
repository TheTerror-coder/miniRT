/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:36:07 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/11 15:05:56 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "inters.h"

t_bool	ray_inter_cy_extremities(t_ray *ray, t_cy *cy, int x);
t_bool	setallparameters(t_ray *ray, t_cy *cy, t_params *xp);
double	computeheight_inters(t_ray *ray, t_cy *cy, double t);

t_bool	two_intersections(t_ray *ray, t_cy *cy, t_params *xp, int x);
t_bool	intersection_at_hp1(t_ray *ray, t_cy *cy, t_params *xp, int x);
t_bool	intersection_at_hp2(t_ray *ray, t_cy *cy, t_params *xp, int x);

t_bool	ray_inter_cy(t_ray *ray, t_cy *cy, int x)
{
	t_params	xp;

	vectornormalize(&cy->axis, &cy->axis);
	ray_inter_cy_extremities(ray, cy, x);
	setallparameters(ray, cy, &xp);
	if (xp.delta < 0)
		return (__FALSE);
	xp.hp1 = computeheight_inters(ray, cy, xp.t1);
	xp.hp2 = computeheight_inters(ray, cy, xp.t2);
	if (xp.hp1 < 0 && xp.hp2 < 0)
		return (__FALSE);
	if (xp.hp1 >= 0 && xp.hp2 >= 0)
		return (two_intersections(ray, cy, &xp, x));
	if (xp.hp1 >= xp.hp2)
		return (intersection_at_hp1(ray, cy, &xp, x));
	if (xp.hp2 > xp.hp1)
		return (intersection_at_hp2(ray, cy, &xp, x));
	return (__FALSE);
}

t_bool	two_intersections(t_ray *ray, t_cy *cy, t_params *xp, int x)
{
	double	t;

	t = assess_the_solution(xp->t1, xp->t2);
	if (assess_color(ray, t))
	{
		ray->obj.type = __CYLINDER;
		ray->obj.index = x;
		return (ray->color = compute_color(&cy->rgb), __TRUE);
	}
	return (__FALSE);
}

t_bool	intersection_at_hp1(t_ray *ray, t_cy *cy, t_params *xp, int x)
{
	if (assess_color(ray, xp->t1))
	{
		ray->obj.type = __CYLINDER;
		ray->obj.index = x;
		return (ray->color = compute_color(&cy->rgb), __TRUE);
	}
	return (__FALSE);
}

t_bool	intersection_at_hp2(t_ray *ray, t_cy *cy, t_params *xp, int x)
{
	if (assess_color(ray, xp->t2))
	{
		ray->obj.type = __CYLINDER;
		ray->obj.index = x;
		return (ray->color = compute_color(&cy->rgb), __TRUE);
	}
	return (__FALSE);
}
