/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 19:54:01 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/13 14:45:24 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_bool	check(const char *str, int i, int *coma)
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

t_bool	is_uint(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (__FALSE);
		i++;
	}
	return (__TRUE);
}

t_bool	isnumber(const char *str)
{
	int	i;
	int	coma;

	i = 0;
	coma = 0;
	while (str[i])
	{
		if (!check(str, i, &coma))
			return (__FALSE);
		i++;
	}
	return (__TRUE);
}

t_bool	ft_error(char *str)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(str, STDERR_FILENO);
	return (__FALSE);
}

int	compute_color(t_rgb *rgb)
{
	int	result;

	result = rgb->r << 16;
	result += rgb->g << 8;
	result += rgb->b;
	return (result);
}
