/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:33:56 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/18 16:17:48 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "memtools.h"

t_vars	*ft_init_v(void)
{
	t_vars	*v;

	v = ft_calloc(1, sizeof(t_vars));
	if (!v)
		exit(1);
	v->im = ft_calloc(1, sizeof(t_img));
	return (v);
}
