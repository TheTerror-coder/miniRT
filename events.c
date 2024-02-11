/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:20:10 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/11 15:10:56 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_keyhook(int keycode, t_vars *v)
{
	if (keycode == __ESC)
		exitprocss(v, EXIT_SUCCESS);
	return (0);
}

int	ft_xbutton_close(t_vars *v)
{
	exitprocss(v, EXIT_SUCCESS);
	return (0);
}

void	events(t_vars *v)
{
	mlx_hook(v->win, __ON_DESTROY, 0, ft_xbutton_close, v);
	mlx_hook(v->win, __ON_KEYUP, __KEYRELEASEMASK, ft_keyhook, v);
}
