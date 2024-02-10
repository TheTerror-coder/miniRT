/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inters.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:21:23 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/10 16:26:59 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERS_H
# define INTERS_H

# include "../minirt.h"

t_bool	ray_inter_sp(t_ray *ray, t_sp *sp, int x);
t_bool	ray_inter_pl(t_ray *ray, t_pl *pl, int x);
t_bool	assess_color(t_ray *ray, double len_found);
double	assess_the_solution(double s1, double s2);
t_bool	ray_inter_cy(t_ray *ray, t_cy *cy, int x);
t_bool	ray_inter_cy_extremities(t_ray *ray, t_cy *cy, int x);

#endif
