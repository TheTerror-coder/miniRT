/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathtools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:36:23 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/10 16:32:09 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHTOOLS_H
# define MATHTOOLS_H

# include "../minirt.h"

void	pointsdiff(t_coord *end, t_coord *origin, t_vec *res);
double	vectornorm(t_vec *vector);
double	vectornormsqr(t_vec *vector);
void	setvec_coords(t_vec *vector);
double	vecdotvec(t_vec *vec1, t_vec *vec2);
t_vec	vecdotpt(t_vec *vector, t_coord *point);
t_vec	vecdotconst(t_vec *vector, const double k);
double	degtorad(double alpha);
double	radtodeg(double alpha);
double	__sq(double n);
void	vectornormalize(t_vec *vec, t_vec *normvec);

#endif
