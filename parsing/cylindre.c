/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylindre.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:54:49 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/20 18:13:18 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	ft_set_cycenter(t_cy *cy, char *infocenter);
t_bool	ft_set_cydir(t_cy *cy, char *infodir);
t_bool	ft_set_cycolor(t_cy *cy, char *infocolor);

t_bool ft_set_cylindre(t_vars *v, char **infos)
{
	int	i;

	if (ft_2strlen(infos) < 5)
		return (ft_error("cylindre: missing information"));
	if (ft_2strlen(infos) > 5)
		return (ft_error("cylindre: too much information"));
	if (!ft_init_a_cylindre(v, &i))
		return (__FALSE);
	v->cy[i] = ft_calloc(1, sizeof(t_cy));
	if (!v->cy[i])
		return (ft_error("ft_set_cylindre(): ft_calloc() failed"));
	if (!ft_set_cycenter(v->cy[i], infos[0]))
		return (__FALSE);
	if (!ft_set_cydir(v->cy[i], infos[1]))
		return (__FALSE);
	if (!ft_isnumber(infos[2]) || !ft_isnumber(infos[3]))
		return (ft_error("cylindre: expecting only decimal numbers"));
	v->cy[i]->d = ft_atod(infos[2]);
	v->cy[i]->h = ft_atod(infos[3]);
	if (!ft_set_cycolor(v->cy[i], infos[4]))
		return (__FALSE);
	return (__TRUE);
}

t_bool	ft_set_cycenter(t_cy *cy, char *infocenter)
{
	char	**center;
	int		i;

	i = 0;
	center = ft_splitwset(infocenter, " ,\t\n");
	if (!center)
		return (ft_error("ft_set_center(): ft_splitwset() failed"));
	if (!center[0] || ft_2strlen(center) != 3)
		return (ft_free2str(&center), \
			ft_error("cylindre: incorrect center point format"));
	while (center[i])
	{
		if (!ft_isnumber(center[i]))
			return (ft_free2str(&center), \
				ft_error("cylindre: expecting only decimal numbers"));
		i++;
	}
	cy->o.x = ft_atod(center[0]);
	cy->o.y = ft_atod(center[1]);
	cy->o.z = ft_atod(center[2]);
	ft_free2str(&center);
	return (__TRUE);
}

t_bool	ft_set_cydir(t_cy *cy, char *infodir)
{
	char	**dir;
	int		i;

	i = 0;
	dir = ft_splitwset(infodir, " ,\t\n");
	if (!dir)
		return (ft_error("ft_set_dir(): ft_splitwset() failed"));
	if (!dir[0] || ft_2strlen(dir) != 3)
		return (ft_free2str(&dir), \
			ft_error("cylindre: incorrect orientation vector format"));
	while (dir[i])
	{
		if (!ft_isnumber(dir[i]))
			return (ft_free2str(&dir), \
				ft_error("cylindre: expecting only decimal numbers"));
		i++;
	}
	cy->dir.x = ft_atod(dir[0]);
	cy->dir.y = ft_atod(dir[1]);
	cy->dir.z = ft_atod(dir[2]);
	ft_free2str(&dir);
	if (cy->dir.x < -1 || cy->dir.x > 1 || cy->dir.y < -1 || \
		cy->dir.y > 1 || cy->dir.z < -1 || cy->dir.z > 1)
		return (ft_error("cylindre: incorrect orientation vector format"));
	return (__TRUE);
}

t_bool	ft_set_cycolor(t_cy *cy, char *infocolor)
{
	char	**colors;
	int		i;

	i = 0;
	colors = ft_splitwset(infocolor, " ,\t\n");
	if (!colors)
		return (ft_error("ft_set_cycolor(): ft_splitwset() failed"));
	if (!colors[0] || ft_2strlen(colors) != 3)
		return (ft_free2str(&colors), \
			ft_error("cylindre: incorrect color format"));
	while (colors[i])
	{
		if (!ft_isnumber(colors[i]))
			return (ft_free2str(&colors), \
				ft_error("cylindre: expecting only decimal numbers"));
		i++;
	}
	cy->r = ft_atoi(colors[0]);
	cy->g = ft_atoi(colors[1]);
	cy->b = ft_atoi(colors[2]);
	ft_free2str(&colors);
	if (cy->r < 0 || cy->r > 255 || cy->g < 0 || cy->g > 255 || \
		cy->b < 0 || cy->b > 255)
		return (ft_error("cylindre: incorrect color format"));
	return (__TRUE);
}
