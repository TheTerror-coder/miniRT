/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inters.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:21:23 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/13 14:27:12 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERS_H
# define INTERS_H

# include "../minirt.h"

/*
	cy_extremities.c struct tools
*/
typedef struct s_ray_cy_extremities_variables
{
	t_coord	pt_ph;
	double	t;
	double	norm_phpi;
	double	c1;
	double	c2;
	double	c3;
	double	c4;
	double	c5;
	double	c6;
	int		x;
}				t_cyvars;

/*
	ray_sphere.c struct variables
*/
typedef struct s_ray_sphere_vars
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	s1;
	double	s2;
}				t_spvars;

typedef struct s_ray_plane_variables
{
	t_vec	p_ro;
	t_coord	ray_o;
	double	num;
	double	denom;
	double	length;
}				t_plvars;

t_bool	ray_inter_sp(t_ray *ray, t_sp *sp, int x);
t_bool	ray_inter_pl(t_ray *ray, t_pl *pl, int x);
t_bool	assess_color(t_ray *ray, double len_found);
double	assess_the_solution(double s1, double s2);
t_bool	ray_inter_cy(t_ray *ray, t_cy *cy, int x);

#endif
