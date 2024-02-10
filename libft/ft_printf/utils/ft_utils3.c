/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:29:44 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/10 17:25:46 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void	checkprecision(t_vars *v)
{
	int	i;

	i = v->i;
	if (v->fmt[i + 1] == '.')
	{
		i++;
		v->_dot = __TRUE;
		if (ft_isdigit(v->fmt[i + 1]))
		{
			v->precision = ft_atoi(&v->fmt[i + 1]);
			i += ft_nbrlen((long long int) v->precision);
		}
		else
			v->precision = 0;
	}
	v->i = i;
}

void	checkflags(t_vars *v)
{
	int	i;

	i = v->i;
	while (ft_isflag(v->fmt[i + 1]))
	{
		v->_noflag = __FALSE;
		if (v->fmt[i + 1] == '-')
			v->_minus = __TRUE;
		else if (v->fmt[i + 1] == '0')
			v->_zero = __TRUE;
		else if (v->fmt[i + 1] == '#')
			v->_sharp = __TRUE;
		else if (v->fmt[i + 1] == ' ')
			v->_space = __TRUE;
		else if (v->fmt[i + 1] == '+')
			v->_plus = __TRUE;
		i++;
	}
	v->i = i;
}

void	checkwidth(t_vars *v)
{
	int	i;

	i = v->i;
	if (ft_iswidth(v->fmt[i + 1]))
	{
		v->width = ft_atoi(&v->fmt[i + 1]);
		i += ft_nbrlen((long long int) v->width);
	}
	v->i = i;
}

t_bool	checkoptionals(t_vars *v)
{
	checkflags(v);
	checkwidth(v);
	checkprecision(v);
	return (__TRUE);
}
