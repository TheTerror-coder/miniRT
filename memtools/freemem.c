/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freemem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:32:00 by TheTerror         #+#    #+#             */
/*   Updated: 2023/08/20 17:29:45 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "memtools.h"

void	ft_free_im(t_vars *v);
void	ft_free_mlx(t_vars *v);
void	ft_free_elms(t_vars *v);

void	ft_free_v(t_vars *v)
{
	ft_freestr(&v->file);
	ft_free_im(v);
	ft_free_mlx(v);
	ft_free_elms(v);
	free(v);
}

void	ft_free_elms(t_vars *v)
{
	if (v->a)
		free(v->a);
	if (v->c)
		free(v->c);
	if (v->l)
		free(v->l);
	ft_free_sp(v);
	ft_free_pl(v);
	ft_free_cy(v);
}

void	ft_free_im(t_vars *v)
{
	if(!v->im)
		return ;
	if (v->im->img)
		mlx_destroy_image(v->xptr, v->im->img);
	free(v->im);
	v->im = NULL;
}
void	ft_free_mlx(t_vars *v)
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
