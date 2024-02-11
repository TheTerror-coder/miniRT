/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 06:28:58 by lmohin            #+#    #+#             */
/*   Updated: 2024/02/11 18:58:42 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "lightning.h"

typedef struct s_localvars
{
	double	dist;
	int		color;
	t_bool	inter;
	t_vec	normal;
}				t_lvars;

t_bool	is_shadows_sp(t_vars *v, t_lvars *vars, t_ray *light_ray, int x);
t_bool	is_shadows_pl(t_vars *v, t_lvars *vars, t_ray *light_ray, int x);
t_bool	is_shadows_cy(t_vars *v, t_lvars *vars, t_ray *light_ray, int x);

t_bool	is_shadows(t_vars *v, t_ray *light_ray, int i, int j)
{
	t_lvars	vars;

	light_ray->len = -1;
	vars.inter = __FALSE;
	is_shadows_sp(v, &vars, light_ray, -1);
	is_shadows_pl(v, &vars, light_ray, -1);
	is_shadows_cy(v, &vars, light_ray, -1);
	vars.dist = __sq(light_ray->len)
		- __sq(v->cam->pov.x - v->light->pol.x + v->ray->len * v->ray->dir.x)
		- __sq(v->cam->pov.y - v->light->pol.y + v->ray->len * v->ray->dir.y)
		- __sq(v->cam->pov.z - v->light->pol.z + v->ray->len * v->ray->dir.z);
	if (vars.dist >= 0.0000000001 || vars.dist <= -0.0000000001 \
			|| (vars.inter == __TRUE && v->ray->len != -1))
	{
		vars.color = amb_color(*v->amb, v->ray->color);
		my_mlx_pixel_put(v->im, i, j, vars.color);
		return (__TRUE);
	}
	else
		return (__FALSE);
	return (__TRUE);
}

t_bool	is_shadows_sp(t_vars *v, t_lvars *vars, t_ray *light_ray, int x)
{
	while (v->sp && v->sp[++x])
	{
		vars->dist = light_ray->len;
		light_ray->len = -1;
		ray_inter_sp(light_ray, v->sp[x], x);
		if (light_ray->len != -1 && (vars->dist - light_ray->len \
			>= -0.0000000001) && (vars->dist - light_ray->len <= 0.0000000001))
		{
			if (!light_side_test(get_normal_sphere(*v->sp[x], *light_ray), \
						*light_ray, *v->ray))
			{
				vars->normal = get_normal_sphere(*v->sp[x], *light_ray);
				vars->inter = __TRUE;
			}
			else if (light_side_test(vars->normal, *light_ray, *v->ray))
				vars->inter = __TRUE;
		}
		else if (light_ray->len < vars->dist && light_ray->len != -1)
			return (vars->inter = __FALSE, \
			vars->normal = get_normal_sphere(*v->sp[x], *light_ray), __TRUE);
		else if (vars->dist != -1)
			return (light_ray->len = vars->dist, __TRUE);
	}
	return (__TRUE);
}

t_bool	is_shadows_pl(t_vars *v, t_lvars *vars, t_ray *light_ray, int x)
{
	while (v->pl && v->pl[++x])
	{
		vars->dist = light_ray->len;
		light_ray->len = -1;
		ray_inter_pl(light_ray, v->pl[x], x);
		if (light_ray->len != -1 && ((vars->dist - light_ray->len) \
			>= -0.0000000001) && (vars->dist - light_ray->len <= 0.0000000001))
		{
			if (!light_side_test(v->pl[x]->normal, *light_ray, *v->ray))
			{
				vars->normal = v->pl[x]->normal;
				vars->inter = __TRUE;
			}
			else if (!light_side_test(vars->normal, *light_ray, *v->ray))
				vars->inter = __TRUE;
		}
		else if (light_ray->len < vars->dist && light_ray->len != -1)
			return (vars->inter = __FALSE, \
			vars->normal = v->pl[x]->normal, __TRUE);
		else if (vars->dist != -1)
			return (light_ray->len = vars->dist, __TRUE);
	}
	return (__TRUE);
}

t_bool	is_shadows_cy(t_vars *v, t_lvars *vars, t_ray *light_ray, int x)
{
	while (v->cy && v->cy[++x])
	{
		vars->dist = light_ray->len;
		light_ray->len = -1;
		ray_inter_cy(light_ray, v->cy[x], x);
		if (light_ray->len != -1 && (vars->dist - light_ray->len \
			>= -0.0000000001) && (vars->dist - light_ray->len <= 0.0000000001))
		{
			if (!light_side_test(get_normal_cylinder(*v->cy[x], \
				*light_ray), *light_ray, *v->ray))
			{
				vars->normal = get_normal_cylinder(*v->cy[x], *light_ray);
				vars->inter = __TRUE;
			}
			else if (!light_side_test(vars->normal, *light_ray, *v->ray))
				vars->inter = __TRUE;
		}
		else if (light_ray->len < vars->dist && light_ray->len != -1)
			return (vars->inter = __FALSE, vars->normal \
				= get_normal_cylinder(*v->cy[x], *light_ray), __TRUE);
		else if (vars->dist != -1)
			return (light_ray->len = vars->dist, __TRUE);
	}
	return (__TRUE);
}
