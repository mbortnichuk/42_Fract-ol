/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_fract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:22:17 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/10 11:22:21 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Init out jump table so that we can get the relevant fractal func
** we'd like to show.
** We make our jump table static so we only need to init it once per
** program run.
** We need to protect out table lookup by making sure our converted
** number is actually a valid id into the jump table.
*/

int ft_get_fract(void *en, char *choice_line)
{
	static t_fract_jt fract_jt[25] = {NULL};
	static t_f_set_jt fract_set_jt[25] = {NULL};
	t_info *info;
	char *itoa_ch;
	int choice;

	info = (t_info*)en;
	if (fract_jt[0] == NULL)
		ft_init_fract_table(fract_jt);
	if (fract_set_jt[0] == NULL)
		ft_init_fract_init_table(fract_set_jt);
	choice = ft_atoi(choice_line);
	itoa_ch = ft_itoa(choice);
	if ((choice >= 0 && choice < 9) && ft_strcmp(itoa_ch, choice_line) == 0)
	{
		info->fract_func = fract_jt[choice];
		info->fract_init = fract_set_jt[choice];
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
** Calculate the min and max extents of our fractal. These extents can then be
** used to interpolate the real or imaginary coords for each of the pixels
** in pur window.
** To get zooming to work normally:
** -> we scale our x-y width by our desired zoom factor
** -> set out min_x as the center point of our fractal + any offsets and substr
** by the width miltiplied by the ratio_x of our mouse cursor
** -> our max_x is similar except we multiply by 1-ratio_x
** -> repeat 2&&3 but for min_y and min_x
** Multiplying by the mouse cursor ratio will accordingly scale the left width
** and right width of the fractal such that the cursor position will remain
** in the same spot even in pur newly zoomed image.
** The finishing touch is that we set the cent_x and cent_y to the interpolated
** position of the mouse cursor when the zoom scroll was initiated.
*/

t_fract ft_calc_min_max_fractal(t_info *info, t_fract fr)
{
	double xwid;
	double ywid;

	xwid = fr.wid_x / info->fr.factor_z;
	ywid = fr.wid_y / info->fr.factor_z;
	fr.min_x = fr.cent_x + info->t_x - xwid * (info->mouse.ratio_x);
	fr.max_x = fr.cent_x + info->t_x - xwid * (1 - info->mouse.ratio_x);
	fr.min_y = fr.cent_y + info->t_y - ywid * (info->mouse.ratio_y);
	fr.min_y = fr.cent_y + info->t_y - ywid * (1 - info->mouse.ratio_y);
	return fr;
}
