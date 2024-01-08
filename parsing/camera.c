/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 21:35:58 by TheTerror         #+#    #+#             */
/*   Updated: 2024/01/08 14:56:17 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_bool	ft_set_pov(t_vars *v, char *infopov);
t_bool	ft_set_cdir(t_vars *v, char *infodir);

t_bool ft_set_camera(t_vars *v, char **infos)
{
	if (v->cam)
		return (ft_error("camera: multiple definitions"));
	if (ft_2strlen(infos) < 3)
		return (ft_error("camera: missing information"));
	if (ft_2strlen(infos) > 3)
		return (ft_error("camera: too much information"));
	v->cam = ft_calloc(1, sizeof(t_cam));
	if (!v->cam)
		return (ft_error("ft_set_camera(): ft_calloc() failed"));
	if (!ft_set_pov(v, infos[0]))
		return (__FALSE);
	if (!ft_set_cdir(v, infos[1]))
		return (__FALSE);
// printf("%szzz\n", infos[2]);
// ft_exitprocss(v, EXIT_SUCCESS);
	if (!ft_isnumber(infos[2]))
		return (ft_error("camera: expecting only decimal numbers"));
	v->cam->fov = ft_atod(infos[2]);
	if (v->cam->fov < 0 || v->cam->fov > 180)
		return (ft_error("camera: invalid field of view"));
	return (__TRUE);
}

t_bool	ft_set_pov(t_vars *v, char *infopov)
{
	char	**pov;
	int		i;

	i = 0;
	pov = ft_splitwset(infopov, " ,\t\n");
	if (!pov)
		return (ft_error("ft_set_pov(): ft_splitwset() failed"));
	if (!pov[0] || ft_2strlen(pov) != 3)
		return (ft_free2str(&pov), \
			ft_error("camera: incorrect point of view format"));
	while (pov[i])
	{
		if (!ft_isnumber(pov[i]))
			return (ft_free2str(&pov), \
				ft_error("camera: expecting only decimal numbers"));
		i++;
	}
	v->cam->pov.x = ft_atod(pov[0]);
	v->cam->pov.y = ft_atod(pov[1]);
	v->cam->pov.z = ft_atod(pov[2]);
	ft_free2str(&pov);
	return (__TRUE);
}

t_bool	ft_set_cdir(t_vars *v, char *infodir)
{
	char	**dir;
	int		i;

	i = 0;
	dir = ft_splitwset(infodir, " ,\t\n");
	if (!dir)
		return (ft_error("ft_set_dir(): ft_splitwset() failed"));
	if (!dir[0] || ft_2strlen(dir) != 3)
		return (ft_free2str(&dir), \
			ft_error("camera: incorrect orientation vector format"));
	while (dir[i])
	{
		if (!ft_isnumber(dir[i]))
			return (ft_free2str(&dir), \
				ft_error("camera: expecting only decimal numbers"));
		i++;
	}
	v->cam->dir.x = ft_atod(dir[0]);
	v->cam->dir.y = ft_atod(dir[1]);
	v->cam->dir.z = ft_atod(dir[2]);
	ft_free2str(&dir);
	if (v->cam->dir.x * v->cam->dir.x + v->cam->dir.y \
		* v->cam->dir.y + v->cam->dir.z * v->cam->dir.z != 1)
		return (ft_error("camera: incorrect orientation vector format"));
	if (v->cam->dir.x < -1 || v->cam->dir.x > 1 || v->cam->dir.y < -1 || \
		v->cam->dir.y > 1 || v->cam->dir.z < -1 || v->cam->dir.z > 1)
		return (ft_error("camera: incorrect orientation vector format"));
	return (__TRUE);
}
