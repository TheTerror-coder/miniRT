/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:53:19 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/23 16:22:44 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	ft_set_pol(t_vars *v, char *infopol);
t_bool	ft_set_lcolor(t_vars *v, char *infocolor);

t_bool ft_set_light(t_vars *v, char **infos)
{
	if (v->l)
		return (ft_error("light: multiple definitions"));
	if (ft_2strlen(infos) < 2)
		return (ft_error("light: missing information"));
	if (ft_2strlen(infos) > 3)
		return (ft_error("light: too much information"));
	v->l = ft_calloc(1, sizeof(t_light));
	if (!v->l)
		return (ft_error("ft_set_light(): ft_calloc() failed"));
	if (!ft_set_pol(v, infos[0]))
		return (__FALSE);
	if (!ft_isnumber(infos[1]))
		return (ft_error("light: expecting only decimal numbers"));
	v->l->ratio = ft_atod(infos[1]);
	if (v->l->ratio < 0 || v->l->ratio > 1)
		return (ft_error("light: invalid ratio"));
	if (!ft_set_lcolor(v, infos[2]))
		return (__FALSE);
	return (__TRUE);
}

t_bool	ft_set_pol(t_vars *v, char *infopol)
{
	char	**pol;
	int		i;

	i = 0;
	pol = ft_splitwset(infopol, " ,\t\n");
	if (!pol)
		return (ft_error("ft_set_pol(): ft_splitwset() failed"));
	if (!pol[0] || ft_2strlen(pol) != 3)
		return (ft_free2str(&pol), \
			ft_error("light: incorrect point of light format"));
	while (pol[i])
	{
		if (!ft_isnumber(pol[i]))
			return (ft_free2str(&pol), \
				ft_error("light: expecting only decimal numbers"));
		i++;
	}
	v->l->pol.x = ft_atod(pol[0]);
	v->l->pol.y = ft_atod(pol[1]);
	v->l->pol.z = ft_atod(pol[2]);
	ft_free2str(&pol);
	return (__TRUE);
}

t_bool	ft_set_lcolor(t_vars *v, char *infocolor)
{
	char	**colors;
	int		i;

	i = 0;
	colors = ft_splitwset(infocolor, " ,\t\n");
	if (!colors)
		return (ft_error("ft_set_lcolor(): ft_splitwset() failed"));
	if (!colors[0] || ft_2strlen(colors) != 3)
		return (ft_free2str(&colors), \
			ft_error("light: incorrect color format"));
	while (colors[i])
	{
		if (!ft_isnumber(colors[i]))
			return (ft_free2str(&colors), \
				ft_error("light: expecting only decimal numbers"));
		i++;
	}
	v->l->rgb.r = ft_atoi(colors[0]);
	v->l->rgb.g = ft_atoi(colors[1]);
	v->l->rgb.b = ft_atoi(colors[2]);
	ft_free2str(&colors);
	if (v->l->rgb.r < 0 || v->l->rgb.r > 255 || v->l->rgb.g < 0 || v->l->rgb.g > 255 || \
		v->l->rgb.b < 0 || v->l->rgb.b > 255)
		return (ft_error("light: incorrect color format"));
	return (__TRUE);
}
