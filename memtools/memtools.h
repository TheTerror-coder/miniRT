/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memtools.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:32:49 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/10 16:52:47 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMTOOLS_H
# define MEMTOOLS_H

# include "../minirt.h"

t_vars	*init_v(void);
t_bool	init_a_sphere(t_vars *v, int *index);
t_bool	init_a_plane(t_vars *v, int *index);
t_bool	init_a_cylindre(t_vars *v, int *index);
void	free_v(t_vars *v);
void	free_sp(t_vars *v);
void	free_pl(t_vars *v);
void	free_cy(t_vars *v);

#endif
