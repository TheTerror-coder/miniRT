/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:35:58 by TheTerror         #+#    #+#             */
/*   Updated: 2024/01/11 23:19:17 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	set_pov(t_vars *v, char *infopov, size_t line_index);
t_bool	parse_pov(char **pov, size_t line_index);
t_bool	set_cam_dir(t_vars *v, char *infodir, size_t line_index);
t_bool	parse_cam_dir(char **dir, size_t line_index);

t_bool	set_camera(t_vars *v, char **infos, size_t line_index)
{
	if (v->cam)
		return (scene_error("camera: multiple definitions", line_index));
	if (ft_2strlen(infos) < 3)
		return (scene_error("camera: missing information", line_index));
	if (ft_2strlen(infos) > 3)
		return (scene_error("camera: too much information", line_index));
	v->cam = ft_calloc(1, sizeof(t_cam));
	if (!v->cam)
		return (ft_error("set_camera(): ft_calloc() failed"));
	if (!set_pov(v, infos[0], line_index))
		return (__FALSE);
	if (!set_cam_dir(v, infos[1], line_index))
		return (__FALSE);
	if (!ft_isnumber(infos[2]))
		return (scene_error("camera: expecting only decimal numbers",
				line_index));
	v->cam->fov = ft_atod(infos[2]);
	if (v->cam->fov < 0 || v->cam->fov > 180)
		return (scene_error("camera: invalid field of view", line_index));
	return (__TRUE);
}

t_bool	set_pov(t_vars *v, char *infopov, size_t line_index)
{
	char	**pov;

	if (ft_countchar(infopov, ',') != 2)
		return (scene_error("camera: incorrect coordinates", line_index));
	pov = ft_split(infopov, ',');
	if (!pov)
		return (ft_error("set_pov(): ft_split() failed"));
	if (!parse_pov(pov, line_index))
	{
		ft_free2str(&pov);
		return (__FALSE);
	}
	v->cam->pov.x = ft_atod(pov[0]);
	v->cam->pov.y = ft_atod(pov[1]);
	v->cam->pov.z = ft_atod(pov[2]);
	ft_free2str(&pov);
	return (__TRUE);
}

t_bool	parse_pov(char **pov, size_t line_index)
{
	int	i;

	i = 0;
	if (ft_2strlen(pov) != 3)
		return (scene_error("camera: incorrect coordinates", line_index));
	while (pov[i])
	{
		if (!ft_isnumber(pov[i]))
		{
			scene_error("camera coordinates: expecting decimal numbers",
				line_index);
			return (__FALSE);
		}
		i++;
	}
	return (__TRUE);
}

t_bool	set_cam_dir(t_vars *v, char *infodir, size_t line_index)
{
	char	**dir;

	if (ft_countchar(infodir, ',') != 2)
		return (scene_error("camera: incorrect dir format", line_index));
	dir = ft_split(infodir, ',');
	if (!dir)
		return (ft_error("set_cam_dir(): ft_split() failed"));
	if (!parse_cam_dir(dir, line_index))
		return (ft_free2str(&dir), __FALSE);
	v->cam->dir.x = ft_atod(dir[0]);
	v->cam->dir.y = ft_atod(dir[1]);
	v->cam->dir.z = ft_atod(dir[2]);
	ft_free2str(&dir);
	if (ft_sq(v->cam->dir.x) + ft_sq(v->cam->dir.y) + ft_sq(v->cam->dir.z) != 1)
		return (scene_error("camera: orientation vector must be normalized",
				line_index));
	if (v->cam->dir.x < -1 || v->cam->dir.x > 1
		|| v->cam->dir.y < -1 || v->cam->dir.y > 1
		|| v->cam->dir.z < -1 || v->cam->dir.z > 1)
	{
		return (scene_error("camera: incorrect orientation vector format",
				line_index));
	}
	return (__TRUE);
}

t_bool	parse_cam_dir(char **dir, size_t line_index)
{
	int	i;

	i = 0;
	if (ft_2strlen(dir) != 3)
		return (scene_error("camera: incorrect dir format", line_index));
	while (dir[i])
	{
		if (!ft_isnumber(dir[i]))
			return (scene_error("camera: incorrect dir format", line_index));
		i++;
	}
	return (__TRUE);
}
