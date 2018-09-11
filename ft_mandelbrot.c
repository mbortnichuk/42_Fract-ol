/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 12:15:26 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/07 12:15:27 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Initializes the zoom factor, center "x y" coords of our fractal as well as
** the width of our "x y" dimensions.
*/

void ft_init_mandelbrot(void *env)
{
	t_info *info;

	info = (t_info*)env;
	info->fr.factor_z = 1;
	info->fr.d = 2;
	info->fr.abs = 0;
	info->fr.interact = 0;
	info->fr.cent_x = -0.5;
	info->fr.cent_y = 0.0;
	info->fr.wid_x = 3.5;
	info->fr.wid_y = 2.5;
}

void ft_init_tribrot(void *env)
{
	t_info *info;

	info = (t_info*)env;
	info->fr.factor_z = 1;
	info->fr.d = 3;
	info->fr.abs = 0;
	info->fr.interact = 0;
	info->fr.cent_x = 0.0;
	info->fr.cent_y = 0.0;
	info->fr.wid_x = 4.0;
	info->fr.wid_y = 3;
}

void ft_init_quabrot(void *env)
{
	t_info *info;

	info = (t_info*)env;
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
** Basic Mandelbrot, where "c" is determined based on a pixel's location
** in a bounded area.
*/

void ft_mandelbrot(void *env, int pix_id)
{
	t_fract fr;
	t_info *info;

	info = (t_info*)env;
	fr = info->fr;
	fr.x = pix_id % info->w;
	fr.y = pix_id / info->w;
	if (info->psycho == 0)
	{
		fr = ft_calc_min_max_fractal(info, fr);
		info->fr = fr;
		fr.c.real = ft_lint(fr.min_x, fr.max_x, (float)fr.x / info->w);
		fr.c.imag = ft_lint(fr.min_y, fr.max_y, (float)fr.y / info->h);
		fr.z.real = 0;
		fr.z.imag = 0;
		info->buff_iter[pix_id] = ft_esc_time(info, fr);
	}
	ft_image_put_pixel(info, fr.x, fr.y, ft_clr_choose(info, info->buff_iter[pix_id]));
}
