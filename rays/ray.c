/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:05:07 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/31 16:50:25 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_bool	ft_setray000(t_ray *ray000, double fov, int i, int j);
t_bool	ft_definematrix(t_vars *v, t_vec *matrix);
t_bool	ft_transf_ray000toray(t_vars *v, t_ray *ray000, t_vec *matrix);

t_bool	ft_setray(t_vars *v, int i, int j)
{
	t_ray	ray000;
	t_vec	matrix;

	ft_definematrix(v, &matrix);
	ft_setray000(&ray000, v->c->fov, i, j);
	ft_vectornormalize(&ray000.dir, &ray000.dir);
	ft_transf_ray000toray(v, &ray000, &matrix);
	ft_vectornormalize(&v->ray.dir, &v->ray.dir);
	v->ray.color = ft_color(&v->a->rgb);
	v->ray.len = -1;
	return (__TRUE);
}

t_bool	ft_definematrix(t_vars *v, t_vec *matrix)
{
	t_vec	dir000;

	dir000.x = 0;
	dir000.y = 0;
	dir000.z = -1;
	ft_vectornormalize(&v->c->dir, &v->c->dir);
	matrix->x = v->c->dir.x - dir000.x;
	matrix->y = v->c->dir.y - dir000.y;
	matrix->z = v->c->dir.z - dir000.z;
	return (__TRUE);
}
t_bool	ft_transf_ray000toray(t_vars *v, t_ray *ray000, t_vec *matrix)
{
	v->ray.o.x = v->c->pov.x;
	v->ray.o.y = v->c->pov.y;
	v->ray.o.z = v->c->pov.z;
	v->ray.dir.x = matrix->x + ray000->dir.x;
	v->ray.dir.y = matrix->y + ray000->dir.y;
	v->ray.dir.z = matrix->z + ray000->dir.z;
	return (__TRUE);
}

t_bool	ft_setray000(t_ray *ray000, double fov, int i, int j)
{
	ray000->dir.x = (i - (_SIZE_X / 2.00));
	ray000->dir.y = (-j + (_SIZE_Y / 2.00));
	ray000->dir.z = (-_SIZE_X /(2.00 * tan(ft_degtorad(fov) / 2.00)));
	return (__TRUE);
}