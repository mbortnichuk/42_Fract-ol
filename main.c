/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:09:19 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/19 15:09:21 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Useful function to get the row and col value from a flattened
**	2D matrix. Dim is the 'width' of the matrix.
*/

int		ft_id_x(int dim, int row, int col)
{
	return (row * dim + col);
}

/*
**	Linear INTerpolation between two points given a decimal percent.
**	We don't do: (st + dec_prc * (end - st)) because if
**	st and end differ significantly in magnitude then we lose precision.
**	Test with: ft_linint(-16.0e30, 16.0, 1.0)
*/

double	ft_linint(double dec_prc, double st, double end)
{
	if (st == end)
		return (st);
	return (st * (1.0 - dec_prc) + (end * dec_prc));
}

void	ft_calculate_z(t_plxdcm z, t_plxdcm c, t_info *info, t_plxdcm *tmp_z)
{
	if (info->fr.d == 2)
	{
		tmp_z->imag = (z.real + z.imag) * (z.real + z.imag) - \
		z.rsqr - z.isqr + c.imag;
		tmp_z->real = z.rsqr - z.isqr + c.real;
	}
	else if (info->fr.d == 3)
	{
		tmp_z->imag = z.imag * (3 * z.rsqr - z.isqr) + c.imag;
		tmp_z->real = z.real * (z.rsqr - 3 * z.isqr) + c.real;
	}
	else if (info->fr.d == 4)
	{
		tmp_z->imag = (4 * z.real * z.imag) * (z.rsqr - z.isqr) + c.imag;
		tmp_z->real = (z.rsqr * z.rsqr) + z.isqr * \
		(z.isqr - 6 * z.rsqr) + c.real;
	}
	if (info->fr.abs == 1)
	{
		tmp_z->imag = (tmp_z->imag < 0.0f) ? -tmp_z->imag : tmp_z->imag;
		tmp_z->real = (tmp_z->real < 0.0f) ? -tmp_z->real : tmp_z->real;
	}
}

/*
**	Entry point of the program.
*/

int		main(int argc, char *argv[])
{
	t_info	info;

	info.choice_of_fract = -1;
	if (argc == 2 && (info.choice_of_fract = \
		ft_get_fractal(argv[1], &info)) != -1)
	{
		ft_show_info(1);
		ft_init_info(&info);
		return (0);
	}
	else
	{
		ft_show_info(0);
		return (1);
	}
}
