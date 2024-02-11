/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:26:34 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/11 13:28:43 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	parse_plane_point(char **point, size_t line_index)
{
	int	i;

	i = 0;
	if (ft_2strlen(point) != 3)
	{
		return (scene_error("plane: incorrect point's coordinates format", \
				line_index));
	}
	while (point[i])
	{
		if (!isnumber(point[i]))
		{
			return (scene_error("plane: incorrect point's coordinates format", \
					line_index));
		}
		i++;
	}
	return (__TRUE);
}

t_bool	parse_plane_normal_vector(char **normal_vector, size_t line_index)
{
	int	i;

	i = 0;
	if (ft_2strlen(normal_vector) != 3)
		return (scene_error("plane: incorrect normal vector format", \
				line_index));
	while (normal_vector[i])
	{
		if (!isnumber(normal_vector[i]))
			return (scene_error("camera: incorrect normal vector format", \
					line_index));
		i++;
	}
	return (__TRUE);
}

t_bool	parse_plane_color(char **colors, size_t line_index)
{
	int	i;

	i = 0;
	if (ft_2strlen(colors) != 3)
		return (scene_error("plane: incorrect color format", line_index));
	while (colors[i])
	{
		if (!is_uint(colors[i]))
		{
			scene_error("plane: incorrect color format", line_index);
			return (__FALSE);
		}
		i++;
	}
	return (__TRUE);
}
