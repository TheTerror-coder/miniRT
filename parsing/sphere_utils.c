/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:35:13 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/11 13:36:16 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	parse_sphere_center(char **center, size_t line_index)
{
	int	i;

	i = 0;
	if (ft_2strlen(center) != 3)
		return (scene_error("sphere: incorrect center point format", \
				line_index));
	while (center[i])
	{
		if (!isnumber(center[i]))
			return (scene_error("sphere: incorrect center point format", \
					line_index));
		i++;
	}
	return (__TRUE);
}

t_bool	parse_sphere_color(char **colors, size_t line_index)
{
	int	i;

	i = 0;
	if (ft_2strlen(colors) != 3)
		return (scene_error("sphere: incorrect color format", line_index));
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
