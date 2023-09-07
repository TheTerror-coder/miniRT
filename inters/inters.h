/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inters.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:21:23 by TheTerror         #+#    #+#             */
/*   Updated: 2023/09/06 22:31:29 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERS_H
# define INTERS_H

# include "../minirt.h"

t_bool	ft_ray_inter_sp(t_vars *v, t_sp *sp);
t_bool	ft_ray_inter_pl(t_vars *v, t_pl *pl);
t_bool	ft_assess_color(t_vars *v, double len_found);

#endif