/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bship.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:13:49 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/19 14:13:50 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Initializes the zoom factor, center X Y coordinates of our fractal as
**	well as the width of our X Y dimensions.
*/

void	ft_init_bship(void *en)
{
	t_info	*info;

	info = (t_info *)en;
	info->fr.factor_z = 1;
	info->fr.d = 2;
	info->fr.abs = 1;
	info->fr.interact = 0;
	info->fr.cent_x = -0.5;
	info->fr.cent_y = -0.25;
	info->fr.wid_x = 3.0;
	info->fr.wid_y = 3.0;
}

/*
**	It's actually the d = 3 version of burning ship...
*/

void	ft_init_excalibur(void *en)
{
	t_info	*info;

	info = (t_info *)en;
	info->fr.factor_z = 1;
	info->fr.d = 3;
	info->fr.abs = 1;
	info->fr.interact = 0;
	info->fr.cent_x = 0.0;
	info->fr.cent_y = 0.0;
	info->fr.wid_x = 4.0;
	info->fr.wid_y = 4.0;
}

void	ft_init_quadroship(void *en)
{
	t_info	*info;

	info = (t_info *)en;
	info->fr.factor_z = 1;
	info->fr.d = 4;
	info->fr.abs = 1;
	info->fr.interact = 0;
	info->fr.cent_x = 0.0;
	info->fr.cent_y = 0.0;
	info->fr.wid_x = 4.0;
	info->fr.wid_y = 4.0;
}
