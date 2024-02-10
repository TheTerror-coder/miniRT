/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:33:56 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/10 16:51:46 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "memtools.h"

t_vars	*init_v(void)
{
	t_vars	*v;

	v = ft_calloc(1, sizeof(t_vars));
	if (!v)
		exit(1);
	v->im = ft_calloc(1, sizeof(t_img));
	v->ray = ft_calloc(1, sizeof(t_ray));
	v->ray->len = -1;
	v->ray->obj.type = __NOTHING;
	return (v);
}
