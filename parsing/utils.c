/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmohin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 20:25:04 by lmohin            #+#    #+#             */
/*   Updated: 2024/01/08 20:26:50 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_bool	scene_error(char *str, size_t line_index)
{
	ft_printf("scene parsing - line %u: ", line_index);
	return (ft_error(str));
}
