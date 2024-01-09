/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmohin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:25:04 by lmohin            #+#    #+#             */
/*   Updated: 2024/01/09 16:55:50 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_bool	scene_error(char *str, size_t line_index)
{
	ft_printf("scene parsing - line %u: ", line_index);
	return (ft_error(str));
}

size_t	ft_countchar(char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}	
	
