/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:29:22 by TheTerror         #+#    #+#             */
/*   Updated: 2023/09/07 17:23:35 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	ft_intersections(t_vars *v, int i, int j);

t_bool	ft_minirt(t_vars *v)
{
	int	i;
	int	j;

	j = 0;
	while (j < _HEIGHT)
	{
		i = 0;
		while (i < _WIDHT)
		{
			ft_setray(v, i, j);
			ft_intersections(v, i, j);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(v->xptr, v->win, v->im->img, 0, 0);
	return (__TRUE);
}


// t_bool	ft_ray_fit_fov(t_vars *v)
// {
// 	double	alpha;
// 	double	beta;
// 	double	ray_dot_c;
// 	double	cosbeta;

// 	alpha = ft_degtorad(v->c->fov);
// 	ray_dot_c = ft_vecdotvec(&v->c->dir, &v->ray.dir);
// 	cosbeta = ray_dot_c / (ft_vectornorm(&v->c->dir) * ft_vectornorm(&v->ray.dir));
// 	beta = acos(cosbeta);
// 	if (beta <= alpha / 2.00)
// 		return (__TRUE);
// 	return (__FALSE);
// }

t_bool	ft_intersections(t_vars *v, int i, int j)
{
	int	x;

	x = -1;
	while (v->sp && v->sp[++x])
		ft_ray_inter_sp(v, v->sp[x]);
	x = -1;
	while (v->pl && v->pl[++x])
		ft_ray_inter_pl(v, v->pl[x]);
	my_mlx_pixel_put(v->im, i, j, v->ray.color);
	return (__TRUE);
}
