/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:15:36 by TheTerror         #+#    #+#             */
/*   Updated: 2024/01/06 11:17:08 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	ft_displayothers(t_vars *v);

t_bool	ft_displayelms(t_vars *v)
{
	int	i;

	printf("A	%.2f	%d,%d,%d\n", v->amb->ratio, v->amb->rgb.r, v->amb->rgb.g, v->amb->rgb.b);
	printf(\
	"C	%.2f,%.2f,%.2f	%.2f,%.2f,%.2f	%.2f\n", v->cam->pov.x, v->cam->pov.y, \
	v->cam->pov.z, v->cam->dir.x, v->cam->dir.y, v->cam->dir.z, v->cam->fov);
	printf("L	%.2f,%.2f,%.2f	%.2f	%d,%d,%d\n", v->light->pol.x, \
	v->light->pol.y, v->light->pol.z, v->light->ratio, v->light->rgb.r, v->light->rgb.g, v->light->rgb.b);
	i = 0;
	while (v->sp[i])
	{
		printf("sp	%.2f,%.2f,%.2f	%.2f	%d,%d,%d\n", \
		v->sp[i]->o.x, v->sp[i]->o.y, v->sp[i]->o.z, v->sp[i]->d, \
		v->sp[i]->rgb.r, v->sp[i]->rgb.g, v->sp[i]->rgb.b);
		i++;
	}
	ft_displayothers(v);
	return (__TRUE);
}

t_bool	ft_displayothers(t_vars *v)
{
	int	i;

	i = 0;
	while (v->pl[i])
	{
		printf(\
		"pl	%.2f,%.2f,%.2f	%.2f,%.2f,%.2f	%d,%d,%d\n", v->pl[i]->p.x, \
			v->pl[i]->p.y, v->pl[i]->p.z, v->pl[i]->normal.x, v->pl[i]->normal.y, \
			v->pl[i]->normal.z, v->pl[i]->rgb.r, v->pl[i]->rgb.g, v->pl[i]->rgb.b);
		i++;
	}
	i = 0;
	while (v->cy[i])
	{
		printf(\
		"cy	%.2f,%.2f,%.2f	%.2f,%.2f,%.2f	%.2f	%.2f	%d,%d,%d\n", \
			v->cy[i]->o.x, v->cy[i]->o.y, v->cy[i]->o.z, v->cy[i]->dir.x, \
			v->cy[i]->dir.y, v->cy[i]->dir.z, v->cy[i]->d, v->cy[i]->h, \
			v->cy[i]->rgb.r, v->cy[i]->rgb.g, v->cy[i]->rgb.b);
		i++;
	}
	return (__TRUE);
}
