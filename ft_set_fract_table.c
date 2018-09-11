/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_fract_table.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:23:57 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/10 11:24:00 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** A jump table to grab correct fractal function.
*/

void ft_init_fract_table(t_fract_jt j_table[25])
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
void ft_init_fract_init_table(t_f_set_jt j_table[25])
{
	j_table[0] = &ft_init_julia;
	j_table[1] = &ft_init_mandelbrot;
	j_table[2] = &ft_init_bship;
	j_table[3] = &ft_init_trijulia;
	j_table[4] = &ft_init_tribrot;
	j_table[5] = &ft_init_excalibur;
	j_table[6] = &ft_init_quajulia;
	j_table[7] = &ft_init_quabrot;
	j_table[8] = &ft_init_quaship;
}

/*
** Perform absolute squared of our complex number. Recall for a complex number
** p where p = a + bi that the absolute value of p: |p| = sqrt(aˆ2 + bˆ2)
** Because square root is an expencive operation for computer if we take the
** absolute value squared we get: |p|ˆ2 = aˆ2 + bˆ2
*/

t_plxdcm ft_abs_sqr(t_plxdcm p)
{
	p.real_sqr = (p.real * p.real);
	p.imag_sqr = (p.imag * p.imag);
	return p;
}
