/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightning.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmohin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:38:48 by lmohin            #+#    #+#             */
/*   Updated: 2024/02/07 10:54:17 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTNING_H
# define LIGHTNING_H

# include "../minirt.h"

t_bool	lightning(t_vars *v, int i, int j);
t_bool	is_shadows(t_vars *v, t_ray *light_ray, int i, int j);
t_bool	plane_lightning(t_vars *v, t_ray light_ray, int i, int j);
t_bool	sphere_lightning(t_vars *v, t_ray light_ray, int i, int j);

t_bool	light_side_test(t_vec normal_obj, t_ray light_ray, t_ray main_ray);

int		amb_color(t_amb amb, int obj_color);
int		enlightened_color(t_vars *v, t_ray light_ray, double scalar);

t_vec	get_normal_sphere(t_sp sphere, t_ray main_ray);

#endif
