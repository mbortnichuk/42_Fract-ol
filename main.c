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
