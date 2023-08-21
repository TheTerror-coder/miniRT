/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:30:47 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/20 22:56:22 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_vars	*v;

	(void) argc;
	(void) argv;
	v = ft_init_v();
	if (!ft_parse(v, argc, argv))
		ft_exitprocss(v, EXIT_FAILURE);
	if (!ft_set_mlx(v))
		ft_exitprocss(v, EXIT_FAILURE);
	ft_events(v);
	mlx_loop(v->xptr);
	return (0);
}

void	ft_exitprocss(t_vars *v, int status)
{
	ft_free_v(v);
	exit(status);
}
