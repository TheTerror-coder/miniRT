/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:29:22 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/26 15:31:51 by TheTerror        ###   ########lyon.fr   */
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
	while (j < _HEIGHT)
	{
		i = 0;
		while (i < _WIDHT)
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
	double	norm;
	t_vec	v_hyp;
	t_vec	v_dir;

	v->ray.o.x = v->c->pov.x;
	v->ray.o.y = v->c->pov.y;
	v->ray.o.z = v->c->pov.z;
	v_hyp.x = (i - (_WIDHT / 2.00));
	v_hyp.y = (-j + (_HEIGHT / 2.00));
	v_hyp.z = (-_WIDHT /(2.00 * tan(ft_degtorad(v->c->fov) / 2.00)));
	norm = ft_vectornorm(&v_hyp);
	ft_vectornormalize(&v->c->dir, &v_dir);
	v->ray.dir.x = v_dir.x * norm;
	v->ray.dir.y = v_dir.y * norm;
	v->ray.dir.z = v_dir.z * norm;
	v->ray.dir.x += (i - (_WIDHT / 2.00));
	v->ray.dir.y += (-j + (_HEIGHT / 2.00));
	v->ray.dir.x -= v->ray.o.x;
	v->ray.dir.y -= v->ray.o.y;
	v->ray.dir.z -= v->ray.o.z;
	ft_vectornormalize(&v->ray.dir, &v->ray.dir);
	v->ray.color = ft_color(&v->a->rgb);
	v->ray.len = -1;
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
	while (v->sp[++x])
	{
		// if (!ft_ray_fit_fov(v))
		// 	break ;
		ft_ray_inter_sp(v, v->sp[x]);
	}
	my_mlx_pixel_put(v->im, i, j, v->ray.color);
	return (__TRUE);
}
