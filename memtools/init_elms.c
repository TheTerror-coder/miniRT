/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:51:42 by TheTerror         #+#    #+#             */
/*   Updated: 2024/01/10 16:44:51 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtools.h"

t_bool	init_a_sphere(t_vars *v, int *index)
{
	t_sp	**new;
	int		len;

	len = 0;
	while (v->sp && v->sp[len])
		len++;
	*index = len;
	len++;
	new = ft_calloc(len + 1, sizeof(t_sp *));
	if (!new)
		return (ft_error("init_a_sphere(): ft_calloc() failed"));
	len = 0;
	while (v->sp && v->sp[len])
	{
		new[len] = v->sp[len];
		v->sp[len] = NULL;
		len++;
	}
	ft_free_sp(v);
	v->sp = new;
	return (__TRUE);
}

t_bool	init_a_plane(t_vars *v, int *index)
{
	t_pl	**new;
	int		len;

	len = 0;
	while (v->pl && v->pl[len])
		len++;
	*index = len;
	len++;
	new = ft_calloc(len + 1, sizeof(t_pl *));
	if (!new)
		return (ft_error("ft_init_a_plane(): ft_calloc() failed"));
	len = 0;
	while (v->pl && v->pl[len])
	{
		new[len] = v->pl[len];
		v->pl[len] = NULL;
		len++;
	}
	ft_free_pl(v);
	v->pl = new;
	return (__TRUE);
}

t_bool	init_a_cylindre(t_vars *v, int *index)
{
	t_cy	**new;
	int		len;

	len = 0;
	while (v->cy && v->cy[len])
		len++;
	*index = len;
	len++;
	new = ft_calloc(len + 1, sizeof(t_cy *));
	if (!new)
		return (ft_error("ft_init_a_cylindre(): ft_calloc() failed"));
	len = 0;
	while (v->cy && v->cy[len])
	{
		new[len] = v->cy[len];
		v->cy[len] = NULL;
		len++;
	}
	ft_free_cy(v);
	v->cy = new;
	return (__TRUE);
}
