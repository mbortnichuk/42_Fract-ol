/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_esc_time_fr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:41:54 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/11 14:41:55 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**
*/

float ft_esc_time(t_info *info, t_fract fract)
{
	t_plxdcm z;
	t_plxdcm c;
	t_plxdcm z_tmp;
	size_t it;

	z = fract.z;
	c = fract.c;
	it = 0;
	z = ft_abs_sqr(z);
	while (z.real_sqr + z.imag_sqr <= 4.0 && it < info->limit_iter)
	{
		ft_calculate_z(info, &z_tmp, z, c);
		if (z.real == z_tmp.real && z.imag == z_tmp.imag)
		{
			it = info->limit_iter;
			break;
		}
		z = ft_abs_sqr(z_tmp);
		it++;
	}
	if (info->ccol == 1 && it != info->limit_iter)
		return ((float)it + 1 - log(log(z.real_sqr + z.imag_sqr)) /  log(info->fr.d));
	return ((float)it);
}
