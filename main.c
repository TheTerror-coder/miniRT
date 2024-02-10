/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:30:47 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/10 16:57:06 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_vars	*v;

	v = init_v();
	if (!parse_args(v, argc, argv))
		exitprocss(v, EXIT_FAILURE);
	if (!set_mlx(v))
		exitprocss(v, EXIT_FAILURE);
	minirt(v);
	events(v);
	mlx_loop(v->xptr);
	return (0);
}

void	exitprocss(t_vars *v, int status)
{
	free_v(v);
	exit(status);
}
