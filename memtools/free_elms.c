/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_elms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:51:42 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/10 16:52:47 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "memtools.h"

void	free_sp(t_vars *v)
{
	int		i;

	i = 0;
	while (v->sp && v->sp[i])
	{
		free(v->sp[i]);
		v->sp[i] = NULL;
		i++;
	}
	if (v->sp)
		free(v->sp);
	v->sp = NULL;
}

void	free_pl(t_vars *v)
{
	int		i;

	i = 0;
	while (v->pl && v->pl[i])
	{
		free(v->pl[i]);
		v->pl[i] = NULL;
		i++;
	}
	if (v->pl)
		free(v->pl);
	v->pl = NULL;
}

void	free_cy(t_vars *v)
{
	int		i;

	i = 0;
	while (v->cy && v->cy[i])
	{
		free(v->cy[i]);
		v->cy[i] = NULL;
		i++;
	}
	if (v->cy)
		free(v->cy);
	v->cy = NULL;
}
