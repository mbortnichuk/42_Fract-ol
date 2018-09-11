/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bship.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:28:27 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/10 15:28:28 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Excalibur is actually d = 3 version of bship :)
*/

void ft_init_bship(void *env)
{
	t_info *info;

	info = (t_info*)env;
	info->fr.factor_z = 1;
	info->fr.d = 2;
	info->fr.abs = 1;
	info->fr.interact = 0;
	info->fr.cent_x = -0.5;
	info->fr.cent_y = -0.25;
	info->fr.wid_x = 3.0;
	info->fr.wid_y = 3.0;
}

void ft_init_excalibur(void *env)
{
	t_info *info;

	info = (t_info*)env;
	info->fr.factor_z = 1;
	info->fr.d = 3;
	info->fr.abs = 1;
	info->fr.interact = 0;
	info->fr.cent_x = 0.0;
	info->fr.cent_y = 0.0;
	info->fr.wid_x = 4.0;
	info->fr.wid_y = 4.0;
}

void ft_init_quaship(void *env)
{
	t_info *info;

	info = (t_info*)env;
	info->fr.factor_z = 1;
	info->fr.d = 4;
	info->fr.abs = 1;
	info->fr.interact = 0;
	info->fr.cent_x = 0.0;
	info->fr.cent_y = 0.0;
	info->fr.wid_x = 4.0;
	info->fr.wid_y = 4.0;
}
