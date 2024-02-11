/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:54:13 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/11 13:30:16 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	set_plane_point(t_pl *pl, char *infopoint, size_t line_index);
t_bool	set_plane_normal_vector(t_pl *pl, char *infonormal, size_t line_index);
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
	if (!set_plane_normal_vector(v->pl[i], infos[1], line_index))
		return (__FALSE);
	if (!set_plane_color(v->pl[i], infos[2], line_index))
		return (__FALSE);
	return (__TRUE);
}

t_bool	set_plane_point(t_pl *pl, char *infopoint, size_t line_index)
{
	char	**point;

	if (countchar(infopoint, ',') != 2)
	{
		return (scene_error("plane: incorrect point's coordinates format", \
				line_index));
	}
	point = ft_split(infopoint, ',');
	if (!point)
		return (ft_error("set_plane_point(): ft_split() failed"));
	if (!parse_plane_point(point, line_index))
	{
		ft_free2str(&point);
		return (__FALSE);
	}
	pl->p.x = ft_atod(point[0]);
	pl->p.y = ft_atod(point[1]);
	pl->p.z = ft_atod(point[2]);
	ft_free2str(&point);
	return (__TRUE);
}

t_bool	set_plane_normal_vector(t_pl *pl, char *infonormal, size_t line_index)
{
	char	**normal_vector;

	if (countchar(infonormal, ',') != 2)
		return (scene_error("plane: incorrect normal vector format",
				line_index));
	normal_vector = ft_split(infonormal, ',');
	if (!normal_vector)
		return (ft_error("set_plane_normal_vector(): ft_split() failed"));
	if (!parse_plane_normal_vector(normal_vector, line_index))
		return (ft_free2str(&normal_vector), __FALSE);
	pl->normal.x = ft_atod(normal_vector[0]);
	pl->normal.y = ft_atod(normal_vector[1]);
	pl->normal.z = ft_atod(normal_vector[2]);
	ft_free2str(&normal_vector);
	if (__sq(pl->normal.x) + __sq(pl->normal.y) + __sq(pl->normal.z) != 1)
		return (scene_error("plane: incorrect normal vector format", \
				line_index));
	if (pl->normal.x < -1 || pl->normal.x > 1 \
		|| pl->normal.y < -1 || pl->normal.y > 1 \
		|| pl->normal.z < -1 || pl->normal.z > 1)
	{
		return (scene_error("plane: incorrect orientation vector format", \
				line_index));
	}
	return (__TRUE);
}

t_bool	set_plane_color(t_pl *pl, char *infocolor, size_t line_index)
{
	char	**colors;

	colors = ft_split(infocolor, ',');
	if (!colors)
		return (ft_error("set_plane_color(): ft_split() failed"));
	if (!parse_plane_color(colors, line_index))
		return (ft_free2str(&colors), __FALSE);
	pl->rgb.r = ft_atoi(colors[0]);
	pl->rgb.g = ft_atoi(colors[1]);
	pl->rgb.b = ft_atoi(colors[2]);
	ft_free2str(&colors);
	if (pl->rgb.r < 0 || pl->rgb.r > 255 \
		|| pl->rgb.g < 0 || pl->rgb.g > 255 \
		|| pl->rgb.b < 0 || pl->rgb.b > 255)
	{
		return (scene_error("plane: incorrect color format", line_index));
	}
	return (__TRUE);
}
