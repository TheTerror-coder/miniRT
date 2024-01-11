/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:54:13 by TheTerror         #+#    #+#             */
/*   Updated: 2024/01/11 21:19:36 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	set_plane_point(t_pl *pl, char *infopoint, size_t line_index);
t_bool	set_plane_dir(t_pl *pl, char *infodir, size_t line_index);
t_bool	set_plane_color(t_pl *pl, char *infocolor, size_t line_index);

t_bool	set_plane(t_vars *v, char **infos, size_t line_index)
{
	int	i;

	if (ft_2strlen(infos) < 3)
		return (scene_error("plane: missing information", line_index));
	if (ft_2strlen(infos) > 3)
		return (scene_error("plane: too much information", line_index));
	if (!init_a_plane(v, &i))
		return (__FALSE);
	v->pl[i] = ft_calloc(1, sizeof(t_pl));
	if (!v->pl[i])
		return (ft_error("set_plane(): ft_calloc() failed"));
	if (!set_plane_point(v->pl[i], infos[0], line_index))
		return (__FALSE);
	if (!set_plane_dir(v->pl[i], infos[1], line_index))
		return (__FALSE);
	if (!set_plane_color(v->pl[i], infos[2], line_index))
		return (__FALSE);
	return (__TRUE);
}

t_bool	set_plane_point(t_pl *pl, char *infopoint, size_t line_index)
{
	char	**point;
	int		i;

	i = 0;
	point = ft_splitwset(infopoint, " ,\t\n");
	if (!point)
		return (ft_error("set_plane_point(): ft_splitwset() failed"));
	if (!point[0] || ft_2strlen(point) != 3)
		return (ft_free2str(&point), \
			scene_error("plane: incorrect point's coordinates format", line_index));
	while (point[i])
	{
		if (!ft_isnumber(point[i]))
			return (ft_free2str(&point), \
				scene_error("plane: expecting only decimal numbers", line_index));
		i++;
	}
	pl->p.x = ft_atod(point[0]);
	pl->p.y = ft_atod(point[1]);
	pl->p.z = ft_atod(point[2]);
	ft_free2str(&point);
	return (__TRUE);
}

t_bool	set_plane_dir(t_pl *pl, char *infodir, size_t line_index)
{
	char	**dir;
	int		i;

	i = 0;
	dir = ft_splitwset(infodir, " ,\t\n");
	if (!dir)
		return (ft_error("set_plane_dir(): ft_splitwset() failed"));
	if (!dir[0] || ft_2strlen(dir) != 3)
		return (ft_free2str(&dir), \
			scene_error("plane: incorrect orientation vector format", line_index));
	while (dir[i])
	{
		if (!ft_isnumber(dir[i]))
			return (ft_free2str(&dir), \
				scene_error("plane: expecting only decimal numbers", line_index));
		i++;
	}
	pl->normal.x = ft_atod(dir[0]);
	pl->normal.y = ft_atod(dir[1]);
	pl->normal.z = ft_atod(dir[2]);
	ft_free2str(&dir);
	if (pl->normal.x < -1 || pl->normal.x > 1 || pl->normal.y < -1 || \
		pl->normal.y > 1 || pl->normal.z < -1 || pl->normal.z > 1)
		return (scene_error("plane: incorrect orientation vector format", line_index));
	return (__TRUE);
}

t_bool	set_plane_color(t_pl *pl, char *infocolor, size_t line_index)
{
	char	**colors;
	int		i;

	i = 0;
	colors = ft_splitwset(infocolor, " ,\t\n");
	if (!colors)
		return (ft_error("ft_set_plcolor(): ft_splitwset() failed"));
	if (!colors[0] || ft_2strlen(colors) != 3)
		return (ft_free2str(&colors), \
			scene_error("plane: incorrect color format", line_index));
	while (colors[i])
	{
		if (!ft_isnumber(colors[i]))
			return (ft_free2str(&colors), \
				scene_error("plane: expecting only decimal numbers", line_index));
		i++;
	}
	pl->rgb.r = ft_atoi(colors[0]);
	pl->rgb.g = ft_atoi(colors[1]);
	pl->rgb.b = ft_atoi(colors[2]);
	ft_free2str(&colors);
	if (pl->rgb.r < 0 || pl->rgb.r > 255 || pl->rgb.g < 0 || pl->rgb.g > 255 || \
		pl->rgb.b < 0 || pl->rgb.b > 255)
		return (scene_error("plane: incorrect color format", line_index));
	return (__TRUE);
}
