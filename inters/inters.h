/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inters.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:21:23 by TheTerror         #+#    #+#             */
/*   Updated: 2023/09/08 16:19:36 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERS_H
# define INTERS_H

# include "../minirt.h"

t_bool	ft_ray_inter_sp(t_vars *v, t_sp *sp);
t_bool	ft_ray_inter_pl(t_vars *v, t_pl *pl);
t_bool	ft_assess_color(t_vars *v, double len_found);
double	ft_assessthesolution(double s1, double s2);
t_bool	ft_ray_inter_cy(t_vars *v, t_cy *cy);

#endif