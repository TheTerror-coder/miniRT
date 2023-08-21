/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathtools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:36:23 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/18 18:54:38 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHTOOLS_H
# define MATHTOOLS_H

# include "../minirt.h"

t_coord	*ft_pointsdiff(t_coord *end, t_coord *origin);
double	ft_vectornorm(t_vec *vector);
double	ft_vectornormsqr(t_vec *vector);
void	ft_setvec_coords(t_vec *vector);
double	ft_vecdotvec(t_vec *vec2, t_vec *vec1, const double angle);
t_vec	*ft_vecdotpt(t_vec *vector, t_coord *point);
t_vec	*ft_vecdotconst(t_vec *vector, const double k);

#endif
