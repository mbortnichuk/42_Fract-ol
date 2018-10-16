/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_fract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:30:09 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/19 14:30:10 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Initiate a jump table so that we can get the relevant fract
**	func we would like to show
**	We make our jumptable static so we only need to set it once per run of
**	our program.
**	We need to protect our jump table lookup by making sure our converted number
**	is actually a valid index into the jump table.
*/

int			ft_get_fractal(char *ch_line, void *env)
{
	static t_fract_jt	fractal_jt[25] = {NULL};
	static t_f_set_jt	fract_setup_jt[25] = {NULL};
	int					choice;
	char				*itoa_ch;
	t_info				*info;

	info = (t_info *)env;
	if (fractal_jt[0] == NULL)
		ft_init_fract_table(fractal_jt);
	if (fract_setup_jt[0] == NULL)
		ft_init_fract_init_table(fract_setup_jt);
	choice = ft_atoi(ch_line);
	itoa_ch = ft_itoa(choice);
	if ((choice >= 0 && choice < 9) && ft_strcmp(itoa_ch, ch_line) == 0)
	{
		info->fract_func = fractal_jt[choice];
		info->fract_init = fract_setup_jt[choice];
		free(itoa_ch);
		return (choice);
	}
	else
	{
		free(itoa_ch);
		return (-1);
	}
}

/*
**	Calculate the minimum and maximum extents of our fractal. These extents
**	can then be used to interpolate the (real, imag) coordinates for each
**	of the pixels in our window.
**	To get zooming to work correctly (like in Google maps):
**	1) We scale our X and Y widths by our desired zoom factor
**	2) We set our min_x as the center point of our fractal + any offsets
**	and subtract by the width multiplied by the 'ratio_x' of our mouse cursor
**	3) Our max_x is similar except we multiply by '1 - ratio_x'
**	4) Repeat 2) && 3) but for min_y and max_y
**	Multiplying by the mouse cursor ratio will accordingly scale the left
**	width and right width of the fractal such that the cursor position will
**	will remain in the same spot even in our newly zoomed image.
**	The finishing puzzle piece is that we set the x_center and y_center
**	to the interpolated position of the mouse cursor when the zoom scroll
**	was initiated. (see: mouse_hooks.c)
*/

t_fract		ft_calc_min_max_fract(t_fract fr, t_info *info)
{
	double	xwid;
	double	ywid;

	xwid = fr.wid_x / info->fr.factor_z;
	ywid = fr.wid_y / info->fr.factor_z;
	fr.min_x = fr.cent_x + info->t_x - xwid * (info->mouse.ratio_x);
	fr.max_x = fr.cent_x + info->t_x + xwid * (1 - info->mouse.ratio_x);
	fr.min_y = fr.cent_y + info->t_y - ywid * (info->mouse.ratio_y);
	fr.max_y = fr.cent_y + info->t_y + ywid * (1 - info->mouse.ratio_y);
	return (fr);
}
