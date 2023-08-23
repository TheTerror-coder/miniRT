/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:53:48 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/23 16:23:40 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	ft_set_spcenter(t_sp *sp, char *infocenter);
t_bool	ft_set_spcolor(t_sp *sp, char *infocolor);

t_bool ft_set_sphere(t_vars *v, char **infos)
{
	int	i;

	if (ft_2strlen(infos) < 3)
		return (ft_error("sphere: missing information"));
	if (ft_2strlen(infos) > 3)
		return (ft_error("sphere: too much information"));
	if (!ft_init_a_sphere(v, &i))
		return (__FALSE);
	v->sp[i] = ft_calloc(1, sizeof(t_sp));
	if (!v->sp[i])
		return (ft_error("ft_set_sphere(): ft_calloc() failed"));
	if (!ft_set_spcenter(v->sp[i], infos[0]))
		return (__FALSE);
	if (!ft_isnumber(infos[1]))
		return (ft_error("sphere: expecting only decimal numbers"));
	v->sp[i]->d = ft_atod(infos[1]);
	if (!ft_set_spcolor(v->sp[i], infos[2]))
		return (__FALSE);
	return (__TRUE);
}

t_bool	ft_set_spcenter(t_sp *sp, char *infocenter)
{
	char	**center;
	int		i;

	i = 0;
	center = ft_splitwset(infocenter, " ,\t\n");
	if (!center)
		return (ft_error("ft_set_center(): ft_splitwset() failed"));
	if (!center[0] || ft_2strlen(center) != 3)
		return (ft_free2str(&center), \
			ft_error("sphere: incorrect center point format"));
	while (center[i])
	{
		if (!ft_isnumber(center[i]))
			return (ft_free2str(&center), \
				ft_error("sphere: expecting only decimal numbers"));
		i++;
	}
	sp->o.x = ft_atod(center[0]);
// printf("hihihhihhihih\n");
	sp->o.y = ft_atod(center[1]);
	sp->o.z = ft_atod(center[2]);
	ft_free2str(&center);
	return (__TRUE);
}

t_bool	ft_set_spcolor(t_sp *sp, char *infocolor)
{
	char	**colors;
	int		i;

	i = 0;
	colors = ft_splitwset(infocolor, " ,\t\n");
	if (!colors)
		return (ft_error("ft_set_spcolor(): ft_splitwset() failed"));
	if (!colors[0] || ft_2strlen(colors) != 3)
		return (ft_free2str(&colors), \
			ft_error("sphere: incorrect color format"));
	while (colors[i])
	{
		if (!ft_isnumber(colors[i]))
			return (ft_free2str(&colors), \
				ft_error("sphere: expecting only decimal numbers"));
		i++;
	}
	sp->rgb.r = ft_atoi(colors[0]);
	sp->rgb.g = ft_atoi(colors[1]);
	sp->rgb.b = ft_atoi(colors[2]);
	ft_free2str(&colors);
	if (sp->rgb.r < 0 || sp->rgb.r > 255 || sp->rgb.g < 0 || sp->rgb.g > 255 || \
		sp->rgb.b < 0 || sp->rgb.b > 255)
		return (ft_error("sphere: incorrect color format"));
	return (__TRUE);
}
