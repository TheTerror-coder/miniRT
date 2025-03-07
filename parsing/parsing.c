/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:35:23 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/13 13:19:50 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include <errno.h>

t_bool	parse_file(t_vars *v);
t_bool	set_elements(t_vars *v, char *line, size_t line_index);
t_bool	auth_id_then_set(t_vars *v, char **infos, char *id, size_t line_index);
t_bool	parse_loop(t_vars *v, int fd);

t_bool	parse_args(t_vars *v, int argc, char **argv)
{
	if (argc < 2)
		return (ft_error("no input"));
	if (argc > 2)
		return (ft_error("too much arguments"));
	if (!check_format(argv[1]))
		return (__FALSE);
	v->file = ft_strdup(argv[1]);
	if (!v->file)
		return (ft_error("ft_strdup() failed"));
	if (!parse_file(v))
		return (__FALSE);
	return (__TRUE);
}

t_bool	parse_file(t_vars *v)
{
	int		fd;

	fd = open(v->file, O_RDONLY);
	if (fd < 0)
		return (perror(v->file), __FALSE);
	if (!parse_loop(v, fd))
		return (close(fd), __FALSE);
	close(fd);
	if (!v->cam)
		return (ft_error("missing informations, check your elements"));
	if (!v->light)
	{
		if (!set_elements(v, "L 0,0,0 0 255,255,255", 0))
			return (__FALSE);
	}
	if (!v->amb)
	{
		if (!set_elements(v, "A 0 0,0,0", 0))
			return (__FALSE);
	}
	return (__TRUE);
}

t_bool	parse_loop(t_vars *v, int fd)
{
	char	*line;
	size_t	line_index;

	errno = 0;
	line = get_next_line(fd);
	if (!line && errno)
		return (ft_error("get_next_line() failed"));
	else if (!line)
		return (ft_error("missing informations, check your elements"));
	line_index = 1;
	while (line)
	{
		if (!set_elements(v, line, line_index))
			return (ft_freestr(&line), __FALSE);
		line_index++;
		ft_freestr(&line);
		errno = 0;
		line = get_next_line(fd);
		if (!line && errno)
			return (ft_error("get_next_line() failed"));
	}
	ft_freestr(&line);
	return (__TRUE);
}

t_bool	set_elements(t_vars *v, char *line, size_t line_index)
{
	char	**elm;

	elm = ft_splitwset(line, " \t\n");
	if (!elm)
		return (ft_error("ft_splitwset() failed"));
	if (!elm[0])
		return (ft_free2str(&elm), __TRUE);
	if (ft_2strlen(elm) < 3)
		return (ft_free2str(&elm), \
		scene_error("missing informations, check your elements", line_index));
	if (!auth_id_then_set(v, &elm[1], elm[0], line_index))
		return (ft_free2str(&elm), __FALSE);
	ft_free2str(&elm);
	return (__TRUE);
}

t_bool	auth_id_then_set(t_vars *v, char **infos, char *id, size_t line_index)
{
	if (!ft_strncmp("A", id, ft_strlen(id) + 1))
		return (set_ambient(v, infos, line_index));
	if (!ft_strncmp("C", id, ft_strlen(id) + 1))
		return (set_camera(v, infos, line_index));
	if (!ft_strncmp("L", id, ft_strlen(id) + 1))
		return (set_light(v, infos, line_index));
	if (!ft_strncmp("sp", id, ft_strlen(id) + 2))
		return (set_sphere(v, infos, line_index));
	if (!ft_strncmp("pl", id, ft_strlen(id) + 2))
		return (set_plane(v, infos, line_index));
	if (!ft_strncmp("cy", id, ft_strlen(id) + 2))
		return (set_cylindre(v, infos, line_index));
	return (scene_error("unknown id type", line_index));
}
