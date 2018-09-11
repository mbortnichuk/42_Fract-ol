/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:14:18 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/06 15:14:20 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Linear Interpolation between two points given a decimal percent.
** Test with: ft_lint(-16.0e30, 16.0, 1.0);
** We do not do: (st + dec_perc * (end - st)) - because if start and end differ
** in magnitude then we lose a lot of precision.
*/

double ft_lint(double st, double end, double dec_perc)
{
	if (st == end)
		return (st);
	return (st * (1.0 - dec_perc) + (end * dec_perc));
}

/*
** Function to get the row and col value from a flattened 2D matrix.
** Dim is the "width" of the matrix.
*/

int id_x(int row, int col, int dimens)
{
	return (row * dimens + col);
}

/*
** lookup ft_esc_time_fr.c
*/

void ft_calculate_z(t_info *info, t_plxdcm *z_tmp, t_plxdcm z, t_plxdcm v)
{
	if (info->fr.d == 2)
	{
		z_tmp->imag = (z.real + z.imag) * (z.real + z.imag) - z.real_sqr - z.imag_sqr + v.imag;
		z_tmp->real = z.real_sqr - z.imag_sqr + v.real;
	}
	else if (info->fr.d == 3)
	{
		z_tmp->imag = z.imag * (3 * z.real_sqr - z.imag_sqr) + v.imag;
		z_tmp->real = z.real * (z.real_sqr - 3 * z.imag_sqr) + v.real;
	}
	else if (info->fr.d == 4)
	{
		z_tmp->imag = (4 * z.real * z.imag) * (z.real_sqr - z.imag_sqr) + v.imag;
		z_tmp->real = (z.real_sqr * z.imag_sqr) + z.imag_sqr * (z.imag_sqr - 6 * z.real_sqr) + v.real;
	}
	if (info->fr.abs == 1)
	{
		z_tmp->imag = (z_tmp->imag < 0.0f) ? -z_tmp->imag : z_tmp->imag;
		z_tmp->real = (z_tmp->real < 0.0f) ? -z_tmp->real : z_tmp->real;
	}
}

/*
** Entry point of the program.
*/

int main(int ac, char **av)
{
	// if (ac == 2)
	// 	ft_printf("Works!!!\n");
	// return (0);

	t_info info;

	info.choose_fract = -1;
	if (ac == 2 && (info.choose_fract = ft_get_fract(&info, av[1])) != -1)
	{
		ft_show_info(1);
		ft_init_info(&info);
		return 0;
	}
	else
	{
		ft_show_info(0);
		return 1;
	}
}
