/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:09:27 by TheTerror         #+#    #+#             */
/*   Updated: 2024/01/09 16:56:11 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../minirt.h"

t_bool	parse_args(t_vars *v, int argc, char **argv);
t_bool	set_ambient(t_vars *v, char **infos, size_t line_index);
t_bool	ft_set_camera(t_vars *v, char **infos, size_t line_index);
t_bool	ft_set_light(t_vars *v, char **infos, size_t line_index);
t_bool	ft_set_sphere(t_vars *v, char **infos, size_t line_index);
t_bool	ft_set_plane(t_vars *v, char **infos, size_t line_index);
t_bool	ft_set_cylindre(t_vars *v, char **infos, size_t line_index);

t_bool	scene_error(char *str, size_t line_index);
size_t	ft_countchar(char *str, char c);

#endif
