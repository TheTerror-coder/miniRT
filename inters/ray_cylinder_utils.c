/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:25:04 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/13 17:57:10 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inters.h"

t_bool	setparams_term1(t_ray *ray, t_cy *cy, t_params *xp);
t_bool	setparams_term2_term3(t_ray *ray, t_params *xp);

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
	xp->t1 = (-xp->b - __sqrt(xp->delta)) / (2 * xp->a);
	xp->t2 = (-xp->b + __sqrt(xp->delta)) / (2 * xp->a);
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

/*
	p : potential intersection point
	op : vector from the cylinder center to p
	hp : // height of the intersection relative to cylinder's center
	if (hp > cy->h/2) // the intersection is beyond the cylinder height
*/

double	computeheight_inters(t_ray *ray, t_cy *cy, double t)
{
	t_coord	p;
	t_vec	op;
	double	hp;

	p.x = ray->dir.x * t + ray->o.x;
	p.y = ray->dir.y * t + ray->o.y;
	p.z = ray->dir.z * t + ray->o.z;
	op.x = p.x - cy->o.x;
	op.y = p.y - cy->o.y;
	op.z = p.z - cy->o.z;
	hp = __sqrt(__sq(vectornorm(&op)) - __sq(cy->r));
	if (!vecdotvec(&op, &cy->axis))
		hp = 0;
	if (hp > cy->h / 2)
		return (-1);
	return (hp);
}
