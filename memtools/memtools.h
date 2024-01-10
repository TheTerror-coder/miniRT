/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memtools.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 20:32:49 by TheTerror         #+#    #+#             */
/*   Updated: 2024/01/10 16:45:09 by lmohin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMTOOLS_H
# define MEMTOOLS_H

# include "../minirt.h"

t_vars	*ft_init_v(void);
t_bool	init_a_sphere(t_vars *v, int *index);
t_bool	init_a_plane(t_vars *v, int *index);
t_bool	init_a_cylindre(t_vars *v, int *index);
void	ft_free_v(t_vars *v);
void	ft_free_sp(t_vars *v);
void	ft_free_pl(t_vars *v);
void	ft_free_cy(t_vars *v);

#endif
