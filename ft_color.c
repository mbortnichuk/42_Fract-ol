/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:17:53 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/19 14:17:55 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** By using a sin wave and shifting the frequency and phase of R G B
** color components we can generate regular repeating color gradients.
** The center of our color range is 127 (because 255 is max)
** Thus the width of our color range is 128 (if we want rainbow effects)
*/

int		ft_choose_clr(float iter, t_info *info)
{
	int		r;
	int		g;
	int		b;
	t_clr	c;

	c = info->c;
	if (iter >= info->limit_iter)
		return (0);
	else
	{
		r = sin(fmod(c.r_gb * iter + c.r_gb_ps, 2 * M_PI)) * c.wid + c.centr;
		g = sin(fmod(c.r_g_b * iter + c.r_g_b_ps, 2 * M_PI)) * c.wid + c.centr;
		b = sin(fmod(c.rg_b * iter + c.rg_b_ps, 2 * M_PI)) * c.wid + c.centr;
		return (r << 16 | g << 8 | b);
	}
}
