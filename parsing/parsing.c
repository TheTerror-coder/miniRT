/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:35:23 by TheTerror         #+#    #+#             */
/*   Updated: 2024/01/08 15:37:19 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_bool	ft_checkformat(char *file);
t_bool	ft_parsefile(t_vars *v);
t_bool	ft_setelements(t_vars *v, char *line);
t_bool	ft_auth_id_then_set(t_vars *v, char **infos, char *id);

t_bool	ft_parse(t_vars *v, int argc, char **argv)
{
	if (argc < 2)
		return (ft_error("No input"));
	if (argc > 2)
		return (ft_error("too much arguments"));
	if (!ft_checkformat(argv[1]))
		return (__FALSE);
	v->file = ft_strdup(argv[1]);
	if (!v->file)
		return (ft_error("ft_strdup() failed"));
	if (!ft_parsefile(v))
		return (__FALSE);
	return (__TRUE);
}

t_bool	ft_parsefile(t_vars *v)
{
	int		fd;
	char	*line;

	fd = open(v->file, O_RDONLY);
	if (fd < 0)
		return (perror(v->file), __FALSE);
	line = get_next_line(fd);
	if (!line)
		return (ft_error("missing informations, check your elements"));
	while (line)
	{
		if (!ft_setelements(v, line))
			return (ft_freestr(&line), close(fd), __FALSE);
		ft_freestr(&line);
		line = get_next_line(fd);
	}
	ft_freestr(&line);
	close(fd);
	return (__TRUE);
}

t_bool	ft_setelements(t_vars *v, char *line)
{
	char	**elm;

	elm = ft_splitwset(line, " \t\n");
	if (!elm)
		return (ft_error("ft_splitwset() failed"));
	if (!elm[0])
		return (__TRUE);
	if (ft_2strlen(elm) < 3)
		return (ft_free2str(&elm), ft_error("missing informations, check your elements"));
	if (!ft_auth_id_then_set(v, &elm[1], elm[0]))
		return (ft_free2str(&elm), __FALSE);
	ft_free2str(&elm);
	return (__TRUE);
}

t_bool	ft_auth_id_then_set(t_vars *v, char **infos, char *id)
{
	if (!ft_strncmp("A", id, ft_strlen(id) + 1))
		return (ft_set_ambient(v, infos));
	if (!ft_strncmp("C", id, ft_strlen(id) + 1))
		return (ft_set_camera(v, infos));
	if (!ft_strncmp("L", id, ft_strlen(id) + 1))
		return (ft_set_light(v, infos));
	if (!ft_strncmp("sp", id, ft_strlen(id) + 2))
		return (ft_set_sphere(v, infos));
	if (!ft_strncmp("pl", id, ft_strlen(id) + 2))
		return (ft_set_plane(v, infos));
	if (!ft_strncmp("cy", id, ft_strlen(id) + 2))
		return (ft_set_cylindre(v, infos));
	return (ft_error("unknown id type"));
}

t_bool	ft_checkformat(char *file)
{
	size_t	i;

	i = ft_strlen(file);
	while (i != 0 && file[i] != '.')
		i--;
	if (ft_strncmp(file + i, ".rt", 4))
	{
		ft_putendl_fd("invalid file extension", STDERR_FILENO);
		return (__FALSE);
	}
	return (__TRUE);
}
