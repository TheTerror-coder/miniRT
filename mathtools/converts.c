/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:23:31 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/21 20:35:19 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mathtools.h"

double	ft_degtorad(double alpha)
{
	double	pi;

	pi = 3.14159265358979323846264338327950288;
	return ((alpha * pi) / 180);
}

double	ft_radtodeg(double alpha)
{
	double	pi;

	pi = 3.14159265358979323846264338327950288;
	return ((alpha * 180) / pi);
}
