/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:23:31 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/10 16:31:28 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mathtools.h"

double	degtorad(double alpha)
{
	double	pi;

	pi = 3.14159265358979323846264338327950288;
	return ((alpha * pi) / 180);
}

double	radtodeg(double alpha)
{
	double	pi;

	pi = 3.14159265358979323846264338327950288;
	return ((alpha * 180) / pi);
}
