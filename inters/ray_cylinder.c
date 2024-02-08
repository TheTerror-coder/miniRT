/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:36:07 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/08 12:00:50 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inters.h"

t_bool	ft_ray_inter_cy_op(t_ray *ray, t_cy *cy, t_params *xp, int x);
t_bool	ft_setallparameters(t_ray *ray, t_cy *cy, t_params *xp);
t_bool	ftsetparams_term1(t_ray *ray, t_cy *cy, t_params *xp);
t_bool	ftsetparams_term2_term3(t_ray *ray, t_params *xp);
double	ft_computeheight_inters(t_ray *ray, t_cy *cy, double t);

t_bool	ft_ray_inter_cy(t_ray *ray, t_cy *cy, int x)
{
	t_params	xp;
	
	ft_vectornormalize(&cy->axis, &cy->axis);
	ft_setallparameters(ray, cy, &xp);
	if (xp.delta < 0)
		return (__FALSE);
	xp.hp1 = ft_computeheight_inters(ray, cy, xp.t1);
	xp.hp2 = ft_computeheight_inters(ray, cy, xp.t2);
	if (xp.hp1 < 0 && xp.hp2 < 0)
		return (__FALSE);
	return (ft_ray_inter_cy_op(ray, cy, &xp, x));
}

t_bool	ft_ray_inter_cy_op(t_ray *ray, t_cy *cy, t_params *xp, int x)
{
	double	t;

	if (xp->hp1 >= 0 && xp->hp2 >= 0)
	{
		t = ft_assessthesolution(xp->t1, xp->t2);
		if (ft_assess_color(ray, t))
		{
			ray->obj.type = __CYLINDER;
			ray->obj.index = x;
			return (ray->color = ft_color(&cy->rgb), __TRUE);
		}
		return (__FALSE);
	}
	if (xp->hp1 > xp->hp2)
	{
		if (ft_assess_color(ray, xp->t1))
		{
			ray->obj.type = __CYLINDER;
			ray->obj.index = x;
			return (ray->color = ft_color(&cy->rgb), __TRUE);
		}
		return (__FALSE);
	}
	if (xp->hp2 > xp->hp1)
	{
		if (ft_assess_color(ray, xp->t2))
		{
			ray->obj.type = __CYLINDER;
			ray->obj.index = x;
			return (ray->color = ft_color(&cy->rgb), __TRUE);
		}
		return (__FALSE);
	}
	return (__FALSE);
}

t_bool	ft_setallparameters(t_ray *ray, t_cy *cy, t_params *xp)
{
	xp->k = ft_sq(cy->axis.x) + ft_sq(cy->axis.y) + ft_sq(cy->axis.z);
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
	ftsetparams_term1(ray, cy, xp);
	ftsetparams_term2_term3(ray, xp);
	xp->c += xp->e - (xp->k * ft_sq(cy->r));
	xp->delta = ft_sq(xp->b) - (4 * xp->a * xp->c);
	xp->t1 = (-xp->b - sqrt(xp->delta)) / (2 * xp->a);
	xp->t2 = (-xp->b + sqrt(xp->delta)) / (2 * xp->a);
	return (__TRUE);
}

t_bool	ftsetparams_term1(t_ray *ray, t_cy *cy, t_params *xp)
{
	xp->a = (xp->k - ft_sq(cy->axis.x)) * ft_sq(ray->dir.x) + \
			(xp->k - ft_sq(cy->axis.y)) * ft_sq(ray->dir.y) + \
			(xp->k - ft_sq(cy->axis.z)) * ft_sq(ray->dir.z);
	xp->b = 2 * ((xp->k - ft_sq(cy->axis.x)) * ray->dir.x * xp->l + \
				(xp->k - ft_sq(cy->axis.y)) * ray->dir.y * xp->m + \
				(xp->k - ft_sq(cy->axis.z)) * ray->dir.z * xp->n);
	xp->c = (xp->k - ft_sq(cy->axis.x)) * ft_sq(xp->l) + \
			(xp->k - ft_sq(cy->axis.y)) * ft_sq(xp->m) + \
			(xp->k - ft_sq(cy->axis.z)) * ft_sq(xp->n);
	return (__TRUE);
}

t_bool	ftsetparams_term2_term3(t_ray *ray, t_params *xp)
{
	xp->a += (xp->f * ray->dir.x * ray->dir.y \
		+ xp->g * ray->dir.x * ray->dir.z + \
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

double	ft_computeheight_inters(t_ray *ray, t_cy *cy, double t)
{
	t_coord	p;
	t_vec	op;
	double	hp;
	double	alpha;

	if (t < 0)
		return (t);
	p.x = ray->dir.x * t + ray->o.x;
	p.y = ray->dir.y * t + ray->o.y;
	p.z = ray->dir.z * t + ray->o.z;
	op.x = p.x - cy->o.x;
	op.y = p.y - cy->o.y;
	op.z = p.z - cy->o.z;
	hp = sqrt(ft_sq(ft_vectornorm(&op)) - ft_sq(cy->r));
	alpha = acos(ft_vecdotvec(&cy->axis, &op) / ft_vectornorm(&op));
	alpha = ft_radtodeg(alpha);
	if (alpha < -90 || alpha > 90)
		hp = -1;
	if (!(hp >= 0 && hp <= cy->h))
		return (-1);
	return (hp);
}
