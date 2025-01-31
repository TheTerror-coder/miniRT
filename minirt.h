/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:29:48 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/11 15:14:05 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "preprocss.h"
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "./inters/inters.h"
# include "./mathtools/mathtools.h"
# include "./memtools/memtools.h"
# include "./mlx_linux/mlx.h"
# include "./parsing/parsing.h"
# include "./lightning/lightning.h"

t_bool	set_mlx(t_vars *v);
void	exitprocss(t_vars *v, int status);
void	events(t_vars *v);
t_bool	ft_error(char *str);
t_bool	isnumber(const char *str);
t_bool	is_uint(const char *str);
double	ft_atod(const char *nptr);
t_bool	display_elms(t_vars *v);
t_bool	minirt(t_vars *v);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		compute_color(t_rgb *rgb);
t_bool	set_ray(t_vars *v, int i, int j);

#endif
