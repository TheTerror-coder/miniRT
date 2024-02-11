/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:25:04 by lmohin            #+#    #+#             */
/*   Updated: 2024/02/11 13:20:48 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_bool	scene_error(char *str, size_t line_index)
{
	ft_printf("scene parsing - line %u: ", line_index);
	return (ft_error(str));
}

size_t	countchar(char *str, char c)
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

t_bool	check_format(char *file)
{
	size_t	i;

	i = ft_strlen(file);
	while (i != 0 && file[i] != '.')
		i--;
	if (ft_strncmp(file + i, ".rt", 4))
	{
		ft_putendl_fd("invalid file extension", STDERR_FILENO);
		return (__FALSE);
	}
	return (__TRUE);
}
