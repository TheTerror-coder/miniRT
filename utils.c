/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:54:01 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/23 16:17:38 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	ft_check(const char *str, int i, int *coma)
{
	if (str[i] == '.')
	{
		if (i == 0)
			return (__FALSE);
		else if (i && *coma)
			return (__FALSE);
		*coma += 1;
		return (__TRUE);
	}
	if (!i && !ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
		return (__FALSE);
	else if (i && !ft_isdigit(str[i]))
		return (__FALSE);
	return (__TRUE);
}

t_bool	ft_isnumber(const char *str)
{
	int	i;
	int	coma;

	i = 0;
	coma = 0;
	while (str[i])
	{
		if (!ft_check(str, i, &coma))
			return (__FALSE);
		i++;
	}
	return (__TRUE);
}

t_bool	ft_error(char *str)
{
	ft_putendl_fd("error", STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
	return (__FALSE);
}

int	ft_color(t_rgb *rgb)
{
	int	result;

	result = rgb->r<<16;
	result += rgb->g<<8;
	result += rgb->b;
	return (result);
}
