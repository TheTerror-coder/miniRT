/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathtools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:36:23 by TheTerror         #+#    #+#             */
/*   Updated: 2023/09/08 15:56:16 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHTOOLS_H
# define MATHTOOLS_H

# include "../minirt.h"

void	ft_pointsdiff(t_coord *end, t_coord *origin, t_vec *res);
double	ft_vectornorm(t_vec *vector);
double	ft_vectornormsqr(t_vec *vector);
void	ft_setvec_coords(t_vec *vector);
double	ft_vecdotvec(t_vec *vec1, t_vec *vec2);
t_vec	ft_vecdotpt(t_vec *vector, t_coord *point);
t_vec	ft_vecdotconst(t_vec *vector, const double k);
double	ft_degtorad(double alpha);
double	ft_radtodeg(double alpha);
double	ft_sq(double n);
void	ft_vectornormalize(t_vec *vec, t_vec *normvec);

#endif
