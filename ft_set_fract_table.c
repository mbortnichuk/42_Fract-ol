/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_fract_table.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:57:13 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/19 14:57:14 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Initiate  a jump table so we can grab the correct fract func.
*/

void		ft_init_fract_table(t_fract_jt j_table[25])
{
	j_table[0] = &ft_julia;
	j_table[1] = &ft_mandelbrot;
	j_table[2] = &ft_mandelbrot;
	j_table[3] = &ft_julia;
	j_table[4] = &ft_mandelbrot;
	j_table[5] = &ft_mandelbrot;
	j_table[6] = &ft_julia;
	j_table[7] = &ft_mandelbrot;
	j_table[8] = &ft_mandelbrot;
}

void		ft_init_fract_init_table(t_f_set_jt j_table[25])
{
	j_table[0] = &ft_init_julia;
	j_table[1] = &ft_init_mandelbrot;
	j_table[2] = &ft_init_bship;
	j_table[3] = &ft_init_trijulia;
	j_table[4] = &ft_init_tribrot;
	j_table[5] = &ft_init_excalibur;
	j_table[6] = &ft_init_quadjulia;
	j_table[7] = &ft_init_quadrobrot;
	j_table[8] = &ft_init_quadroship;
}

/*
**	Perform absolute squared of our complex number
**	Recall for a complex number z where z = a + bi that the absolute value of z:
**	z = sqrt(a^2  + b^2)
**	Because square root is an expensive operation for computer if we take the
**	absolute value squared we get:
**	z^2 = a^2 + b^2
*/

t_plxdcm	ft_abs_sqr(t_plxdcm z)
{
	z.rsqr = (z.real * z.real);
	z.isqr = (z.imag * z.imag);
	return (z);
}
