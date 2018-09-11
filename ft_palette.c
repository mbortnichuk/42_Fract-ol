/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_palette.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 13:39:15 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/10 13:39:18 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_surprise_clr(t_info *info)
{
	info->clr.r_gb = rand() % 10;
	info->clr.r_g_b = rand() % 10;
	info->clr.rg_b = rand() % 10;
}

void ft_psycho_surprise(t_info *info)
{
	info->clr.r_gb_phase = rand() % 20;
	info->clr.r_g_b_phase = rand() % 20;
	info->clr.rg_b_phase = rand() % 20;
}

void ft_toggle_palette(t_info *info)
{
	info->clr_style = (info->clr_style + 1) % 4;
	if (info->clr_style == 0)
	{
		info->clr.r_gb = 0.33;
		info->clr.r_g_b = 0.33;
		info->clr.rg_b = 0.33;
	}
	if (info->clr_style == 1)
	{
		info->clr.r_gb = 0.33;
		info->clr.r_g_b = 0.33;
		info->clr.rg_b = 0.00;
	}
	if (info->clr_style == 2)
	{
		info->clr.r_gb = 0.33;
		info->clr.r_g_b = 0.00;
		info->clr.rg_b = 0.33;
	}
	if (info->clr_style == 3)
	{
		info->clr.r_gb = 0.00;
		info->clr.r_g_b = 0.33;
		info->clr.rg_b = 0.33;
	}
}
