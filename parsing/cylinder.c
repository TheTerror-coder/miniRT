/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:54:49 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/11 13:18:53 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	cy_setter(t_vars *v, char **infos, size_t line_index, int i);
t_bool	set_cycenter(t_cy *cy, char *infocenter, size_t line_index);
t_bool	set_cydir(t_cy *cy, char *infodir, size_t line_index);
t_bool	set_cycolor(t_cy *cy, char *infocolor, size_t line_index);

t_bool	set_cylindre(t_vars *v, char **infos, size_t line_index)
{
	int	i;

	if (ft_2strlen(infos) < 5)
		return (scene_error("cylindre: missing information", line_index));
	if (ft_2strlen(infos) > 5)
		return (scene_error("cylindre: too much information", line_index));
	if (!init_a_cylindre(v, &i))
		return (__FALSE);
	v->cy[i] = ft_calloc(1, sizeof(t_cy));
	if (!v->cy[i])
		return (ft_error("set_cylindre(): ft_calloc() failed"));
	return (cy_setter(v, infos, line_index, i));
}

t_bool	cy_setter(t_vars *v, char **infos, size_t line_index, int i)
{
	if (!set_cycenter(v->cy[i], infos[0], line_index))
		return (__FALSE);
	if (!set_cydir(v->cy[i], infos[1], line_index))
		return (__FALSE);
	if (!isnumber(infos[2]) || !isnumber(infos[3]))
		return (scene_error(\
			"cylindre: expecting only decimal numbers", line_index));
	v->cy[i]->d = ft_atod(infos[2]);
	if (v->cy[i]->d <= 0)
		return (scene_error(\
			"cylinder diameter must be a positive number", line_index));
	v->cy[i]->r = v->cy[i]->d / 2;
	v->cy[i]->h = ft_atod(infos[3]);
	if (v->cy[i]->h <= 0)
		return (scene_error(\
			"cylinder height must be a positive number", line_index));
	if (!set_cycolor(v->cy[i], infos[4], line_index))
		return (__FALSE);
	return (__TRUE);
}
