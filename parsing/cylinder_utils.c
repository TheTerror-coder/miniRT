/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 22:06:56 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/13 03:11:38 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	set_cydir_op(t_cy *cy, char **dir, size_t line_index);
t_bool	set_cycolor_op(t_cy *cy, char **colors, size_t line_index);

t_bool	set_cycenter(t_cy *cy, char *infocenter, size_t line_index)
{
	char	**center;
	int		i;

	i = 0;
	center = ft_split(infocenter, ',');
	if (!center)
		return (ft_error("ft_set_center(): ft_split() failed"));
	if (ft_2strlen(center) != 3)
		return (ft_free2str(&center), \
			scene_error("cylinder: incorrect center point format", line_index));
	while (center[i])
	{
		if (!isnumber(center[i]))
			return (ft_free2str(&center), scene_error(\
				"cylinder: expecting only decimal numbers", line_index));
		i++;
	}
	cy->o.x = ft_atod(center[0]);
	cy->o.y = ft_atod(center[1]);
	cy->o.z = ft_atod(center[2]);
	ft_free2str(&center);
	return (__TRUE);
}

t_bool	set_cydir(t_cy *cy, char *infodir, size_t line_index)
{
	char	**dir;
	int		i;

	i = 0;
	dir = ft_split(infodir, ',');
	if (!dir)
		return (ft_error("ft_set_dir(): ft_split() failed"));
	if (ft_2strlen(dir) != 3)
		return (ft_free2str(&dir), scene_error(\
			"cylinder: incorrect orientation vector format", line_index));
	while (dir[i])
	{
		if (!isnumber(dir[i]))
			return (ft_free2str(&dir), scene_error(\
				"cylinder: expecting only decimal numbers", line_index));
		i++;
	}
	if (!set_cydir_op(cy, dir, line_index))
		return (ft_free2str(&dir), __FALSE);
	ft_free2str(&dir);
	return (__TRUE);
}

t_bool	set_cydir_op(t_cy *cy, char **dir, size_t line_index)
{
	cy->axis.x = ft_atod(dir[0]);
	cy->axis.y = ft_atod(dir[1]);
	cy->axis.z = ft_atod(dir[2]);
	if (cy->axis.x < -1 || cy->axis.x > 1 || cy->axis.y < -1 || \
		cy->axis.y > 1 || cy->axis.z < -1 || cy->axis.z > 1)
		return (scene_error("cylinder: incorrect orientation vector format",
				line_index));
	if (__sq(cy->axis.x) + __sq(cy->axis.y) + __sq(cy->axis.z) != 1)
		return (scene_error("cylinder: incorrect orientation vector format",
				line_index));
	return (__TRUE);
}

t_bool	set_cycolor(t_cy *cy, char *infocolor, size_t line_index)
{
	char	**colors;
	int		i;

	i = 0;
	colors = ft_split(infocolor, ',');
	if (!colors)
		return (ft_error("set_cycolor(): ft_split() failed"));
	if (ft_2strlen(colors) != 3)
		return (ft_free2str(&colors),
			scene_error("cylinder: incorrect color format", line_index));
	while (colors[i])
	{
		if (!is_uint(colors[i]))
		{
			ft_free2str(&colors);
			return (scene_error("cylinder: expecting only decimal numbers",
					line_index));
		}
		i++;
	}
	if (!set_cycolor_op(cy, colors, line_index))
		return (ft_free2str(&colors), __FALSE);
	ft_free2str(&colors);
	return (__TRUE);
}

t_bool	set_cycolor_op(t_cy *cy, char **colors, size_t line_index)
{
	cy->rgb.r = ft_atoi(colors[0]);
	cy->rgb.g = ft_atoi(colors[1]);
	cy->rgb.b = ft_atoi(colors[2]);
	if (cy->rgb.r < 0 || cy->rgb.r > 255 || cy->rgb.g < 0 || cy->rgb.g > 255 || \
		cy->rgb.b < 0 || cy->rgb.b > 255)
		return (scene_error("cylinder: incorrect color format", line_index));
	return (__TRUE);
}
