/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:19:01 by TheTerror         #+#    #+#             */
/*   Updated: 2024/01/25 23:21:38 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inters.h"

double	ft_ray_inter_sp_op(t_vars *v, t_sp *sp);

t_bool	ft_ray_inter_sp(t_vars *v, t_sp *sp, int x)
{
	double	s;

	s = ft_ray_inter_sp_op(v, sp);
	if (ft_assess_color(v, s))
	{
		v->obj.type = 2;
		v->obj.index = x;
		return (v->ray.color = ft_color(&sp->rgb), __TRUE);
	}
	return (__FALSE);
}

t_bool	ft_assess_color(t_vars *v, double len_found)
{
	if (v->ray.len < 0)
	{
		if (len_found >= 0)
		{
			v->ray.len = len_found;
			return (__TRUE);
		}
		return (__FALSE);
	}
	if (len_found >= 0 && len_found <= v->ray.len)
	{
		v->ray.len = len_found;
		return (__TRUE);
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

	a = ft_sq(v->ray.dir.x) + ft_sq(v->ray.dir.y) + \
		ft_sq(v->ray.dir.z);
	b = 2.00 * v->ray.dir.x * (v->ray.o.x - sp->o.x) + \
		2.00 * v->ray.dir.y * (v->ray.o.y - sp->o.y) + \
		2.00 * v->ray.dir.z * (v->ray.o.z - sp->o.z);
	c = ft_sq(v->ray.o.x - sp->o.x) + \
		ft_sq(v->ray.o.y - sp->o.y) + \
		ft_sq(v->ray.o.z - sp->o.z) - \
		ft_sq(sp->d / 2.00);
	delta = ft_sq(b) - (4 * a * c);
	if (delta < 0)
		return (delta);
/*	printf("dir: %f %f %f\n", v->ray.dir.x, v->ray.dir.y, v->ray.dir.z);
	printf("origin: %f %f %f\n", v->ray.o.x, v->ray.o.y, v->ray.o.z);
	printf("sp: %f %f %f\n", sp->o.x, sp->o.y, sp->o.z);*/
	s1 = (-b - sqrt(delta)) / (2 * a);
	s2 = (-b + sqrt(delta)) / (2 * a);
	return (ft_assessthesolution(s1, s2));
}

double	ft_assessthesolution(double s1, double s2)
{
//	printf("dist: %f %f\n", s1, s2);
//	exit(0);
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
