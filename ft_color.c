/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 12:24:17 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/10 12:24:18 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** By using a SIN wave and shifting the frequency and phase of RGB color
** components we can generate regular repeating color gradients.
** The center of our color range is 127 (because 255 is maximum).
** Thus the width of out color range is 128 (if we want rainbow effects).
*/

int ft_clr_choose(t_info *info, float it)
{
	int r;
	int g;
	int b;
	t_clr cl;

	cl = info->clr;
	if (it >= info->limit_iter)
		return 0;
	else
	{
		r = sin(fmod(cl.r_gb * it + cl.r_gb_phase, 2 * M_PI)) * cl.wid + cl.centr;
		g = sin(fmod(cl.r_g_b * it + cl.r_g_b_phase, 2 * M_PI)) * cl.wid + cl.centr;
		b = sin(fmod(cl.rg_b * it + cl.rg_b_phase, 2 * M_PI)) * cl.wid + cl.centr;
		return (r << 16 | g << 8 | b);
	}
}
