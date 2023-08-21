/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:35:58 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/20 18:06:11 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	ft_set_acolor(t_vars *v, char *infocolor);

t_bool	ft_set_ambient(t_vars *v, char **infos)
{
	if (v->a)
		return (ft_error("ambient light: multiple definitions"));
	if (ft_2strlen(infos) < 2)
		return (ft_error("ambient light: missing information"));
	if (ft_2strlen(infos) > 2)
		return (ft_error("ambient light: too much information"));
	v->a = ft_calloc(1, sizeof(t_amb));
	if (!v->a)
		return (ft_error("ft_set_ambient(): ft_calloc() failed"));
	if (!ft_isnumber(infos[0]))
		return (ft_error("ambient light: expecting only decimal numbers"));
	v->a->ratio = ft_atod(infos[0]);
	if (v->a->ratio < 0 || v->a->ratio > 1)
		return (ft_error("ambient light: invalid ratio"));
	if (!ft_set_acolor(v, infos[1]))
		return (__FALSE);
	return (__TRUE);
}

t_bool	ft_set_acolor(t_vars *v, char *infocolor)
{
	char	**colors;
	int		i;

	i = 0;
	colors = ft_splitwset(infocolor, " ,\t\n");
	if (!colors)
		return (ft_error("ft_set_acolor(): ft_splitwset() failed"));
	if (!colors[0] || ft_2strlen(colors) != 3)
		return (ft_free2str(&colors), \
			ft_error("ambient light: incorrect color format"));
	while (colors[i])
	{
		if (!ft_isnumber(colors[i]))
			return (ft_free2str(&colors), \
				ft_error("ambient light: expecting only decimal numbers"));
		i++;
	}
	v->a->r = ft_atoi(colors[0]);
	v->a->g = ft_atoi(colors[1]);
	v->a->b = ft_atoi(colors[2]);
	ft_free2str(&colors);
	if (v->a->r < 0 || v->a->r > 255 || v->a->g < 0 || v->a->g > 255 || \
		v->a->b < 0 || v->a->b > 255)
		return (ft_error("ambient light: incorrect color format"));
	return (__TRUE);
}
