/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_extremities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:38:21 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/04 16:11:46 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "inters.h"

typedef struct	s_consts
{
	t_coord	pt_ph;
	double	t;
	double	norm_phpi;
	double	c1;
	double	c2;
	double	c3;
	double	c4;
	double	c5;
	double	c6;
}				t_consts;

t_bool	compute_pt_ph(t_cy *cy, t_consts *vars);
t_bool	compute_lenght_t(t_vars *v, t_cy *cy, t_consts *vars);
t_bool	compute_norm_vec_phpi(t_vars *v, t_consts *vars);

t_bool	case_ray_inter_extremities(t_vars *v, t_cy *cy)
{
	t_consts	vars;
	
	compute_pt_ph(cy, &vars);
	compute_lenght_t(v, cy, &vars);
	compute_norm_vec_phpi(v, &vars);
	if (vars.norm_phpi > (cy->d / 2))
		return (__FALSE);
	if (ft_assess_color(v, vars.t))
		return (v->ray.color = ft_color(&cy->rgb), __TRUE);
	return (__FALSE);
}

t_bool	compute_pt_ph(t_cy *cy, t_consts *vars)
{
	vars->pt_ph.x = cy->o.x + (cy->h / 2) * cy->axis.x;
	vars->pt_ph.x = cy->o.y + (cy->h / 2) * cy->axis.y;
	vars->pt_ph.x = cy->o.z + (cy->h / 2) * cy->axis.z;
	return (__TRUE);
}

t_bool	compute_lenght_t(t_vars *v, t_cy *cy, t_consts *vars)
{
	double	num;
	double	denom;

	vars->c1 = v->ray.o.x - vars->pt_ph.x;
	vars->c2 = v->ray.o.y - vars->pt_ph.y;
	vars->c3 = v->ray.o.z - vars->pt_ph.z;
	vars->c4 = v->ray.o.x - cy->o.x;
	vars->c5 = v->ray.o.y - cy->o.y;
	vars->c6 = v->ray.o.z - cy->o.z;
	num = ft_sq(vars->c4) + ft_sq(vars->c5) + ft_sq(vars->c6) \
		- ft_sq(vars->c1) - ft_sq(vars->c2) - ft_sq(vars->c3) \
		- ft_sq(cy->h / 2);
	denom = 2 * (v->ray.dir.x * (vars->c1 - vars->c4) + v->ray.dir.y \
		* (vars->c2 - vars->c5) + v->ray.dir.z * (vars->c3 - vars->c6));
	if (!num || !denom)
		return(vars->t = 0, __TRUE);
	vars->t = num / denom;
	return (__TRUE);
}

t_bool	compute_norm_vec_phpi(t_vars *v, t_consts *vars)
{
	vars->norm_phpi = sqrt(ft_sq(vars->t * v->ray.dir.x + vars->c1) \
			+ ft_sq(vars->t * v->ray.dir.y + vars->c2) + ft_sq(vars->t \
			* v->ray.dir.z + vars->c3));
	return (__TRUE);
}