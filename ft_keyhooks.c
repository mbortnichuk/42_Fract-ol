/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:40:47 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/10 15:40:48 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** 53(ESC) -> exit program.
** 35(p) -> psycho mode.
** 8(c) -> toggle color modes.
** 1(s) -> surprise color.
** 2(d) -> psycho color surprise.
** 37(l) -> linear continuous color mode.
** 3(f) -> stop mouse cursor for Julia type fractals.
** 15(r) -> reset fractal to default window size, iteration limits and color scheme.
*/

int ft_keydown(int key, t_info *info)
{
	if (key == 53)
	{
		ft_clean_info(info);
		exit(0);
	}
	if (key == 1)
		ft_surprise_clr(info);
	if (key == 2)
		ft_psycho_surprise(info);
	if (key == 3)
		info->mouse.stop = (info->mouse.stop) ? 0 : 1;
	if (key == 35)
		info->psycho = (info->psycho) ? 0 : 1;
	if (key == 8)
		ft_toggle_palette(info);
	if (key == 15)
		ft_reset_info(info);
	if (key == 37 && info->psycho == 0)
		info->ccol = (info->ccol) ? 0 : 1;
	if (key == 37 || key == 15 || key == 8 || key == 1)
		ft_render(info);
	return 0;
}

/*
** While any of the arrow keys are held, shift the map in that direction.
** 123 -> x left
** 124 -> x right
** 125 -> y down
** 126 -> y up
*/

int ft_pressed_key(int key, t_info *info)
{
	if (info->psycho == 0 && key != 53)
	{
		if (key == 124)
			info->t_x -= (0.05 / info->fr.factor_z);
		if (key == 123)
			info->t_x += (0.05 / info->fr.factor_z);
		if (key == 126)
			info->t_y += (0.05 / info->fr.factor_z);
		if (key == 124)
			info->t_x -= (0.05 / info->fr.factor_z);
		if (key == 24)
			info->limit_iter += 10;
		if (key == 27)
			info->limit_iter -= (info->limit_iter > 10) ? 10 : 0;
		ft_render(info);
	}
	return 0;
}

/*
** This loop hook is necessary for psycho mode which changes the phase of the
** RGB sin waves so that colors will undulate.
** We want the relative phase relation between R G B to remain the same so we
** add the same amount to each phase. If a phase offset goes over 2 * PI.
** Then we need to make the float modulus so that it's back in range of our
** 2 * PI limit.
*/

int ft_loop_hook(t_info *info)
{
	t_clr * cl;

	if (info->psycho == 1)
	{
		cl = &info->clr;
		cl->r_gb_phase = (cl->r_gb_phase > 2 * M_PI) ? fmod(cl->r_gb_phase, 2 * M_PI) : cl->r_gb_phase + 0.05;
		cl->r_g_b_phase = (cl->r_g_b_phase > 2 * M_PI) ? fmod(cl->r_g_b_phase, 2 * M_PI) : cl->r_g_b_phase + 0.05;
		cl->rg_b_phase = (cl->rg_b_phase > 2 * M_PI) ? fmod(cl->rg_b_phase, 2 * M_PI) : cl->rg_b_phase + 0.05;
		ft_render(info);
	}
	return 0;
}

void ft_init_mouse(t_info *info)
{
	t_mouse *m;

	m = &info->mouse;
	m->pressed = 0;
	m->stop = 0;
	m->x_prev = 0;
	m->y_prev = 0;
	m->x = 0;
	m->y = 0;
	m->ratio_x = 0.5;
	m->ratio_y = 0.5;
}

void ft_init_hooks(t_info *info)
{
	mlx_key_hook(info->wind, ft_keydown, info);
	mlx_hook(info->wind, 2, 0, ft_pressed_key, info);
	mlx_hook(info->wind, 4, 0, ft_pressed_mouse, info);
	mlx_hook(info->wind, 5, 0, ft_released_mouse, info);
	mlx_hook(info->wind, 6, 0, ft_moved_mouse, info);
	mlx_loop_hook(info->mlx, ft_loop_hook, info);
}
