/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inters.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:21:23 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/08 17:01:20 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERS_H
# define INTERS_H

# include "../minirt.h"

t_bool	ft_ray_inter_sp(t_ray *ray, t_sp *sp, int x);
t_bool	ft_ray_inter_pl(t_ray *ray, t_pl *pl, int x);
t_bool	ft_assess_color(t_ray *ray, double len_found);
double	ft_assessthesolution(double s1, double s2);
t_bool	ft_ray_inter_cy(t_ray *ray, t_cy *cy, int x);
t_bool	case_ray_inter_extremities(t_ray *ray, t_cy *cy);

#endif
