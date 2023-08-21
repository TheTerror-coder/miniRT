/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:29:48 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/20 17:39:31 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "preprocss.h"
# include<math.h>
# include<sys/types.h>
# include<sys/stat.h>
# include<fcntl.h>
# include<stdio.h>
# include "./mlx_linux/mlx.h"
# include "./memtools/memtools.h"
# include "./mathtools/mathtools.h"
# include "./parsing/parsing.h"

t_bool	ft_set_mlx(t_vars *v);
void	ft_exitprocss(t_vars *v, int status);
void	ft_events(t_vars *v);
t_bool	ft_error(char *str);
t_bool	ft_isnumber(const char *str);
double	ft_atod(const char *nptr);
t_bool	ft_displayelms(t_vars *v);

# endif