/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:09:27 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/20 02:21:40 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../minirt.h"

t_bool	ft_parse(t_vars *v, int argc, char **argv);
t_bool	ft_set_ambient(t_vars *v, char **infos);
t_bool	ft_set_camera(t_vars *v, char **infos);
t_bool	ft_set_light(t_vars *v, char **infos);
t_bool	ft_set_sphere(t_vars *v, char **infos);
t_bool	ft_set_plane(t_vars *v, char **infos);
t_bool	ft_set_cylindre(t_vars *v, char **infos);

#endif