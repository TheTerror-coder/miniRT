/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:48:23 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/11 15:13:19 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	set_mlx(t_vars *v)
{
	v->xptr = mlx_init();
	if (!v->xptr)
		return (__FALSE);
	v->win = mlx_new_window(v->xptr, _SIZE_X, _SIZE_Y, "miniRT");
	if (!v->win)
		return (__FALSE);
	v->im->img = mlx_new_image(v->xptr, _WIDHT, _HEIGHT);
	if (!v->im->img)
		return (__FALSE);
	v->im->addr = mlx_get_data_addr(v->im->img, &(v->im->bpp), \
					&(v->im->size_line), &(v->im->endian));
	return (__TRUE);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
