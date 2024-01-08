/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:35:58 by TheTerror         #+#    #+#             */
/*   Updated: 2024/01/08 16:56:25 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	ft_set_acolor(t_vars *v, char *infocolor, size_t line_index);

t_bool	ft_set_ambient(t_vars *v, char **infos, size_t line_index)
{
	if (v->amb)
		return (scene_error("ambient light: multiple definitions", line_index));
	if (ft_2strlen(infos) < 2)
		return (scene_error("ambient light: missing information", line_index));
	if (ft_2strlen(infos) > 2)
		return (scene_error("ambient light: too much information", line_index));
	v->amb = ft_calloc(1, sizeof(t_amb));
	if (!v->amb)
		return (ft_error("ft_set_ambient(): ft_calloc() failed"));
	if (!ft_isnumber(infos[0]))
		return (scene_error("ambient light: expecting only decimal numbers", line_index));
	v->amb->ratio = ft_atod(infos[0]);
	if (v->amb->ratio < 0 || v->amb->ratio > 1)
		return (scene_error("ambient light: invalid ratio", line_index));
	if (!ft_set_acolor(v, infos[1], line_index))
		return (__FALSE);
	return (__TRUE);
}

t_bool	ft_set_acolor(t_vars *v, char *infocolor, size_t line_index)
{
	char	**colors;
	int		i;

	i = 0;
	colors = ft_splitwset(infocolor, " ,\t\n");
	if (!colors)
		return (ft_error("ft_set_acolor(): ft_splitwset() failed"));
	if (!colors[0] || ft_2strlen(colors) != 3)
		return (ft_free2str(&colors), \
			scene_error("ambient light: incorrect color format", line_index));
	while (colors[i])
	{
		if (!ft_isnumber(colors[i]))
			return (ft_free2str(&colors), \
				scene_error("ambient light: expecting only decimal numbers", line_index));
		i++;
	}
	v->amb->rgb.r = ft_atoi(colors[0]);
	v->amb->rgb.g = ft_atoi(colors[1]);
	v->amb->rgb.b = ft_atoi(colors[2]);
	ft_free2str(&colors);
	if (v->amb->rgb.r < 0 || v->amb->rgb.r > 255 || v->amb->rgb.g < 0 || v->amb->rgb.g > 255 || \
		v->amb->rgb.b < 0 || v->amb->rgb.b > 255)
		return (scene_error("ambient light: incorrect color format", line_index));
	return (__TRUE);
}
