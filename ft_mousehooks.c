/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mousehooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:46:45 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/19 14:46:46 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	NOTE: DO NOT TRY TO CHANGE THE PARAMETER TYPES OF X & Y FROM INT TO DOUBLE
*/

int		ft_moved_mouse(int x, int y, t_info *info)
{
	t_mouse		*mouse;
	int			f_i;

	mouse = &info->mouse;
	f_i = info->fr.interact;
	if (mouse->stop == 0 && (x >= 0 && x <= info->w && y >= 0 && y <= info->h))
	{
		mouse->x_prv = mouse->x;
		mouse->y_prv = mouse->y;
		mouse->x = x;
		mouse->y = y;
		if (info->psycho == 0 && f_i == 1)
			ft_render(info);
	}
	return (0);
}

/*
**	NOTE: DO NOT TRY TO CHANGE THE PARAMETER TYPES OF X & Y FROM INT TO DOUBLE
*/

int		ft_released_mouse(int button, int x, int y, t_info *info)
{
	t_mouse		*mouse;

	mouse = &info->mouse;
	(void)button;
	(void)x;
	(void)y;
	mouse->pressed = 0;
	return (0);
}

/*
**	Hook for the mouse pressed event that is passed to
**	mlx_hook(). mlx_hook() will pass "int button, int x, int y" followed by
**	any params also passed to mlx_hook() to the function when the mouse is
**	pressed.
**
**	4 = mouse scroll wheel down - decrease the zoom factor
**	5 = mouse scroll wheel up - increase the the zoom factor
**
**	NOTE: all X Y coordinates reported to the mouse hook functions will
**	have (0, 0) being the BOTTOM LEFT CORNER of the window. (WIN_W, WIN_H) will
**	thus be the TOP RIGHT CORNER of the window which is completely different
**	from the image's (0,0) which is TOP LEFT CORNER
**
**	NOTE: DO NOT TRY TO CHANGE THE PARAMETER TYPES OF X  Y FROM INT TO DOUBLE
**	Doing so will corrupt the addressing of your params and give you segfaults
**	that will take you possibly hundreds of hours to debug
*/

int		ft_pressed_mouse(int button, int x, int y, t_info *info)
{
	double		fx;
	double		fy;
	t_mouse		*mouse;

	mouse = &info->mouse;
	if (x >= 0 && x <= info->w && y >= 0 && y <= info->h)
	{
		if (button == 4 || button == 5)
		{
			mouse->ratio_x = (double)x / info->w;
			mouse->ratio_y = (double)y / info->h;
			fx = ft_linint(mouse->ratio_x, info->fr.min_x, info->fr.max_x);
			fy = ft_linint(mouse->ratio_y, info->fr.min_y, info->fr.max_y);
			if (button == 4)
				info->fr.factor_z /= 1.1;
			if (button == 5)
				info->fr.factor_z *= 1.1;
			info->fr.cent_x = fx;
			info->fr.cent_y = fy;
			info->t_x = 0;
			info->t_y = 0;
			ft_render(info);
		}
	}
	return (0);
}
