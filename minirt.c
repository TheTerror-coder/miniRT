/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:29:22 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/23 22:40:46 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	ft_ray(t_vars *v, int i, int j);
t_bool	ft_intersections(t_vars *v, int i, int j);

t_bool	ft_minirt(t_vars *v)
{
	int	i;
	int	j;

	j = 0;
	while (j < _SIZE_Y)
	{
		i = 0;
		while (i < _SIZE_X)
		{
			ft_ray(v, i, j);
			ft_intersections(v, i, j);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(v->xptr, v->win, v->im->img, 0, 0);
	return (__TRUE);
}

t_bool	ft_ray(t_vars *v, int i, int j)
{
	v->ray.o.x = v->c->pov.x;
	v->ray.o.y = v->c->pov.y;
	v->ray.o.z = v->c->pov.z;
	v->ray.dir.x = (i - (_SIZE_X / 2.00)) - v->ray.o.x;
	v->ray.dir.y = (-j + (_SIZE_Y / 2.00)) - v->ray.o.y;
	v->ray.dir.z = (-_SIZE_X /(2.00 * tan(ft_degtorad(v->c->fov) / 2.00))) - v->ray.o.z;
	v->ray.color = ft_color(&v->a->rgb);
	v->ray.len = -1;
	return (__TRUE);
}

t_bool	ft_intersections(t_vars *v, int i, int j)
{
	int	x;

	x = -1;
	while (v->sp[++x])
	{
		ft_ray_inter_sp(v, v->sp[x]);
	}
	my_mlx_pixel_put(v->im, i, j, v->ray.color);
	return (__TRUE);
}
