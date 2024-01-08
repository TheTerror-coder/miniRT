/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:54:49 by TheTerror         #+#    #+#             */
/*   Updated: 2024/01/08 17:49:28 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	ft_set_cycenter(t_cy *cy, char *infocenter, size_t line_index);
t_bool	ft_set_cydir(t_cy *cy, char *infodir, size_t line_index);
t_bool	ft_set_cycolor(t_cy *cy, char *infocolor, size_t line_index);

t_bool ft_set_cylindre(t_vars *v, char **infos, size_t line_index)
{
	int	i;

	if (ft_2strlen(infos) < 5)
		return (scene_error("cylindre: missing information", line_index));
	if (ft_2strlen(infos) > 5)
		return (scene_error("cylindre: too much information", line_index));
	if (!ft_init_a_cylindre(v, &i))
		return (__FALSE);
	v->cy[i] = ft_calloc(1, sizeof(t_cy));
	if (!v->cy[i])
		return (ft_error("ft_set_cylindre(): ft_calloc() failed"));
	if (!ft_set_cycenter(v->cy[i], infos[0], line_index))
		return (__FALSE);
	if (!ft_set_cydir(v->cy[i], infos[1], line_index))
		return (__FALSE);
	if (!ft_isnumber(infos[2]) || !ft_isnumber(infos[3]))
		return (scene_error("cylindre: expecting only decimal numbers", line_index));
	v->cy[i]->d = ft_atod(infos[2]);
	v->cy[i]->r = v->cy[i]->d / 2;
	v->cy[i]->h = ft_atod(infos[3]);
	if (!ft_set_cycolor(v->cy[i], infos[4], line_index))
		return (__FALSE);
	return (__TRUE);
}

t_bool	ft_set_cycenter(t_cy *cy, char *infocenter, size_t line_index)
{
	char	**center;
	int		i;

	i = 0;
	center = ft_splitwset(infocenter, " ,\t\n");
	if (!center)
		return (ft_error("ft_set_center(): ft_splitwset() failed"));
	if (!center[0] || ft_2strlen(center) != 3)
		return (ft_free2str(&center), \
			scene_error("cylindre: incorrect center point format", line_index));
	while (center[i])
	{
		if (!ft_isnumber(center[i]))
			return (ft_free2str(&center), \
				scene_error("cylindre: expecting only decimal numbers", line_index));
		i++;
	}
	cy->o.x = ft_atod(center[0]);
	cy->o.y = ft_atod(center[1]);
	cy->o.z = ft_atod(center[2]);
	ft_free2str(&center);
	return (__TRUE);
}

t_bool	ft_set_cydir(t_cy *cy, char *infodir, size_t line_index)
{
	char	**dir;
	int		i;

	i = 0;
	dir = ft_splitwset(infodir, " ,\t\n");
	if (!dir)
		return (ft_error("ft_set_dir(): ft_splitwset() failed"));
	if (!dir[0] || ft_2strlen(dir) != 3)
		return (ft_free2str(&dir), \
			scene_error("cylindre: incorrect orientation vector format", line_index));
	while (dir[i])
	{
		if (!ft_isnumber(dir[i]))
			return (ft_free2str(&dir), \
				scene_error("cylindre: expecting only decimal numbers", line_index));
		i++;
	}
	cy->axis.x = ft_atod(dir[0]);
	cy->axis.y = ft_atod(dir[1]);
	cy->axis.z = ft_atod(dir[2]);
	ft_free2str(&dir);
	if (cy->axis.x < -1 || cy->axis.x > 1 || cy->axis.y < -1 || \
		cy->axis.y > 1 || cy->axis.z < -1 || cy->axis.z > 1)
		return (scene_error("cylindre: incorrect orientation vector format", line_index));
	return (__TRUE);
}

t_bool	ft_set_cycolor(t_cy *cy, char *infocolor, size_t line_index)
{
	char	**colors;
	int		i;

	i = 0;
	colors = ft_splitwset(infocolor, " ,\t\n");
	if (!colors)
		return (ft_error("ft_set_cycolor(): ft_splitwset() failed"));
	if (!colors[0] || ft_2strlen(colors) != 3)
		return (ft_free2str(&colors), \
			scene_error("cylindre: incorrect color format", line_index));
	while (colors[i])
	{
		if (!ft_isnumber(colors[i]))
			return (ft_free2str(&colors), \
				scene_error("cylindre: expecting only decimal numbers", line_index));
		i++;
	}
	cy->rgb.r = ft_atoi(colors[0]);
	cy->rgb.g = ft_atoi(colors[1]);
	cy->rgb.b = ft_atoi(colors[2]);
	ft_free2str(&colors);
	if (cy->rgb.r < 0 || cy->rgb.r > 255 || cy->rgb.g < 0 || cy->rgb.g > 255 || \
		cy->rgb.b < 0 || cy->rgb.b > 255)
		return (scene_error("cylindre: incorrect color format", line_index));
	return (__TRUE);
}
