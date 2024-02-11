/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:09:27 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/11 15:01:02 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../minirt.h"

t_bool	parse_args(t_vars *v, int argc, char **argv);
t_bool	set_ambient(t_vars *v, char **infos, size_t line_index);
t_bool	set_camera(t_vars *v, char **infos, size_t line_index);
t_bool	set_light(t_vars *v, char **infos, size_t line_index);
t_bool	set_sphere(t_vars *v, char **infos, size_t line_index);
t_bool	set_plane(t_vars *v, char **infos, size_t line_index);
t_bool	set_cylindre(t_vars *v, char **infos, size_t line_index);

t_bool	check_format(char *file);
t_bool	scene_error(char *str, size_t line_index);
size_t	countchar(char *str, char c);

#endif
