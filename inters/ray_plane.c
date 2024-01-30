/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:27:05 by TheTerror         #+#    #+#             */
/*   Updated: 2024/01/29 04:28:59 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inters.h"
#include "limits.h"

t_bool	ft_define_pl_normal(t_pl *pl, t_vec *pl_n);

t_bool	ft_ray_inter_pl(t_vars *v, t_pl *pl, int x)
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
	if (!nom && (denom < 0.000000000001 && denom > -0.000000000001))
	{
		if (ft_assess_color(v, 0))
		{
			v->obj.type = 0;
			v->obj.index = x;
			return (v->ray.color = ft_color(&pl->rgb), __TRUE);
		}
		return (__FALSE);
	}
	if (!nom || (denom < 0.000000000001 && denom > -0.000000000001))
		return (__FALSE);
	length = nom / denom;
	if (ft_assess_color(v, length))
	{
		v->obj.type = 0;
		v->obj.index = x;
		return (v->ray.color = ft_color(&pl->rgb), __TRUE);
	}
	return (__FALSE);
}

/*

Po is a point belonging to the plane.

Let P be a point.

P ∈ Plane => (P - Po) ∈ Plan
	 => (P - Po) . N = 0
	 => (P.N - Po.N = 0
	 => P.N = Po.N
	 

P ∈ Ray => P = C + t*D

P ∈ Ray && P ∈ Plane => (C + t*D).N = Po.N
		    => (C.N + t * D.N = Po.N
		    => if D.N != 0 : t = (Po.N - C.N) / D.N 
		                     t = (Po - C).N / D.N 
		       else : no intersection or camera is in the plane

n.(P - X*/

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
