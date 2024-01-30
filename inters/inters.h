/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inters.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:21:23 by TheTerror         #+#    #+#             */
/*   Updated: 2024/01/25 23:20:45 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERS_H
# define INTERS_H

# include "../minirt.h"

t_bool	ft_ray_inter_sp(t_vars *v, t_sp *sp, int x);
t_bool	ft_ray_inter_pl(t_vars *v, t_pl *pl, int x);
t_bool	ft_assess_color(t_vars *v, double len_found);
double	ft_assessthesolution(double s1, double s2);
t_bool	ft_ray_inter_cy(t_vars *v, t_cy *cy);

#endif
