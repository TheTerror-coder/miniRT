/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:35:58 by TheTerror         #+#    #+#             */
/*   Updated: 2024/01/10 16:29:12 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	set_amb_color(t_vars *v, char *infocolor, size_t line_index);
t_bool	parse_amb_color(char **colors, size_t line_index);

t_bool	set_ambient(t_vars *v, char **infos, size_t line_index)
{
	if (v->amb)
		return (scene_error("ambient lighting: multiple definitions",
				line_index));
	if (ft_2strlen(infos) < 2)
		return (scene_error("ambient lighting: missing information",
				line_index));
	if (ft_2strlen(infos) > 2)
		return (scene_error("ambient lighting: too much information",
				line_index));
	v->amb = ft_calloc(1, sizeof(t_amb));
	if (!v->amb)
		return (ft_error("set_ambient(): ft_calloc() failed"));
	if (!ft_isnumber(infos[0]))
	{
		scene_error("ambient lighting ratio: expecting decimal numbers",
			line_index);
		return (__FALSE);
	}
	v->amb->ratio = ft_atod(infos[0]);
	if (v->amb->ratio < 0 || v->amb->ratio > 1)
		return (scene_error("ambient lighting: invalid ratio", line_index));
	if (!set_amb_color(v, infos[1], line_index))
		return (__FALSE);
	return (__TRUE);
}

t_bool	set_amb_color(t_vars *v, char *infocolor, size_t line_index)
{
	char	**colors;

	if (ft_countchar(infocolor, ',') != 2)
	{
		return (scene_error("ambient lighting: incorrect color format",
				line_index));
	}
	colors = ft_split(infocolor, ',');
	if (!colors)
		return (ft_error("set_acolor(): ft_split() failed"));
	if (!parse_amb_color(colors, line_index))
		return (ft_free2str(&colors), __FALSE);
	v->amb->rgb.r = ft_atoi(colors[0]);
	v->amb->rgb.g = ft_atoi(colors[1]);
	v->amb->rgb.b = ft_atoi(colors[2]);
	ft_free2str(&colors);
	if (v->amb->rgb.r < 0 || v->amb->rgb.r > 255 || v->amb->rgb.g < 0
		|| v->amb->rgb.g > 255 || v->amb->rgb.b < 0 || v->amb->rgb.b > 255)
	{
		return (scene_error("ambient lighting: incorrect color format",
				line_index));
	}
	return (__TRUE);
}

t_bool	parse_amb_color(char **colors, size_t line_index)
{
	int	i;

	i = 0;
	if (ft_2strlen(colors) != 3)
	{
		return (scene_error("ambient lighting: incorrect color format",
				line_index));
	}
	while (colors[i])
	{
		if (!ft_is_uint(colors[i]))
		{
			scene_error("ambient lighting: incorrrect color format",
				line_index);
			return (__FALSE);
		}
		i++;
	}
	return (__TRUE);
}
