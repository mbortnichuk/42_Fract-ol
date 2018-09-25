/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:04:17 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/19 15:04:19 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_show_info(int mod)
{
	if (mod == 0)
	{
		ft_printf(YEL"\nUsage: ./fractol [fractol numer]\n\n"RC);
		ft_printf(MAG"Fractol numbers: \n"RC);
		ft_printf("0. Julia\n1.Mandelbrot\n2.Burning ship\n\
3.Trijulia\n4.Tribrot\n5.Excalibur\n6.Quadjulia\n\
7.Quadrobrot\n8.Ghosts\n\n");
		ft_printf(YEL"Example: ./fractol 3  -> will display Trijulia\n\n"RC);
	}
	else if (mod == 1)
	{
		ft_printf(YEL"\nFractol info: \n\n"RC);
		ft_printf("-> Mouse: zoom in/out\n-> Arrow keys: real/imaginary axes\n\
-> +/-: incr/decr iteration limit\n-> r: reset current fractal\n\
-> f: stop mouse tracking (Julia fractals)\n-> p: psycho mode\n\
-> c: toggle palettes\n-> s: surprise color\n-> d: psycho color surprise\n\
-> l: linear continuous mode\n-> esc: exit\n\n");
	}
}

void	ft_init_info(t_info *info)
{
	info->w = 1024;
	info->h = 576;
	info->size = info->w * info->h;
	info->t_x = 0;
	info->t_y = 0;
	info->cllr = 0;
	info->limit_iter = 50;
	info->buff_iter = (float *)malloc(info->size * sizeof(float));
	info->fract_init(info);
	ft_init_clr(info);
	info->mlx = mlx_init();
	info->wind = mlx_new_window(info->mlx, info->w, info->h, "Fractol 42");
	ft_init_new_img(info);
	ft_init_mouse(info);
	ft_start_hooks(info);
	ft_render(info);
	mlx_loop(info->mlx);
}

void	ft_init_clr(t_info *info)
{
	info->clr_style = 0;
	info->c.centr = 127;
	info->c.wid = 128;
	info->c.r_gb = 0.33;
	info->c.r_g_b = 0.33;
	info->c.rg_b = 0.33;
	info->c.r_gb_ps = 0.00;
	info->c.r_g_b_ps = (2 * M_PI) / 3;
	info->c.rg_b_ps = (4 * M_PI) / 3;
	info->psycho = 0;
}

void	ft_clear_info(t_info *info)
{
	free(info->buff_iter);
	mlx_destroy_image(info->mlx, (&info->img)->img);
	mlx_destroy_window(info->mlx, info->wind);
}

void	ft_reset_info(t_info *info)
{
	ft_clear_info(info);
	ft_init_info(info);
}
