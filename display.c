/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:15:36 by TheTerror         #+#    #+#             */
/*   Updated: 2023/09/07 21:26:18 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	ft_displayothers(t_vars *v);

t_bool	ft_displayelms(t_vars *v)
{
	int	i;

	printf("A	%.2f	%d,%d,%d\n", v->a->ratio, v->a->rgb.r, v->a->rgb.g, v->a->rgb.b);
	printf(\
	"C	%.2f,%.2f,%.2f	%.2f,%.2f,%.2f	%.2f\n", v->c->pov.x, v->c->pov.y, \
	v->c->pov.z, v->c->dir.x, v->c->dir.y, v->c->dir.z, v->c->fov);
	printf("L	%.2f,%.2f,%.2f	%.2f	%d,%d,%d\n", v->l->pol.x, \
	v->l->pol.y, v->l->pol.z, v->l->ratio, v->l->rgb.r, v->l->rgb.g, v->l->rgb.b);
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
