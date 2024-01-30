/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:29:22 by TheTerror         #+#    #+#             */
/*   Updated: 2024/01/30 08:22:15 by lmohin           ###   ########.fr       */
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

t_bool	ft_intersections(t_vars *v, int i, int j)
{
	int	x;
	int	x2;
	int	type2;
	t_vars	*light;
	int	color;
	int	color2;
	double	stock;
	double	ray_len;
	t_vec	new_vec;

	v->obj.type = 1;
	v->ray.color = 0;
	x = -1;
	while (v->sp && v->sp[++x])
		ft_ray_inter_sp(v, v->sp[x], x);
	x = -1;
	while (v->pl && v->pl[++x])
		ft_ray_inter_pl(v, v->pl[x], x);
	x = -1;
	while (v->cy && v->cy[++x])
		ft_ray_inter_cy(v, v->cy[x]);
	x2 = v->obj.index;
	type2 = v->obj.type;
	ray_len = v->ray.len;
	light = ft_init_v();
	light->ray.o.x = v->light->pol.x;
	light->ray.o.y = v->light->pol.y;
	light->ray.o.z = v->light->pol.z; 
	light->ray.dir.x = v->cam->pov.x - v->light->pol.x + v->ray.len * v->ray.dir.x;
	light->ray.dir.y = v->cam->pov.y - v->light->pol.y + v->ray.len * v->ray.dir.y;
	light->ray.dir.z = v->cam->pov.z - v->light->pol.z + v->ray.len * v->ray.dir.z;
	ft_vectornormalize(&light->ray.dir, &light->ray.dir);
	x = -1;
	while (v->sp && v->sp[++x])
		ft_ray_inter_sp(light, v->sp[x], x);
	x = -1;
	while (v->pl && v->pl[++x])
		ft_ray_inter_pl(light, v->pl[x], x);
	x = -1;
	while (v->cy && v->cy[++x])
		ft_ray_inter_cy(light, v->cy[x]);
	if ((light->ray.len * light->ray.len - ft_sq(v->cam->pov.x - v->light->pol.x + v->ray.len * v->ray.dir.x) 
		- ft_sq(v->cam->pov.y - v->light->pol.y + v->ray.len * v->ray.dir.y)
		- ft_sq(v->cam->pov.z - v->light->pol.z + v->ray.len * v->ray.dir.z) >= 0.0001) ||
		(light->ray.len * light->ray.len - ft_sq(v->cam->pov.x - v->light->pol.x + v->ray.len * v->ray.dir.x)
 	    - ft_sq(v->cam->pov.y - v->light->pol.y + v->ray.len * v->ray.dir.y)
 	            - ft_sq(v->cam->pov.z - v->light->pol.z + v->ray.len * v->ray.dir.z) <= -0.0001))
	{
		v->ray.color = v->amb->rgb.r * 0.2;
		v->ray.color<<=8;
		v->ray.color += v->amb->rgb.g * 0.2;
		v->ray.color<<=8;
		v->ray.color += v->amb->rgb.b * 0.2;
		my_mlx_pixel_put(v->im, i, j, v->ray.color);
		return (__TRUE);
	}
	if (type2 == 0)
	{
		stock = light->ray.dir.x * v->pl[x2]->normal.x + light->ray.dir.y * v->pl[x2]->normal.y + light->ray.dir.z * v->pl[x2]->normal.z;
		if (stock * (v->ray.dir.x * v->pl[x2]->normal.x + v->ray.dir.y * v->pl[x2]->normal.y + v->pl[x2]->normal.z * v->ray.dir.z) < 0)
		{
			v->ray.color = v->amb->rgb.r * 0.2;
			v->ray.color <<=8;
			v->ray.color += v->amb->rgb.g * 0.2;
			v->ray.color <<=8;
			v->ray.color += v->amb->rgb.b * 0.2;
			my_mlx_pixel_put(v->im, i, j, v->ray.color);
			return (__TRUE);
		}
	//	printf("%f - %f\n", stock, v->ray.dir.x * v->pl[x2]->normal.x + v->ray.dir.y * v->pl[x2]->normal.y + v->pl[x2]->normal.z * v->ray.dir.z);
		if (stock < 0)
			stock *= -1;
		stock /= light->ray.len;
		if (stock > 1)
			stock = 1;
		color = 0;
		color2 = ft_color(&v->pl[x2]->rgb);
		color += ((color2 >> 16) & 0xFF) * stock * 0.8 + v->amb->rgb.r * 0.2;
		color <<= 8;
		color2 = ft_color(&v->pl[x2]->rgb);
		color += ((color2 >> 8) & 0xFF) * stock * 0.8 + v->amb->rgb.g * 0.2;
		color <<= 8;
		color += (ft_color(&v->pl[x2]->rgb) & 0xFF) * stock * 0.8 + v->amb->rgb.b * 0.2;
//		printf("%d\n", color);
		v->ray.color = color;
	}
	if (type2 == 2)
	{
		new_vec.x = v->sp[x2]->o.x - (v->cam->pov.x + v->ray.len * v->ray.dir.x);
		new_vec.y = v->sp[x2]->o.y - (v->cam->pov.y + v->ray.len * v->ray.dir.y);
		new_vec.z = v->sp[x2]->o.z - (v->cam->pov.z + v->ray.len * v->ray.dir.z);
		ft_vectornormalize(&new_vec, &new_vec);
		stock = light->ray.dir.x * new_vec.x + light->ray.dir.y * new_vec.y + light->ray.dir.z * new_vec.z;
	//	printf("%f\n", stock);
		if (stock * (v->ray.dir.x * new_vec.x + v->ray.dir.y * new_vec.y + v->ray.dir.z * new_vec.z) < 0)
		{
			v->ray.color = v->amb->rgb.r * 0.2;
			v->ray.color <<= 8;
			v->ray.color += v->amb->rgb.g * 0.2;
			v->ray.color <<= 8;
			v->ray.color += v->amb->rgb.b * 0.2;
			my_mlx_pixel_put(v->im, i, j, v->ray.color);
			return (__TRUE);
		}
		if (stock < 0)
			stock *= -1;
		stock /= light->ray.len;
		if (stock > 1)
			stock = 1;
		color2 = ft_color(&v->sp[x2]->rgb);
		color = 0;
		color += ((color2 >> 16) & 0xff) * stock * 0.8 + v->amb->rgb.r * 0.2;
		color2 = ft_color(&v->sp[x2]->rgb);
		color <<= 8;
		color += ((color2 >> 8) & 0xFF) * stock * 0.8 + v->amb->rgb.g * 0.2;
		color <<= 8;
		color += (ft_color(&v->sp[x2]->rgb) & 0xFF) * stock * 0.8 + v->amb->rgb.b * 0.2;
		v->ray.color = color;
	}
	my_mlx_pixel_put(v->im, i, j, v->ray.color);
	return (__TRUE);
}
