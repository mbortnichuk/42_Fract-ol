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

#include "fractol.c"

/*
** A jump table to grab correct fractal function.
*/

void ft_init_fract_table(t_fract_jt j_table[25])
{
	j_table[0] = &julia;
	j_table[1] = &mandelbrot;
	j_table[2] = &mandelbrot;
	j_table[3] = &julia;
	j_table[4] = &mandelbrot;
	j_table[5] = &mandelbrot;
	j_table[6] = &julia;
	j_table[7] = &mandelbrot;
	j_table[8] = &mandelbrot;
}
void ft_init_fract_init_table(t_f_set_jt j_table[25])
{
	j_table[0] = &ft_init_julia;
	j_table[1] = &ft_init_mandelbrot;
	// j_table[2] = &ft_init_bship;
	j_table[3] = &ft_init_trijulia;
	j_table[4] = &ft_init_tribrot;
	// j_table[5] = &ft_init_triship;
	j_table[6] = &ft_init_quajulia;
	j_table[7] = &ft_init_quabrot;
	// j_table[8] = &ft_init_quaship;
}
