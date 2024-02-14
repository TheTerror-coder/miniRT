/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:50:05 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/13 17:55:52 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathtools.h"

double	__sq(double n)
{
	return (n * n);
}

double	__sqrt(double n)
{
	if (n <= 0.000001 && n >= -0.000001)
		return (0);
	else if (n < 0)
		return (0);
	else
		return (sqrt(n));
}
