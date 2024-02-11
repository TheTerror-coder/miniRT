/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:27:05 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/11 14:17:38 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "inters.h"
#include "limits.h"

typedef struct s_localvars
{
	t_vec	p_ro;
	t_coord	ray_o;
	double	num;
	double	denom;
	double	length;
}				t_lvars;

t_bool	ray_inter_pl_op(t_ray *ray, t_pl *pl, t_lvars *vars, int x);

/*
	t_vec	p_ro; // vector between the given point of the plane and the ray origin
	t_coord	ray_o; // ray origin
	double	num; // numerator
	double	denom; // denominator
	double	length; // length of the ray
*/

t_bool	ray_inter_pl(t_ray *ray, t_pl *pl, int x)
{
	t_lvars	vars;

	vars.ray_o.x = ray->o.x;
	vars.ray_o.y = ray->o.y;
	vars.ray_o.z = ray->o.z;
	vectornormalize(&pl->normal, &pl->normal);
	vectornormalize(&ray->dir, &ray->dir);
	vars.denom = vecdotvec(&pl->normal, &ray->dir);
	pointsdiff(&pl->p, &vars.ray_o, &vars.p_ro);
	vars.num = vecdotvec(&vars.p_ro, &pl->normal);
	if (!vars.num && (vars.denom < 0.0000000001 && vars.denom > -0.0000000001))
	{
		if (assess_color(ray, 0))
		{
			ray->obj.type = __PLANE;
			ray->obj.index = x;
			return (ray->color = compute_color(&pl->rgb), __TRUE);
		}
		return (__FALSE);
	}
	if (!vars.num || (vars.denom < 0.000000000001 \
			&& vars.denom > -0.000000000001))
		return (__FALSE);
	return (ray_inter_pl_op(ray, pl, &vars, x));
}

t_bool	ray_inter_pl_op(t_ray *ray, t_pl *pl, t_lvars *vars, int x)
{
	vars->length = vars->num / vars->denom;
	if (assess_color(ray, vars->length))
	{
		ray->obj.type = __PLANE;
		ray->obj.index = x;
		return (ray->color = compute_color(&pl->rgb), __TRUE);
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

*/
