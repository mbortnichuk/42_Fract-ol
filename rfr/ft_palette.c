/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_palette.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:51:21 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/19 14:51:22 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_surprise_color(t_info *info)
{
	info->c.r_gb = rand() % 10;
	info->c.r_g_b = rand() % 10;
	info->c.rg_b = rand() % 10;
}

void	ft_psycho_surprise(t_info *info)
{
	info->c.r_gb_ps = rand() % 20;
	info->c.r_g_b_ps = rand() % 20;
	info->c.rg_b_ps = rand() % 20;
}

void	ft_toggle_palette(t_info *info)
{
	info->clr_style = (info->clr_style + 1) % 4;
	if (info->clr_style == 0)
	{
		info->c.r_gb = 0.33;
		info->c.r_g_b = 0.33;
		info->c.rg_b = 0.33;
	}
	if (info->clr_style == 1)
	{
		info->c.r_gb = 0.33;
		info->c.r_g_b = 0.33;
		info->c.rg_b = 0.00;
	}
	if (info->clr_style == 2)
	{
		info->c.r_gb = 0.33;
		info->c.r_g_b = 0.00;
		info->c.rg_b = 0.33;
	}
	if (info->clr_style == 3)
	{
		info->c.r_gb = 0.00;
		info->c.r_g_b = 0.33;
		info->c.rg_b = 0.33;
	}
}
