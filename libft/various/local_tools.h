/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_tools.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:06:01 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/13 14:34:21 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOCAL_TOOLS_H
# define LOCAL_TOOLS_H

# include "../libft.h"

/*
	ft_atod() struct including all util variables
*/
typedef struct s_atod_variables
{
	unsigned int		i;
	int					sign;
	double				dec;
	double				val;
	double				exp_sign;
	double				n;
}				t_atod_vars;

#endif
