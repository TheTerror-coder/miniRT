/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:53:19 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/10 16:55:29 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	set_light_coordinates(t_vars *v, char *infopol, size_t line_index);
t_bool	set_light_color(t_vars *v, char *infocolor, size_t line_index);
t_bool	parse_light_coordinates(char **light_point, size_t line_index);
t_bool	parse_light_color(char **colors, size_t line_index);

t_bool	set_light(t_vars *v, char **infos, size_t line_index)
{
	if (v->light)
		return (scene_error("light: multiple definitions", line_index));
	if (ft_2strlen(infos) < 3)
		return (scene_error("light: missing information", line_index));
	if (ft_2strlen(infos) > 3)
		return (scene_error("light: too much information", line_index));
	v->light = ft_calloc(1, sizeof(t_light));
	if (!v->light)
		return (ft_error("set_light(): ft_calloc() failed"));
	if (!set_light_coordinates(v, infos[0], line_index))
		return (__FALSE);
	if (!isnumber(infos[1]))
	{
		return (scene_error("light: expecting only decimal numbers",
				line_index));
	}
	v->light->ratio = ft_atod(infos[1]);
	if (v->light->ratio < 0 || v->light->ratio > 1)
		return (scene_error("light: invalid ratio", line_index));
	if (!set_light_color(v, infos[2], line_index))
		return (__FALSE);
	return (__TRUE);
}

t_bool	set_light_coordinates(t_vars *v, char *infopol, size_t line_index)
{
	char	**light_point;

	if (countchar(infopol, ',') != 2)
		return (scene_error("light: incorrect coordinates", line_index));
	light_point = ft_split(infopol, ',');
	if (!light_point)
		return (ft_error("set_light_coordinates(): ft_split() failed"));
	if (!parse_light_coordinates(light_point, line_index))
	{
		ft_free2str(&light_point);
		return (__FALSE);
	}
	v->light->pol.x = ft_atod(light_point[0]);
	v->light->pol.y = ft_atod(light_point[1]);
	v->light->pol.z = ft_atod(light_point[2]);
	ft_free2str(&light_point);
	return (__TRUE);
}

t_bool	parse_light_coordinates(char **light_point, size_t line_index)
{
	int	i;

	i = 0;
	if (!light_point[0] || ft_2strlen(light_point) != 3)
		return (scene_error("light: incorrect coordinates", line_index));
	while (light_point[i])
	{
		if (!isnumber(light_point[i]))
		{
			return (scene_error("light: incorrect coordinates", line_index));
		}
		i++;
	}
	return (__TRUE);
}

t_bool	set_light_color(t_vars *v, char *infocolor, size_t line_index)
{
	char	**colors;

	if (countchar(infocolor, ',') != 2)
		return (scene_error("light: incorrect color format", line_index));
	colors = ft_split(infocolor, ',');
	if (!colors)
		return (ft_error("set_light_color(): ft_split() failed"));
	if (!parse_light_color(colors, line_index))
	{
		ft_free2str(&colors);
		return (__FALSE);
	}
	v->light->rgb.r = ft_atoi(colors[0]);
	v->light->rgb.g = ft_atoi(colors[1]);
	v->light->rgb.b = ft_atoi(colors[2]);
	ft_free2str(&colors);
	if (v->light->rgb.r < 0 || v->light->rgb.r > 255
		|| v->light->rgb.g < 0 || v->light->rgb.g > 255
		|| v->light->rgb.b < 0 || v->light->rgb.b > 255)
		return (scene_error("light: incorrect color format", line_index));
	return (__TRUE);
}

t_bool	parse_light_color(char **colors, size_t line_index)
{
	int	i;

	i = 0;
	if (ft_2strlen(colors) != 3)
	{
		return (scene_error("light: incorrect color format", line_index));
	}
	while (colors[i])
	{
		if (!is_uint(colors[i]))
		{
			scene_error("light: incorrect color format", line_index);
			return (__FALSE);
		}
		i++;
	}
	return (__TRUE);
}
