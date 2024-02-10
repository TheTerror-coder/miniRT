/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:32:00 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/10 17:07:34 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "memtools.h"

void	free_im(t_vars *v);
void	free_mlx(t_vars *v);
void	free_elms(t_vars *v);

void	free_v(t_vars *v)
{
	ft_freestr(&v->file);
	free_im(v);
	free_mlx(v);
	free_elms(v);
	free(v->ray);
	free(v);
}

void	free_elms(t_vars *v)
{
	if (v->amb)
		free(v->amb);
	if (v->cam)
		free(v->cam);
	if (v->light)
		free(v->light);
	free_sp(v);
	free_pl(v);
	free_cy(v);
}

void	free_im(t_vars *v)
{
	if(!v->im)
		return ;
	if (v->im->img)
		mlx_destroy_image(v->xptr, v->im->img);
	free(v->im);
	v->im = NULL;
}
void	free_mlx(t_vars *v)
{
	if (v->win)
	{
		mlx_clear_window(v->xptr, v->win);
		mlx_destroy_window(v->xptr, v->win);
	}
	if (v->xptr)
	{
		mlx_destroy_display(v->xptr);
		free(v->xptr);
	}
	v->xptr = NULL;
}
