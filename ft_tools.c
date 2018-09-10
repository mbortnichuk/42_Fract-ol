/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 10:47:15 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/10 10:47:18 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_show_info(int mod)
{
	if (mod == 0)
	{
		ft_printf("Usage: ./fractol [fractol number]\n\n");
		ft_printf("Fractol numbers:\n");
		ft_printf("0. Julia\n1.Mandelbrot\n2.Bship\n3.Trijulia\n");
		ft_printf("4.Tribrot\n5.Excalibur\n6.Quajulia\n7.Quabrot\n");
		ft_printf("8.Triship or Ghosts\n");
	}
	else if (mod == 1)
	{
		ft_printf("\n\t\t\t\tFract'ol\n");
		ft_printf("Arrows to translate real/imaginary axes\n\
			'+/-' to incr/decr iteration limit\n\
			f -> freeze mouse cursor (works for Julia fractals)\n\
			p -> psycho mode\nl -> linear continuous color mode\n\
			c -> toggle color palettes\ns -> surprise color\n\
			d -> psycho surprise\nr -> reset current fractal to default\n\
			ESC -> exit\n\n");
	}
}

// void ft_init_hooks(t_info *info)
// {
// 	mlx_key_hook(info->wind, );
// }

void ft_init_info(t_info *info)
{
	info->w = 1024;
	info->h = 576;
	// info->size = info->w * info->h;
	// info->t_x = 0;
	// info->t_y = 0;
	// info->ccol = 0;
	// into->limit_iter = 50;
	info->buff_iter = (float*)malloc(info->size * sizeof(float));
	info->fract_init(info);
	// ft_set_clr(info);
	info->mlx = mlx_init();
	info->wind = mlx_new_window(info->mlx, info->w, info->h, "Fract'ol");
	// ft_init_image(info);
	// ft_init_mouse(info);
	// ft_init_hooks(info);
	// ft_render(info);
	mlx_loop(info->mlx);
}

/*
**
*/


