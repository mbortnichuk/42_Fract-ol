/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:37:45 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/19 14:37:46 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Will be called then a key has been pressed and released.
** 53 (esc) -> exit the program.
** 1 (s) -> surprise color.
** 2 (d) -> psycho surprise.
** 3 (f) -> freeze mouse cursor tracking Julia type fractals.
** 8 (c) -> toggle color palettes.
** 15 (r) -> reset current fractal back to it's default iter limits, color
** palette and window size.
** 35 (p) -> psycho mode.
** 37 (l) -> linear continuous locor mode
*/

int		ft_keydown(int key, t_info *info)
{
	if (key == 53)
	{
		ft_clear_info(info);
		exit(0);
	}
	if (key == 35)
		info->psycho = (info->psycho) ? 0 : 1;
	if (key == 8)
		ft_toggle_palette(info);
	if (key == 1)
		ft_surprise_color(info);
	if (key == 2)
		ft_psycho_surprise(info);
	if (key == 37 && info->psycho == 0)
		info->cllr = (info->cllr) ? 0 : 1;
	if (key == 3)
		info->mouse.stop = (info->mouse.stop) ? 0 : 1;
	if (key == 15)
		ft_reset_info(info);
	if (key == 37 || key == 15 || key == 8 || key == 1)
		ft_render(info);
	return (0);
}

/*
** While any of the arrows on the keyboard are held down
** shift the fractal in that direction.
** 123 -> x left
** 124 -> x right
** 125 -> y down
** 126 -> y up
*/

int		ft_keypressed(int key, t_info *info)
{
	if (info->psycho == 0 && key != 53)
	{
		if (key == 124)
			info->t_x -= (0.05 / info->fr.factor_z);
		if (key == 123)
			info->t_x += (0.05 / info->fr.factor_z);
		if (key == 126)
			info->t_y += (0.05 / info->fr.factor_z);
		if (key == 125)
			info->t_y -= (0.05 / info->fr.factor_z);
		if (key == 24)
			info->limit_iter += 10;
		if (key == 27)
			info->limit_iter -= (info->limit_iter > 10) ? 10 : 0;
		ft_render(info);
	}
	return (0);
}

/*
**	This loop hook is necessary for psycho mode which changes the phase
**	of the RGB sin waves so that colors will undulate.
**	We want the relative phase relation between R G B to remain the same
**	so we add the same amount to each phase. If a phase offset goes over 2 * PI
**	Then we need to take the float modulus so that it's back in range of our
**	2 * PI limit.
*/

int		ft_loop_hook(t_info *info)
{
	t_clr	*c;

	if (info->psycho == 1)
	{
		c = &info->c;
		c->r_gb_ps = (c->r_gb_ps > 2 * M_PI) ?
		fmod(c->r_gb_ps, 2 * M_PI) : c->r_gb_ps + 0.05;
		c->r_g_b_ps = (c->r_g_b_ps > 2 * M_PI) ?
		fmod(c->r_g_b_ps, 2 * M_PI) : c->r_g_b_ps + 0.05;
		c->rg_b_ps = (c->rg_b_ps > 2 * M_PI) ?
		fmod(c->rg_b_ps, 2 * M_PI) : c->rg_b_ps + 0.05;
		ft_render(info);
	}
	return (0);
}

void	ft_init_mouse(t_info *info)
{
	t_mouse		*mous;

	mous = &info->mouse;
	mous->pressed = 0;
	mous->stop = 0;
	mous->x_prv = 0;
	mous->y_prv = 0;
	mous->x = 0;
	mous->y = 0;
	mous->ratio_x = 0.5;
	mous->ratio_y = 0.5;
}

void	ft_start_hooks(t_info *info)
{
	mlx_key_hook(info->wind, ft_keydown, info);
	mlx_hook(info->wind, 2, 0, ft_keypressed, info);
	mlx_hook(info->wind, 4, 0, ft_pressed_mouse, info);
	mlx_hook(info->wind, 5, 0, ft_released_mouse, info);
	mlx_hook(info->wind, 6, 0, ft_moved_mouse, info);
	mlx_loop_hook(info->mlx, ft_loop_hook, info);
}
