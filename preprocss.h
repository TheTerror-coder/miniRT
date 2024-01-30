/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocss.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:41:14 by TheTerror         #+#    #+#             */
/*   Updated: 2024/01/25 15:20:47 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREPROCSS_H
# define PREPROCSS_H

# include "./libft/libft.h"

# define _SIZE_X_HONOR 1920		//screen's widht of the PC HONOR MAGICBOOK
# define _SIZE_Y_HONOR 1080		//screen's height of the PC HONOR MAGICBOOK
# define _SIZE_X_MAC 2840		//screen's widht of 42's MAC
# define _SIZE_Y_MAC 2160		//screen's height of 42's MAC

# define _SIZE_X _SIZE_X_HONOR 		//window's x size
# define _SIZE_Y _SIZE_Y_HONOR 		//window's y size
# define _WIDHT  _SIZE_X			//image's widht
# define _HEIGHT _SIZE_Y 			//image's height

# define __NTR -100 		//Nothing To Report
# define __ON_DESTROY 17 	//Button x window killer
# define __ON_KEYUP 03
# define __ON_MOUSEDOWN 04
# define __KEYRELEASEMASK 2L
# define __BUTTONPRESSMASK 4L

/*KEYCODES*/
# define __ESC 65307 		//ESCape key
# define __H_ 104 			//h key
# define __L_ 108 			//l key
# define __ZOOMIN 4 		//mouse wheel
# define __ZOOMOUT 5 		//mouse wheel
# define __LEFT 65361 		//left key
# define __RIGHT 65363 		//right key
# define __UP 65362 		//up key
# define __DOWN 65364 		//down key
# define __LEFTBUTTON 1 	//mouse's left button
# define __RIGHTBUTTON 3 	//mouse's right button
# define __WHEELBUTTON 2 	//mouse's wheel button


typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct s_coordinates
{
	double	x;
	double	y;
	double	z;
}				t_coord;

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
	t_coord	o;
	t_coord	e;
}				t_vec;

typedef struct s_img
{
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	void	*img;
}				t_img;

typedef struct s_ambient
{
	double	ratio;
	t_rgb	rgb;
}				t_amb;

typedef struct s_camera
{
	t_coord	pov;
	t_vec	dir;
	double	fov;
}				t_cam;

typedef struct s_light
{
	t_coord	pol;
	double	ratio;
	t_rgb	rgb;
}				t_light;

typedef struct s_sphere
{
	t_coord	o;
	double	d;
	t_rgb	rgb;
}				t_sp;

typedef struct s_plane
{
	t_coord	p;
	t_vec	normal;
	t_rgb	rgb;
}				t_pl;

typedef struct s_cylindre
{
	t_coord	o;
	t_vec	axis;
	double	d;
	double	r;
	double	h;
	t_rgb	rgb;
}				t_cy;

typedef struct s_ray
{
	t_coord	o;
	t_vec	dir;
	int		color;
	double	len;
}				t_ray;

typedef struct obj
{
	int	type;
	int	index;
}				t_obj;

typedef struct s_variables
{
	void	*xptr;
	void	*win;
	t_img	*im;
	char	*file;
	t_amb	*amb;
	t_cam	*cam;
	t_light	*light;
	t_sp	**sp;
	t_pl	**pl;
	t_cy	**cy;
	t_ray	ray;
	t_obj	obj;
}				t_vars;

typedef struct s_parameters
{
	double	k;
	double	f;
	double	g;
	double	h;
	double	alpha;
	double	beta;
	double	lamda;
	double	e;
	double	l;
	double	m;
	double	n;
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t1;
	double	t2;
	double	hp1;
	double	hp2;
}				t_params;

#endif
