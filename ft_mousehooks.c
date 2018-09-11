/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mousehooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:57:13 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/10 16:57:15 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** DO NOT TRY TO CHANGE PARAMETER TYPES OF X-Y FROM INT TO DOUBLE
*/

int ft_moved_mouse(int x, int y, t_info *info)
{
	t_mouse *m;
	int fi;

	m = &info->mouse;
	fi = info->fr.interact;
	if (m->stop == 0 && (x >= 0 && x <= info->w && y >= 0 && y <= info->h))
	{
		m->x_prev = m->x;
		m->y_prev = m->y;
		m->x = x;
		m->y = y;
		if (info->psycho == 0 && fi == 1)
			ft_render(info);
	}
	return 0;
}

/*
** DO NOT TRY TO CHANGE PARAMETER TYPES OF X-Y FROM INT TO DOUBLE
*/

int ft_released_mouse(int butt, int x, int y, t_info *info)
{
	t_mouse *m;

	m = &info->mouse;
	(void)butt;
	(void)x;
	(void)y;
	m->pressed = 0;
	return 0;
}

/*
** Hook for the mouse pressed event that is passed to mlx_hook(). It will pass
** "button, x, y" followed by any params also passed to mlx_hook() to the
** function when the mouse is pressed.
*/

int ft_pressed_mouse(int butt, int x, int y, t_info *info)
{
	double fx;
	double fy;
	t_mouse *m;

	m = &info->mouse;
	if (x >= 0 && x <= info->w && y >= 0 && y <= info->h)
	{
		if (butt == 4 || butt == 5)
		{
			m->ratio_x = (double)x / info->w;
			m->ratio_y = (double)y / info->h;
			fx = ft_lint(info->fr.min_x, info->fr.max_x, m->ratio_x);
			fy = ft_lint(info->fr.min_y, info->fr.max_y, m->ratio_y);
			if (butt == 4)
				info->fr.factor_z /= 1.1;
			if (butt == 5)
				info->fr.factor_z *= 1.1;
			info->fr.cent_x = fx;
			info->fr.cent_y = fy;
			info->t_x = 0;
			info->t_y = 0;
			ft_render(info);
		}
	}
	return 0;
}
