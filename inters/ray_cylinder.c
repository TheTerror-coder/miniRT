/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:36:07 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/10 17:04:38 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "inters.h"

t_bool	ray_inter_cy_op(t_ray *ray, t_cy *cy, t_params *xp, int x);
t_bool	setallparameters(t_ray *ray, t_cy *cy, t_params *xp);
t_bool	setparams_term1(t_ray *ray, t_cy *cy, t_params *xp);
t_bool	setparams_term2_term3(t_ray *ray, t_params *xp);
double	computeheight_inters(t_ray *ray, t_cy *cy, double t);

t_bool	ray_inter_cy(t_ray *ray, t_cy *cy, int x)
{
	t_params	xp;
// t_rgb	test;
// test.r = 255;
// test.g = 0;
// test.b = 0;
	vectornormalize(&cy->axis, &cy->axis);
	ray_inter_cy_extremities(ray, cy, x);
	setallparameters(ray, cy, &xp);
	if (xp.delta < 0)
		return (__FALSE);
	xp.hp1 = computeheight_inters(ray, cy, xp.t1);
// if (!xp.hp1)
// {
// 	return (assess_color(ray, cy->r), ray->color = compute_color(&test), __TRUE);
// }
	xp.hp2 = computeheight_inters(ray, cy, xp.t2);
// if (!xp.hp2)
// {
// 	return (assess_color(ray, cy->r), ray->color = compute_color(&test), __TRUE);
// }
// return (__TRUE);
	if (xp.hp1 < 0 && xp.hp2 < 0)
		return (__FALSE);
	return (ray_inter_cy_op(ray, cy, &xp, x));
}


t_bool	ray_inter_cy_op(t_ray *ray, t_cy *cy, t_params *xp, int x)
{
	double	t;

	if (xp->hp1 >= 0 && xp->hp2 >= 0)
	{
		t = assess_the_solution(xp->t1, xp->t2);
		if (assess_color(ray, t))
		{
			ray->obj.type = __CYLINDER;
			ray->obj.index = x;
			return (ray->color = compute_color(&cy->rgb), __TRUE);
		}
		return (__FALSE);
	}
	if (xp->hp1 >= xp->hp2)
	{
		if (assess_color(ray, xp->t1))
		{
			ray->obj.type = __CYLINDER;
			ray->obj.index = x;
			return (ray->color = compute_color(&cy->rgb), __TRUE);
		}
		return (__FALSE);
	}
	if (xp->hp2 > xp->hp1)
	{
		if (assess_color(ray, xp->t2))
		{
			ray->obj.type = __CYLINDER;
			ray->obj.index = x;
			return (ray->color = compute_color(&cy->rgb), __TRUE);
		}
		return (__FALSE);
	}
	return (__FALSE);
}

t_bool	setallparameters(t_ray *ray, t_cy *cy, t_params *xp)
{
	xp->k = __sq(cy->axis.x) + __sq(cy->axis.y) + __sq(cy->axis.z);
	xp->f = -2 * cy->axis.x * cy->axis.y;
	xp->g = -2 * cy->axis.x * cy->axis.z;
	xp->h = -2 * cy->axis.y * cy->axis.z;
	xp->alpha = -(xp->f * cy->o.y) - (xp->g * cy->o.z);
	xp->beta = -(xp->f * cy->o.x) - (xp->h * cy->o.z);
	xp->lamda = -(xp->g * cy->o.x) - (xp->h * cy->o.y);
	xp->e = (xp->f * cy->o.x * cy->o.y) + (xp->g * cy->o.x * cy->o.z) + \
			(xp->h * cy->o.y * cy->o.z);
	xp->l = ray->o.x - cy->o.x;
	xp->m = ray->o.y - cy->o.y;
	xp->n = ray->o.z - cy->o.z;
	setparams_term1(ray, cy, xp);
	setparams_term2_term3(ray, xp);
	xp->c += xp->e - (xp->k * __sq(cy->r));
	xp->delta = __sq(xp->b) - (4 * xp->a * xp->c);
	xp->t1 = (-xp->b - sqrt(xp->delta)) / (2 * xp->a);
	xp->t2 = (-xp->b + sqrt(xp->delta)) / (2 * xp->a);
	return (__TRUE);
}

t_bool	setparams_term1(t_ray *ray, t_cy *cy, t_params *xp)
{
	xp->a = (xp->k - __sq(cy->axis.x)) * __sq(ray->dir.x) + \
			(xp->k - __sq(cy->axis.y)) * __sq(ray->dir.y) + \
			(xp->k - __sq(cy->axis.z)) * __sq(ray->dir.z);
	xp->b = 2 * ((xp->k - __sq(cy->axis.x)) * ray->dir.x * xp->l + \
				(xp->k - __sq(cy->axis.y)) * ray->dir.y * xp->m + \
				(xp->k - __sq(cy->axis.z)) * ray->dir.z * xp->n);
	xp->c = (xp->k - __sq(cy->axis.x)) * __sq(xp->l) + \
			(xp->k - __sq(cy->axis.y)) * __sq(xp->m) + \
			(xp->k - __sq(cy->axis.z)) * __sq(xp->n);
	return (__TRUE);
}

t_bool	setparams_term2_term3(t_ray *ray, t_params *xp)
{
	xp->a += (xp->f * ray->dir.x * ray->dir.y + \
				xp->g * ray->dir.x * ray->dir.z + \
				xp->h * ray->dir.y * ray->dir.z);
	xp->b += (xp->f * ray->dir.x * ray->o.y + \
				xp->f * ray->dir.y * ray->o.x + \
				xp->g * ray->dir.x * ray->o.z + \
				xp->g * ray->dir.z * ray->o.x + \
				xp->h * ray->dir.y * ray->o.z + \
				xp->h * ray->dir.z * ray->o.y);
	xp->c += (xp->f * ray->o.x * ray->o.y + \
				xp->g * ray->o.x * ray->o.z + \
				xp->h * ray->o.y * ray->o.z);
	xp->b += xp->alpha * ray->dir.x + \
				xp->beta * ray->dir.y + \
				xp->lamda * ray->dir.z;
	xp->c += xp->alpha * ray->o.x + \
				xp->beta * ray->o.y + \
				xp->lamda * ray->o.z;
	return (__TRUE);
}

double	computeheight_inters(t_ray *ray, t_cy *cy, double t)
{
	t_coord	p;
	t_vec	op;
	double	hp;
	// double	alpha;

	// if (t < 0)
	// 	return (t);
	p.x = ray->dir.x * t + ray->o.x;
	p.y = ray->dir.y * t + ray->o.y;
	p.z = ray->dir.z * t + ray->o.z;
	op.x = p.x - cy->o.x;
	op.y = p.y - cy->o.y;
	op.z = p.z - cy->o.z;
	hp = sqrt(__sq(vectornorm(&op)) - __sq(cy->r)); // height of the intersection relative to cylinder's center
	if (!vecdotvec(&op, &cy->axis))
		hp = 0;
	// alpha = acos(vecdotvec(&cy->axis, &op) / vectornorm(&op));
	// alpha = radtodeg(alpha);
	// if (alpha < -90 || alpha > 90) // consider the cylinder center as the center of the base so dividing the cylinder's height by 2
	// 	hp = -1;
	if (hp > cy->h/2) // the intersection is beyond the cylinder height
		return (-1);
	return (hp);
}
