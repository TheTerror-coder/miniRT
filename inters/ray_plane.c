/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:27:05 by TheTerror         #+#    #+#             */
/*   Updated: 2023/09/07 22:32:56 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "inters.h"

t_bool	ft_define_pl_normal(t_pl *pl, t_vec *pl_n);

t_bool	ft_ray_inter_pl(t_vars *v, t_pl *pl)
{
	t_vec	p_ro;
	t_coord	ray_o;
	double	nom;
	double	denom;
	double	length;

	ray_o.x = v->ray.o.x;
	ray_o.y = v->ray.o.y;
	ray_o.z = v->ray.o.z;
	ft_vectornormalize(&pl->normal, &pl->normal);
	ft_vectornormalize(&v->ray.dir, &v->ray.dir);
	denom = ft_vecdotvec(&pl->normal, &v->ray.dir);
	ft_pointsdiff(&pl->p, &ray_o, &p_ro);
	nom = ft_vecdotvec(&p_ro, &pl->normal);
	if (!nom && denom > -0.000000000000001 && denom < 0.000000000000001)
		return (v->ray.color = ft_color(&pl->rgb), __TRUE);
	if (!nom || (denom > -0.000000000000001 && denom < 0.000000000000001))
		return (__FALSE);
	length = nom / denom;
	if (ft_assess_color(v, length))
		return (v->ray.color = ft_color(&pl->rgb), __TRUE);
	return (__FALSE);
}

t_bool	ft_define_pl_normal(t_pl *pl, t_vec *pl_n)
{
	t_vec	op;
	t_vec	pm;

	op.x = pl->p.x;
	op.y = pl->p.y;
	op.z = pl->p.z;
	ft_vectornormalize(&op, &op);
	pm.x = (pl->normal.y * op.z) - (pl->normal.z * op.y);
	pm.y = (pl->normal.z * op.x) - (pl->normal.x * op.z);
	pm.z = (pl->normal.x * op.y) - (pl->normal.y * op.x);
	ft_vectornormalize(&pm, &pm);
	pl_n->x = (pm.y * pl->normal.z) - (pm.z * pl->normal.y);
	pl_n->y = (pm.z * pl->normal.x) - (pm.x * pl->normal.z);
	pl_n->z = (pm.x * pl->normal.y) - (pm.y * pl->normal.x);
	return (__TRUE);
}
