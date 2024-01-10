/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:53:48 by TheTerror         #+#    #+#             */
/*   Updated: 2024/01/10 16:45:25 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	set_sphere_center(t_sp *sp, char *infocenter, size_t line_index);
t_bool	set_sphere_color(t_sp *sp, char *infocolor, size_t line_index);

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
		return (ft_error("ft_set_sphere(): ft_calloc() failed"));
	if (!set_sphere_center(v->sp[i], infos[0], line_index))
		return (__FALSE);
	if (!ft_isnumber(infos[1]))
		return (scene_error("sphere: expecting only decimal numbers", line_index));
	v->sp[i]->d = ft_atod(infos[1]);
	if (!set_sphere_color(v->sp[i], infos[2], line_index))
		return (__FALSE);
	return (__TRUE);
}

t_bool	set_sphere_center(t_sp *sp, char *infocenter, size_t line_index)
{
	char	**center;
	int		i;

	i = 0;
	center = ft_splitwset(infocenter, " ,\t\n");
	if (!center)
		return (ft_error("ft_set_center(): ft_splitwset() failed"));
	if (!center[0] || ft_2strlen(center) != 3)
		return (ft_free2str(&center), \
			scene_error("sphere: incorrect center point format", line_index));
	while (center[i])
	{
		if (!ft_isnumber(center[i]))
			return (ft_free2str(&center), \
				scene_error("sphere: expecting only decimal numbers", line_index));
		i++;
	}
	sp->o.x = ft_atod(center[0]);
	sp->o.y = ft_atod(center[1]);
	sp->o.z = ft_atod(center[2]);
	ft_free2str(&center);
	return (__TRUE);
}

t_bool	set_sphere_color(t_sp *sp, char *infocolor, size_t line_index)
{
	char	**colors;
	int		i;

	i = 0;
	colors = ft_splitwset(infocolor, " ,\t\n");
	if (!colors)
		return (ft_error("ft_set_spcolor(): ft_splitwset() failed"));
	if (!colors[0] || ft_2strlen(colors) != 3)
		return (ft_free2str(&colors), \
			scene_error("sphere: incorrect color format", line_index));
	while (colors[i])
	{
		if (!ft_isnumber(colors[i]))
			return (ft_free2str(&colors), \
				scene_error("sphere: expecting only decimal numbers", line_index));
		i++;
	}
	sp->rgb.r = ft_atoi(colors[0]);
	sp->rgb.g = ft_atoi(colors[1]);
	sp->rgb.b = ft_atoi(colors[2]);
	ft_free2str(&colors);
	if (sp->rgb.r < 0 || sp->rgb.r > 255 || sp->rgb.g < 0 || sp->rgb.g > 255 || \
		sp->rgb.b < 0 || sp->rgb.b > 255)
		return (scene_error("sphere: incorrect color format", line_index));
	return (__TRUE);
}
