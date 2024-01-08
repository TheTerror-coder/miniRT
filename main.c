/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:30:47 by TheTerror         #+#    #+#             */
/*   Updated: 2024/01/08 21:19:42 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_vars	*v;

	v = ft_init_v();
	if (!parse_args(v, argc, argv))
		ft_exitprocss(v, EXIT_FAILURE);
	if (!ft_set_mlx(v))
		ft_exitprocss(v, EXIT_FAILURE);
	ft_minirt(v);
	ft_events(v);
	mlx_loop(v->xptr);
	return (0);
}

void	ft_exitprocss(t_vars *v, int status)
{
	ft_free_v(v);
	exit(status);
}
