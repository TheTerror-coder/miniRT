/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:53:48 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/10 16:55:29 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	set_sphere_center(t_sp *sp, char *infocenter, size_t line_index);
t_bool	parse_sphere_center(char **center, size_t line_index);
t_bool	set_sphere_color(t_sp *sp, char *infocolor, size_t line_index);
t_bool	parse_sphere_color(char **colors, size_t line_index);

t_bool	set_sphere(t_vars *v, char **infos, size_t line_index)
{
	int	i;

	if (ft_2strlen(infos) < 3)
		return (scene_error("sphere: missing information", line_index));
	if (ft_2strlen(infos) > 3)
		return (scene_error("sphere: too much information", line_index));
	if (!init_a_sphere(v, &i))
		return (__FALSE);
	v->sp[i] = ft_calloc(1, sizeof(t_sp));
	if (!v->sp[i])
		return (ft_error("set_sphere(): ft_calloc() failed"));
	if (!set_sphere_center(v->sp[i], infos[0], line_index))
		return (__FALSE);
	if (!isnumber(infos[1]))
	{
		return (scene_error("sphere: expecting only decimal numbers",
				line_index));
	}
	v->sp[i]->d = ft_atod(infos[1]);
	if (v->sp[i]->d <= 0)
	{
		return (scene_error("sphere: diameter must be stricly positive",
				line_index));
	}
	if (!set_sphere_color(v->sp[i], infos[2], line_index))
		return (__FALSE);
	return (__TRUE);
}

t_bool	set_sphere_center(t_sp *sp, char *infocenter, size_t line_index)
{
	char	**center;

	if (countchar(infocenter, ',') != 2)
	{
		return (scene_error("sphere: incorrect center point format",
				line_index));
	}
	center = ft_split(infocenter, ',');
	if (!center)
		return (ft_error("set_center(): ft_split() failed"));
	if (!parse_sphere_center(center, line_index))
	{
		ft_free2str(&center);
		return (__FALSE);
	}
	sp->o.x = ft_atod(center[0]);
	sp->o.y = ft_atod(center[1]);
	sp->o.z = ft_atod(center[2]);
	ft_free2str(&center);
	return (__TRUE);
}

t_bool	parse_sphere_center(char **center, size_t line_index)
{
	int	i;

	i = 0;
	if (ft_2strlen(center) != 3)
	{
		return (scene_error("sphere: incorrect center point format",
				line_index));
	}
	while (center[i])
	{
		if (!isnumber(center[i]))
		{
			return (scene_error("sphere: incorrect center point format",
					line_index));
		}
		i++;
	}
	return (__TRUE);
}

t_bool	set_sphere_color(t_sp *sp, char *infocolor, size_t line_index)
{
	char	**colors;

	colors = ft_splitwset(infocolor, " ,\t\n");
	if (!colors)
		return (ft_error("ft_set_spcolor(): ft_splitwset() failed"));
	if (!parse_sphere_color(colors, line_index))
	{
		ft_free2str(&colors);
		return (__FALSE);
	}
	sp->rgb.r = ft_atoi(colors[0]);
	sp->rgb.g = ft_atoi(colors[1]);
	sp->rgb.b = ft_atoi(colors[2]);
	ft_free2str(&colors);
	if (sp->rgb.r < 0 || sp->rgb.r > 255 || sp->rgb.g < 0 || sp->rgb.g > 255
		|| sp->rgb.b < 0 || sp->rgb.b > 255)
	{
		return (scene_error("sphere: incorrect color format", line_index));
	}
	return (__TRUE);
}

t_bool	parse_sphere_color(char **colors, size_t line_index)
{
	int	i;

	i = 0;
	if (ft_2strlen(colors) != 3)
	{
		return (scene_error("sphere: incorrect color format", line_index));
	}
	while (colors[i])
	{
		if (!is_uint(colors[i]))
		{
			scene_error("sphere: incorrect color format", line_index);
			return (__FALSE);
		}
		i++;
	}
	return (__TRUE);
}
