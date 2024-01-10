/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:53:19 by TheTerror         #+#    #+#             */
/*   Updated: 2024/01/10 15:42:43 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	set_light_coordinates(t_vars *v, char *infopol, size_t line_index);
t_bool	set_light_color(t_vars *v, char *infocolor, size_t line_index);

t_bool	set_light(t_vars *v, char **infos, size_t line_index)
{
	if (v->light)
		return (scene_error("light: multiple definitions", line_index));
	if (ft_2strlen(infos) < 2)
		return (scene_error("light: missing information", line_index));
	if (ft_2strlen(infos) > 3)
		return (scene_error("light: too much information", line_index));
	v->light = ft_calloc(1, sizeof(t_light));
	if (!v->light)
		return (ft_error("ft_set_light(): ft_calloc() failed"));
	if (!set_light_coordinates(v, infos[0], line_index))
		return (__FALSE);
	if (!ft_isnumber(infos[1]))
		return (scene_error("light: expecting only decimal numbers", line_index));
	v->light->ratio = ft_atod(infos[1]);
	if (v->light->ratio < 0 || v->light->ratio > 1)
		return (scene_error("light: invalid ratio", line_index));
	if (!set_light_color(v, infos[2], line_index))
		return (__FALSE);
	return (__TRUE);
}

t_bool	set_light_coordinates(t_vars *v, char *infopol, size_t line_index)
{
	char	**pol;
	int		i;

	i = 0;
	pol = ft_splitwset(infopol, " ,\t\n");
	if (!pol)
		return (ft_error("ft_set_pol(): ft_splitwset() failed"));
	if (!pol[0] || ft_2strlen(pol) != 3)
		return (ft_free2str(&pol), \
			scene_error("light: incorrect point of light format", line_index));
	while (pol[i])
	{
		if (!ft_isnumber(pol[i]))
			return (ft_free2str(&pol), \
				scene_error("light: expecting only decimal numbers", line_index));
		i++;
	}
	v->light->pol.x = ft_atod(pol[0]);
	v->light->pol.y = ft_atod(pol[1]);
	v->light->pol.z = ft_atod(pol[2]);
	ft_free2str(&pol);
	return (__TRUE);
}

t_bool	set_light_color(t_vars *v, char *infocolor, size_t line_index)
{
	char	**colors;
	int		i;

	i = 0;
	colors = ft_splitwset(infocolor, " ,\t\n");
	if (!colors)
		return (ft_error("ft_set_lcolor(): ft_splitwset() failed"));
	if (!colors[0] || ft_2strlen(colors) != 3)
		return (ft_free2str(&colors), \
			scene_error("light: incorrect color format", line_index));
	while (colors[i])
	{
		if (!ft_isnumber(colors[i]))
			return (ft_free2str(&colors), \
				scene_error("light: expecting only decimal numbers", line_index));
		i++;
	}
	v->light->rgb.r = ft_atoi(colors[0]);
	v->light->rgb.g = ft_atoi(colors[1]);
	v->light->rgb.b = ft_atoi(colors[2]);
	ft_free2str(&colors);
	if (v->light->rgb.r < 0 || v->light->rgb.r > 255 || v->light->rgb.g < 0 || v->light->rgb.g > 255 || \
		v->light->rgb.b < 0 || v->light->rgb.b > 255)
		return (scene_error("light: incorrect color format", line_index));
	return (__TRUE);
}
