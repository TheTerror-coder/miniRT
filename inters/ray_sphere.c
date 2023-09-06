/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:19:01 by TheTerror         #+#    #+#             */
/*   Updated: 2023/09/06 15:43:30 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "inters.h"

double	ft_ray_inter_sp_op(t_vars *v, t_sp *sp);
double	ft_rsp_op_fdbk(double s1, double s2);

t_bool	ft_ray_inter_sp(t_vars *v, t_sp *sp)
{
	double	s;

	s = ft_ray_inter_sp_op(v, sp);
	if (v->ray.len < 0)
	{
		if (s >= 0)
		{
			v->ray.len = s;
			return (v->ray.color = ft_color(&sp->rgb), __TRUE);
		}
		return (__FALSE);
	}
	if (s >= 0 && s <= v->ray.len)
	{
		v->ray.len = s;
		return (v->ray.color = ft_color(&sp->rgb), __TRUE);
	}
	return (__FALSE);
}

double	ft_ray_inter_sp_op(t_vars *v, t_sp *sp)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	s1;
	double	s2;

	a = ft_square(v->ray.dir.x) + ft_square(v->ray.dir.y) + \
		ft_square(v->ray.dir.z);
	b = 2.00 * v->ray.dir.x * (v->ray.o.x - sp->o.x) + \
		2.00 * v->ray.dir.y * (v->ray.o.y - sp->o.y) + \
		2.00 * v->ray.dir.z * (v->ray.o.z - sp->o.z);
	c = ft_square(v->ray.o.x - sp->o.x) + \
		ft_square(v->ray.o.y - sp->o.y) + \
		ft_square(v->ray.o.z - sp->o.z) - \
		ft_square(sp->d / 2.00);
	delta = ft_square(b) - (4 * a * c);
	if (delta < 0)
		return (delta);
	s1 = (-b - sqrt(delta)) / (2 * a);
	s2 = (-b + sqrt(delta)) / (2 * a);
	return (ft_rsp_op_fdbk(s1, s2));
}

double	ft_rsp_op_fdbk(double s1, double s2)
{
	if (s1 >= 0 && s2 >= 0)
	{
		if (s1 < s2)
			return (s1);
		else
			return (s2);
	}
	if (s1 >= s2)
		return (s1);
	return (s2);
}
