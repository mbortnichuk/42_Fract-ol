/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:40:34 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/19 14:40:36 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_mandelbrot(void *en)
{
	t_info	*info;

	info = (t_info *)en;
	info->fr.factor_z = 1;
	info->fr.d = 2;
	info->fr.abs = 0;
	info->fr.interact = 0;
	info->fr.cent_x = -0.5;
	info->fr.cent_y = 0.0;
	info->fr.wid_x = 3.5;
	info->fr.wid_y = 2.5;
}

void	ft_init_tribrot(void *en)
{
	t_info	*info;

	info = (t_info *)en;
	info->fr.factor_z = 1;
	info->fr.d = 3;
	info->fr.abs = 0;
	info->fr.interact = 0;
	info->fr.cent_x = 0.0;
	info->fr.cent_y = 0.0;
	info->fr.wid_x = 4.0;
	info->fr.wid_y = 3;
}

void	ft_init_quadrobrot(void *en)
{
	t_info	*info;

	info = (t_info *)en;
	info->fr.factor_z = 1;
	info->fr.d = 4;
	info->fr.abs = 0;
	info->fr.interact = 0;
	info->fr.cent_x = 0.0;
	info->fr.cent_y = 0.0;
	info->fr.wid_x = 4.0;
	info->fr.wid_y = 3;
}

/*
**	Basic mandelbrot set where 'c' is determined based on a pixel's location
**	in a bounded area (see: fractal_setup_?.c functions to derive bounds)
*/

void	ft_mandelbrot(void *en, int pix_id)
{
	t_fract	fr;
	t_info	*info;

	info = (t_info *)en;
	fr = info->fr;
	fr.x = pix_id % info->w;
	fr.y = pix_id / info->w;
	if (info->psycho == 0)
	{
		fr = ft_calc_min_max_fract(fr, info);
		info->fr = fr;
		fr.c.real = ft_linint((float)fr.x / info->w, fr.min_x, fr.max_x);
		fr.c.imag = ft_linint((float)fr.y / info->h, fr.min_y, fr.max_y);
		fr.z.real = 0;
		fr.z.imag = 0;
		info->buff_iter[pix_id] = ft_fr_esc_time(fr, info);
	}
	ft_img_put_pix(info, fr.x, fr.y, \
		ft_choose_clr(info->buff_iter[pix_id], info));
}
