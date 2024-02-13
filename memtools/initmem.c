/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:33:56 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/13 14:30:19 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memtools.h"

void	calloc_error(void)
{
	ft_putstr_fd("Error\nft_calloc() failed\n", 2);
	exit(1);
}

t_vars	*init_v(void)
{
	t_vars	*v;

	v = ft_calloc(1, sizeof(t_vars));
	if (!v)
		calloc_error();
	v->im = ft_calloc(1, sizeof(t_img));
	if (!v->im)
	{
		free(v);
		calloc_error();
	}
	v->ray = ft_calloc(1, sizeof(t_ray));
	if (!v->ray)
	{
		free(v->im);
		free(v);
		calloc_error();
	}
	v->ray->len = -1;
	v->ray->obj.type = __NOTHING;
	return (v);
}
