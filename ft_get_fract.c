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

int ft_get_fract(void *info, char *choice_line)
{
	static t_fract_jt fract_jt[25] = {NULL};
	static t_f_set_jt fract_set_jt[25] = {NULL};
	t_info *info;
	char *itoa_ch;
	int choice;

	info = (t_info*)info;
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
