/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:48:23 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/13 14:40:00 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_bool	mlx_error(char *error_msg)
{
	ft_putstr_fd(error_msg, 2);
	return (__FALSE);
}

t_bool	set_mlx(t_vars *v)
{
	v->xptr = mlx_init();
	if (!v->xptr)
		return (mlx_error("Error\nmlx_init() failed\n"));
	v->win = mlx_new_window(v->xptr, _SIZE_X, _SIZE_Y, "miniRT");
	if (!v->win)
		return (mlx_error("Error\nmlx_new_window failed\n"));
	v->im->img = mlx_new_image(v->xptr, _WIDHT, _HEIGHT);
	if (!v->im->img)
		return (mlx_error("Error\nmlx_new_image failed\n"));
	v->im->addr = mlx_get_data_addr(v->im->img, &(v->im->bpp),
			&(v->im->size_line), &(v->im->endian));
	return (__TRUE);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
