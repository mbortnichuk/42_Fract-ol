/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 12:45:47 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/07 12:45:48 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Initializes the zoom factor, center "x y" coords of our fractal as well as
** the width of our "x y" dimesions.
*/

void ft_init_julia(void *env)
{
	t_info *info;

	info = (t_info*)env;
	info->fr.factor_z = 1;
	info->fr.d = 2;
	info->fr.abs = 0;
	info->fr.interact = 1;
	info->fr.cent_x = 0.0;
	info->fr.cent_y = 0.0;
	info->fr.wid_x = 4.0;
	info->fr.wid_y = 4.0;
}

void ft_init_trijulia(void *env)
{
	t_info *info;

	info = (t_info*)env;
	info->fr.factor_z = 1;
	info->fr.d = 3;
	info->fr.abs = 0;
	info->fr.interact = 1;
	info->fr.cent_x = 0.0;
	info->fr.cent_y = 0.0;
	info->fr.wid_x = 4.0;
	info->fr.wid_y = 4.0;
}

void ft_init_quajulia(void *env)
{
	t_info *info;

	info = (t_info*)env;
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
** Julia is very similar to the mandelbrot. The only difference if that
** the "c" value is determined by the position of the mouse cursor.
*/

void ft_julia(void *env, int pix_id)
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
		fr.c.real = ft_lint(-fr.wid_x / 2, fr.wid_x / 2, info->mouse.x / info->w);
		fr.c.real = ft_lint(-fr.wid_y / 2, fr.wid_y / 2, info->mouse.y / info->h);
		fr.z.real = ft_lint(fr.min_x, fr.max_x, (float)fr.x / info->w);
		fr.z.imag = ft_lint(fr.min_y, fr.max_y, (float)fr.y / info->h);
		info->buff_iter[pix_id] = ft_esc_time(info, fr);
	}
	ft_image_put_pixel(info, fr.x, fr.y, ft_clr_choose(info, info->buff_iter[pix_id]));
}
