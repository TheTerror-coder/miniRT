/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:19:02 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/19 21:20:24 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

typedef struct s_tools
{
	unsigned int		i;
	int					sign;
	double				dec;
	double				fdb;
	double				n;
}				t_tools;

void	ft_init_skip(t_tools *x, const char *nptr);

double	ft_atod(const char *nptr)
{
	t_tools	x;

	ft_init_skip(&x, nptr);
	while (nptr[x.i] >= '0' && nptr[x.i] <= '9')
	{
		x.fdb = (x.fdb * 10) + (nptr[x.i] - 48);
		x.i++;
	}
	if (nptr[x.i] == '.' && ft_isdigit(nptr[x.i + 1]))
	{
		x.i++;
		x.dec = 10;
		while (nptr[x.i] >= '0' && nptr[x.i] <= '9')
		{
			x.n = 0;
			x.n = (x.n * 10) + (nptr[x.i] - 48);
			x.n /= x.dec;
			x.fdb += x.n;
			x.dec *= 10;
			x.i++;
		}
	}
	return (x.fdb * x.sign);
}

void	ft_init_skip(t_tools *x, const char *nptr)
{
	x->i = 0;
	x->fdb = 0;
	x->sign = 1;
	while (nptr[x->i] == ' ' || (nptr[x->i] >= 9 && nptr[x->i] <= 13))
		x->i++;
	if (nptr[x->i] == '+' || nptr[x->i] == '-')
	{
		if (nptr[x->i] == '-')
			x->sign = -1;
		x->i++;
	}
}
