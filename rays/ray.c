/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TheTerror <jfaye@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:05:07 by TheTerror         #+#    #+#             */
/*   Updated: 2024/02/11 15:08:08 by TheTerror        ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_bool	rotate_to_3dwrld(t_vars *v, t_vec *localray);
t_bool	setcam_base(t_vars *v, t_vec *cam_u, t_vec *cam_v, t_vec *cam_w);
t_bool	in3dcamera(t_vars *v, t_vec *localray, int i, int j);
t_bool	definecam_up(t_vec *cam_w, t_vec *cam_up);

t_bool	set_ray(t_vars *v, int i, int j)
{
	t_vec	localray;

	in3dcamera(v, &localray, i, j);
	rotate_to_3dwrld(v, &localray);
	v->ray->o.x = v->cam->pov.x;
	v->ray->o.y = v->cam->pov.y;
	v->ray->o.z = v->cam->pov.z;
	v->ray->len = -1;
	return (__TRUE);
}

t_bool	in3dcamera(t_vars *v, t_vec *localray, int i, int j)
{
	localray->x = (i - (_WIDHT / 2.00));
	localray->y = (-j + (_HEIGHT / 2.00));
	localray->z = (-_WIDHT / (2.00 * tan(degtorad(v->cam->fov) / 2.00)));
	return (__TRUE);
}

t_bool	rotate_to_3dwrld(t_vars *v, t_vec *localray)
{
	t_vec	cam_u;
	t_vec	cam_v;
	t_vec	cam_w;

	setcam_base(v, &cam_u, &cam_v, &cam_w);
	v->ray->dir.x = (cam_u.x * localray->x) + (cam_v.x * localray->y) \
					+ (cam_w.x * localray->z);
	v->ray->dir.y = (cam_u.y * localray->x) + (cam_v.y * localray->y) \
					+ (cam_w.y * localray->z);
	v->ray->dir.z = (cam_u.z * localray->x) + (cam_v.z * localray->y) \
					+ (cam_w.z * localray->z);
	vectornormalize(&v->ray->dir, &v->ray->dir);
	return (__TRUE);
}

t_bool	setcam_base(t_vars *v, t_vec *cam_u, t_vec *cam_v, t_vec *cam_w)
{
	t_vec	cam_up;
	t_vec	dir;

	vectornormalize(&v->cam->dir, &dir);
	cam_w->x = -dir.x;
	cam_w->y = -dir.y;
	cam_w->z = -dir.z;
	vectornormalize(cam_w, cam_w);
	definecam_up(cam_w, &cam_up);
	cam_u->x = (cam_up.y * cam_w->z) - (cam_up.z * cam_w->y);
	cam_u->y = (cam_up.z * cam_w->x) - (cam_up.x * cam_w->z);
	cam_u->z = (cam_up.x * cam_w->y) - (cam_up.y * cam_w->x);
	vectornormalize(cam_u, cam_u);
	cam_v->x = (cam_w->y * cam_u->z) - (cam_w->z * cam_u->y);
	cam_v->y = (cam_w->z * cam_u->x) - (cam_w->x * cam_u->z);
	cam_v->z = (cam_w->x * cam_u->y) - (cam_w->y * cam_u->x);
	vectornormalize(cam_v, cam_v);
	return (__TRUE);
}

t_bool	definecam_up(t_vec *cam_w, t_vec *cam_up)
{
	cam_up->x = 0;
	cam_up->y = 1;
	cam_up->z = 0;
	if (!cam_w->x && !cam_w->z && cam_w->y)
	{
		if (cam_w->y < 0)
		{
			cam_up->x = 0;
			cam_up->y = 0;
			cam_up->z = 1;
		}
		else
		{
			cam_up->x = 0;
			cam_up->y = 0;
			cam_up->z = -1;
		}
	}
	return (__TRUE);
}
