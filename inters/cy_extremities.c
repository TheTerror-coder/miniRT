/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_extremities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:38:21 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/10 16:57:31 by TheTerror        ###   ########lyon.fr   */
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

t_bool	inter_extremitie(t_ray *ray, t_cy *cy, t_vec *axis_dir, t_consts *vars, int x);
t_bool	compute_pt_ph(t_cy *cy, t_vec *axis_dir, t_consts *vars);
t_bool	compute_lenght_t(t_ray *ray, t_cy *cy, t_consts *vars);
t_bool	compute_norm_vec_phpi(t_ray *ray, t_consts *vars);

t_bool	ray_inter_cy_extremities(t_ray *ray, t_cy *cy, int x)
{
	t_consts	vars;
	t_vec		axis_dir;
	int			fdbk;
	
	fdbk = inter_extremitie(ray, cy, &cy->axis, &vars, x);
	axis_dir.x = -cy->axis.x;
	axis_dir.y = -cy->axis.y;
	axis_dir.z = -cy->axis.z;
	fdbk |= inter_extremitie(ray, cy, &axis_dir, &vars, x);
	return (fdbk);
}
t_bool	inter_extremitie(t_ray *ray, t_cy *cy, t_vec *axis_dir, t_consts *vars, int x)
{
	compute_pt_ph(cy, axis_dir, vars);
	compute_lenght_t(ray, cy, vars);
	compute_norm_vec_phpi(ray, vars);
	if (vars->norm_phpi > (cy->d / 2))
		return (__FALSE);
	if (assess_color(ray, vars->t))
	{
		ray->obj.type = __CYLINDER;
		ray->obj.index = x;
		return (ray->color = compute_color(&cy->rgb), __TRUE);
	}
	return (__FALSE);
}

t_bool	compute_pt_ph(t_cy *cy, t_vec *axis_dir, t_consts *vars)
{
	vars->pt_ph.x = cy->o.x + (cy->h / 2) * axis_dir->x;
	vars->pt_ph.y = cy->o.y + (cy->h / 2) * axis_dir->y;
	vars->pt_ph.z = cy->o.z + (cy->h / 2) * axis_dir->z;
	return (__TRUE);
}

t_bool	compute_lenght_t(t_ray *ray, t_cy *cy, t_consts *vars)
{
	double	num;
	double	denom;

	vars->c1 = ray->o.x - vars->pt_ph.x;
	vars->c2 = ray->o.y - vars->pt_ph.y;
	vars->c3 = ray->o.z - vars->pt_ph.z;
	vars->c4 = ray->o.x - cy->o.x;
	vars->c5 = ray->o.y - cy->o.y;
	vars->c6 = ray->o.z - cy->o.z;
	num = __sq(vars->c4) + __sq(vars->c5) + __sq(vars->c6) \
		- __sq(vars->c1) - __sq(vars->c2) - __sq(vars->c3) \
		- __sq(cy->h / 2);
	denom = 2 * (ray->dir.x * (vars->c1 - vars->c4) + ray->dir.y \
		* (vars->c2 - vars->c5) + ray->dir.z * (vars->c3 - vars->c6));
	if (!num || !denom)
		return(vars->t = 0, __TRUE);
	vars->t = num / denom;
	return (__TRUE);
}

t_bool	compute_norm_vec_phpi(t_ray *ray, t_consts *vars)
{
	vars->norm_phpi = sqrt(__sq(vars->t * ray->dir.x + vars->c1) \
			+ __sq(vars->t * ray->dir.y + vars->c2) + __sq(vars->t \
			* ray->dir.z + vars->c3));
	return (__TRUE);
}

// t_bool	define_extremitie_pl(t_cy *cy, t_consts *vars)
// {
// 	vars->pl.normal.x = cy->axis.x;
// 	vars->pl.normal.y = cy->axis.y;
// 	vars->pl.normal.z = cy->axis.z;
// 	vars->pl.p.x = cy->o.x + (cy->h / 2) * cy->axis.x;
// 	vars->pl.p.y = cy->o.y + (cy->h / 2) * cy->axis.y;
// 	vars->pl.p.z = cy->o.z + (cy->h / 2) * cy->axis.z;
// 	return (__TRUE);
// }
