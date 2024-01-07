/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:36:07 by TheTerror         #+#    #+#             */
/*   Updated: 2023/09/09 22:23:57 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "inters.h"

t_bool	ft_ray_inter_cy_op(t_vars *v, t_cy *cy, t_params *xp);
t_bool	ft_setallparameters(t_vars *v, t_cy *cy, t_params *xp);
t_bool	ftsetparams_term1(t_vars *v, t_cy *cy, t_params *xp);
t_bool	ftsetparams_term2_term3(t_vars *v, t_params *xp);
double	ft_computeheight_inters(t_vars *v, t_cy *cy, double t);

t_bool	ft_ray_inter_cy(t_vars *v, t_cy *cy)
{
	t_params	xp;
	
	ft_vectornormalize(&cy->axis, &cy->axis);
	ft_setallparameters(v, cy, &xp);
	if (xp.delta < 0)
		return (__FALSE);
	xp.hp1 = ft_computeheight_inters(v, cy, xp.t1);
	xp.hp2 = ft_computeheight_inters(v, cy, xp.t2);
	if (xp.hp1 < 0 && xp.hp2 < 0)
		return (__FALSE);
	return (ft_ray_inter_cy_op(v, cy, &xp));
}

t_bool	ft_ray_inter_cy_op(t_vars *v, t_cy *cy, t_params *xp)
{
	double	t;

	if (xp->hp1 >= 0 && xp->hp2 >= 0)
	{
		t = ft_assessthesolution(xp->t1, xp->t2);
		if (ft_assess_color(v, t))
			return (v->ray.color = ft_color(&cy->rgb), __TRUE);
		return (__FALSE);
	}
	if (xp->hp1 >= xp->hp2)
	{
		if (ft_assess_color(v, xp->t1))
			return (v->ray.color = ft_color(&cy->rgb), __TRUE);
		return (__FALSE);
	}
	if (xp->hp2 > xp->hp1)
	{
		if (ft_assess_color(v, xp->t2))
			return (v->ray.color = ft_color(&cy->rgb), __TRUE);
		return (__FALSE);
	}
	return (__FALSE);
}

t_bool	ft_setallparameters(t_vars *v, t_cy *cy, t_params *xp)
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
	xp->l = v->ray.o.x - cy->o.x;
	xp->m = v->ray.o.y - cy->o.y;
	xp->n = v->ray.o.z - cy->o.z;
	ftsetparams_term1(v, cy, xp);
	ftsetparams_term2_term3(v, xp);
	xp->c += xp->e - (xp->k * ft_sq(cy->r));
	xp->delta = ft_sq(xp->b) - (4 * xp->a * xp->c);
	xp->t1 = (-xp->b - sqrt(xp->delta)) / (2 * xp->a);
	xp->t2 = (-xp->b + sqrt(xp->delta)) / (2 * xp->a);
	return (__TRUE);
}

t_bool	ftsetparams_term1(t_vars *v, t_cy *cy, t_params *xp)
{
	xp->a = (xp->k - ft_sq(cy->axis.x)) * ft_sq(v->ray.dir.x) + \
			(xp->k - ft_sq(cy->axis.y)) * ft_sq(v->ray.dir.y) + \
			(xp->k - ft_sq(cy->axis.z)) * ft_sq(v->ray.dir.z);
	xp->b = 2 * ((xp->k - ft_sq(cy->axis.x)) * v->ray.dir.x * xp->l + \
				(xp->k - ft_sq(cy->axis.y)) * v->ray.dir.y * xp->m + \
				(xp->k - ft_sq(cy->axis.z)) * v->ray.dir.z * xp->n);
	xp->c = (xp->k - ft_sq(cy->axis.x)) * ft_sq(xp->l) + \
			(xp->k - ft_sq(cy->axis.y)) * ft_sq(xp->m) + \
			(xp->k - ft_sq(cy->axis.z)) * ft_sq(xp->n);
	return (__TRUE);
}

t_bool	ftsetparams_term2_term3(t_vars *v, t_params *xp)
{
	xp->a += (xp->f * v->ray.dir.x * v->ray.dir.y + \
				xp->g * v->ray.dir.x * v->ray.dir.z + \
				xp->h * v->ray.dir.y * v->ray.dir.z);
	xp->b += (xp->f * v->ray.dir.x * v->ray.o.y + \
				xp->f * v->ray.dir.y * v->ray.o.x + \
				xp->g * v->ray.dir.x * v->ray.o.z + \
				xp->g * v->ray.dir.z * v->ray.o.x + \
				xp->h * v->ray.dir.y * v->ray.o.z + \
				xp->h * v->ray.dir.z * v->ray.o.y);
	xp->c += (xp->f * v->ray.o.x * v->ray.o.y + \
				xp->g * v->ray.o.x * v->ray.o.z + \
				xp->h * v->ray.o.y * v->ray.o.z);
	xp->b += xp->alpha * v->ray.dir.x + \
				xp->beta * v->ray.dir.y + \
				xp->lamda * v->ray.dir.z;
	xp->c += xp->alpha * v->ray.o.x + \
				xp->beta * v->ray.o.y + \
				xp->lamda * v->ray.o.z;
	return (__TRUE);
}

double	ft_computeheight_inters(t_vars *v, t_cy *cy, double t)
{
	t_coord	p;
	t_vec	op;
	double	hp;
	double	alpha;

	if (t < 0)
		return (t);
	p.x = v->ray.dir.x * t + v->ray.o.x;
	p.y = v->ray.dir.y * t + v->ray.o.y;
	p.z = v->ray.dir.z * t + v->ray.o.z;
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
