/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:19:02 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/12 18:01:43 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

typedef struct s_tools
{
	unsigned int		i;
	int					sign;
	double				dec;
	double				val;
	double				exp_sign;
	double				n;
}				t_tools;

t_bool	init_skip_optional(t_tools *x, const char *nptr);
t_bool	decimal_sequence(t_tools *x, const char *nptr);
t_bool	optional_exponent(t_tools *x, const char *nptr);

double	ft_atod(const char *nptr)
{
	t_tools	x;

	if (init_skip_optional(&x, nptr))
		return (x.val);
	decimal_sequence(&x, nptr);
	optional_exponent(&x, nptr);
	return (x.val * x.sign);
}

t_bool	init_skip_optional(t_tools *x, const char *nptr)
{
	x->i = 0;
	x->val = 0;
	x->exp_sign = 1;
	x->sign = 1;
	while (nptr[x->i] == ' ' || (nptr[x->i] >= 9 && nptr[x->i] <= 13))
		x->i++;
	if (nptr[x->i] == '+' || nptr[x->i] == '-')
	{
		if (nptr[x->i] == '-')
			x->sign = -1;
		x->i++;
	}
	if (ft_strlen(&nptr[x->i]) < 3)
		return (__FALSE);
	if ((nptr[x->i] == 'i' || nptr[x->i] == 'I') && (nptr[x->i + 1] == 'n' || \
	nptr[x->i + 1] == 'N') && (nptr[x->i + 2] == 'f' || nptr[x->i + 2] == 'F'))
		return (x->val = x->sign * INFINITY, __TRUE);
	if ((nptr[x->i] == 'n' || nptr[x->i] == 'N') && (nptr[x->i + 1] == 'a' || \
	nptr[x->i + 1] == 'A') && (nptr[x->i + 2] == 'n' || nptr[x->i + 2] == 'N'))
		return (x->val = NAN, __TRUE);
	return (__FALSE);
}

t_bool	decimal_sequence(t_tools *x, const char *nptr)
{
	while (nptr[x->i] >= '0' && nptr[x->i] <= '9')
	{
		x->val = (x->val * 10) + (nptr[x->i] - 48);
		x->i++;
	}
	if (nptr[x->i] == '.' && ft_isdigit(nptr[x->i + 1]))
	{
		x->i++;
		x->dec = 10;
		while (nptr[x->i] >= '0' && nptr[x->i] <= '9')
		{
			x->n = 0;
			x->n = (x->n * 10) + (nptr[x->i] - 48);
			x->n /= x->dec;
			x->val += x->n;
			x->dec *= 10;
			x->i++;
		}
	}
	return (__FALSE);
}

t_bool	optional_exponent(t_tools *x, const char *nptr)
{
	size_t	power;

	power = 0;
	if (nptr[x->i] == 'e' || nptr[x->i] == 'E')
	{
		x->i++;
		if (nptr[x->i] == '+' || nptr[x->i] == '-')
		{
			x->exp_sign *= -1;
			x->i++;
		}
		while (nptr[x->i] >= '0' && nptr[x->i] <= '9')
		{
			power = (power * 10) + (nptr[x->i] - 48);
			x->i++;
		}
	}
	if (x->exp_sign > 0)
		return (x->val *= pow(10, power), __FALSE);
	else
		return (x->val /= pow(10, power), __FALSE);
	return (__FALSE);
}
