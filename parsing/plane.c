/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:54:13 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/23 16:24:51 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	ft_set_plpoint(t_pl *pl, char *infopoint);
t_bool	ft_set_pldir(t_pl *pl, char *infodir);
t_bool	ft_set_plcolor(t_pl *pl, char *infocolor);

t_bool	ft_set_plane(t_vars *v, char **infos)
{
	int	i;

	if (ft_2strlen(infos) < 3)
		return (ft_error("plane: missing information"));
	if (ft_2strlen(infos) > 3)
		return (ft_error("plane: too much information"));
	if (!ft_init_a_plane(v, &i))
		return (__FALSE);
	v->pl[i] = ft_calloc(1, sizeof(t_pl));
// printf("heheheehehehe\n");
	if (!v->pl[i])
		return (ft_error("ft_set_plane(): ft_calloc() failed"));
	if (!ft_set_plpoint(v->pl[i], infos[0]))
		return (__FALSE);
	if (!ft_set_pldir(v->pl[i], infos[1]))
		return (__FALSE);
	if (!ft_set_plcolor(v->pl[i], infos[2]))
		return (__FALSE);
	return (__TRUE);
}

t_bool	ft_set_plpoint(t_pl *pl, char *infopoint)
{
	char	**point;
	int		i;

	i = 0;
	point = ft_splitwset(infopoint, " ,\t\n");
	if (!point)
		return (ft_error("ft_set_point(): ft_splitwset() failed"));
	if (!point[0] || ft_2strlen(point) != 3)
		return (ft_free2str(&point), \
			ft_error("plane: incorrect point's coordinates format"));
	while (point[i])
	{
		if (!ft_isnumber(point[i]))
			return (ft_free2str(&point), \
				ft_error("plane: expecting only decimal numbers"));
		i++;
	}
	pl->p.x = ft_atod(point[0]);
	pl->p.y = ft_atod(point[1]);
	pl->p.z = ft_atod(point[2]);
	ft_free2str(&point);
	return (__TRUE);
}

t_bool	ft_set_pldir(t_pl *pl, char *infodir)
{
	char	**dir;
	int		i;

	i = 0;
	dir = ft_splitwset(infodir, " ,\t\n");
	if (!dir)
		return (ft_error("ft_set_dir(): ft_splitwset() failed"));
	if (!dir[0] || ft_2strlen(dir) != 3)
		return (ft_free2str(&dir), \
			ft_error("plane: incorrect orientation vector format"));
	while (dir[i])
	{
		if (!ft_isnumber(dir[i]))
			return (ft_free2str(&dir), \
				ft_error("plane: expecting only decimal numbers"));
		i++;
	}
	pl->dir.x = ft_atod(dir[0]);
	pl->dir.y = ft_atod(dir[1]);
	pl->dir.z = ft_atod(dir[2]);
	ft_free2str(&dir);
	if (pl->dir.x < -1 || pl->dir.x > 1 || pl->dir.y < -1 || \
		pl->dir.y > 1 || pl->dir.z < -1 || pl->dir.z > 1)
		return (ft_error("plane: incorrect orientation vector format"));
	return (__TRUE);
}

t_bool	ft_set_plcolor(t_pl *pl, char *infocolor)
{
	char	**colors;
	int		i;

	i = 0;
	colors = ft_splitwset(infocolor, " ,\t\n");
	if (!colors)
		return (ft_error("ft_set_plcolor(): ft_splitwset() failed"));
	if (!colors[0] || ft_2strlen(colors) != 3)
		return (ft_free2str(&colors), \
			ft_error("plane: incorrect color format"));
	while (colors[i])
	{
		if (!ft_isnumber(colors[i]))
			return (ft_free2str(&colors), \
				ft_error("plane: expecting only decimal numbers"));
		i++;
	}
	pl->rgb.r = ft_atoi(colors[0]);
	pl->rgb.g = ft_atoi(colors[1]);
	pl->rgb.b = ft_atoi(colors[2]);
	ft_free2str(&colors);
	if (pl->rgb.r < 0 || pl->rgb.r > 255 || pl->rgb.g < 0 || pl->rgb.g > 255 || \
		pl->rgb.b < 0 || pl->rgb.b > 255)
		return (ft_error("plane: incorrect color format"));
	return (__TRUE);
}
