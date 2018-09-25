/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:34:01 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/19 14:34:02 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Initializes the zoom factor, center X Y coordinates of our fractal as
**	well as the width of our X Y dimensions.
*/

void	ft_init_julia(void *en)
{
	t_info	*info;

	info = (t_info *)en;
	info->fr.factor_z = 1;
	info->fr.d = 2;
	info->fr.abs = 0;
	info->fr.interact = 1;
	info->fr.cent_x = 0.0;
	info->fr.cent_y = 0.0;
	info->fr.wid_x = 4.0;
	info->fr.wid_y = 4.0;
}

void	ft_init_trijulia(void *en)
{
	t_info	*info;

	info = (t_info *)en;
	info->fr.factor_z = 1;
	info->fr.d = 3;
	info->fr.abs = 0;
	info->fr.interact = 1;
	info->fr.cent_x = 0.0;
	info->fr.cent_y = 0.0;
	info->fr.wid_x = 4.0;
	info->fr.wid_y = 4.0;
}

void	ft_init_quadjulia(void *en)
{
	t_info	*info;

	info = (t_info *)en;
	info->fr.factor_z = 1;
	info->fr.d = 4;
	info->fr.abs = 0;
	info->fr.interact = 1;
	info->fr.cent_x = 0.0;
	info->fr.cent_y = 0.0;
	info->fr.wid_x = 4.0;
	info->fr.wid_y = 4.0;
}

/*
**	The julia set is very similar to the mandelbrot set.
**	The only difference is that the c value is determined by the position of the
**	mouse cursor.
*/

void	ft_julia(void *en, int pix_id)
{
	t_fract	fr;
	t_info	*info;

	info = (t_info *)en;
	fr = info->fr;
	fr.x = pix_id % info->w;
	fr.y = pix_id / info->w;
	if (info->psycho == 0)
	{
		fr = ft_calc_min_max_fract(info, fr);
		info->fr = fr;
		fr.c.real = ft_linint(-fr.wid_x / 2, fr.wid_x / 2, \
			info->mouse.x / info->w);
		fr.c.imag = ft_linint(-fr.wid_y / 2, fr.wid_y / 2, \
			info->mouse.y / info->h);
		fr.z.real = ft_linint(fr.min_x, fr.max_x, (float)fr.x / info->w);
		fr.z.imag = ft_linint(fr.min_y, fr.max_y, (float)fr.y / info->h);
		info->buff_iter[pix_id] = ft_fr_esc_time(info, fr);
	}
	ft_img_put_pix(info, fr.x, fr.y, ft_choose_clr(info, \
		info->buff_iter[pix_id]));
}
