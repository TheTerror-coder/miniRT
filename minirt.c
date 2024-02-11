/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:29:22 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/11 15:11:45 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	intersections(t_vars *v, int i, int j);

t_bool	minirt(t_vars *v)
{
	int	i;
	int	j;

	j = 0;
	while (j < _HEIGHT)
	{
		i = 0;
		while (i < _WIDHT)
		{
			set_ray(v, i, j);
			intersections(v, i, j);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(v->xptr, v->win, v->im->img, 0, 0);
	return (__TRUE);
}

t_bool	intersections(t_vars *v, int i, int j)
{
	int	x;

	x = -1;
	v->ray->obj.type = -1;
	while (v->sp && v->sp[++x])
		ray_inter_sp(v->ray, v->sp[x], x);
	x = -1;
	while (v->pl && v->pl[++x])
		ray_inter_pl(v->ray, v->pl[x], x);
	x = -1;
	while (v->cy && v->cy[++x])
		ray_inter_cy(v->ray, v->cy[x], x);
	if (v->ray->len == -1)
	{
		v->ray->color = 0;
		my_mlx_pixel_put(v->im, i, j, v->ray->color);
		return (__TRUE);
	}
	return (lightning(v, i, j));
}
