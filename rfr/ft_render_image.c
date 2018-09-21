/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:53:31 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/19 14:53:32 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
**	Our image is WIN_W * WIN_H * 32 bits per pixel large.
**	Our ft_bzero and ft_memset functions take a size in BYTES though.
*/

void	ft_clear_image(t_info *info)
{
	t_img *img;

	img = &(info->img);
	ft_bzero(img->ptr, info->size * img->bpp);
}

/*
**	Use mlx functions to initialize our image that we will be
**	drawing our maps on.
**	The initial bits per pixel (bpp) that the mlx_get_data_addr function returns
**	is 32 bits.
**	We would like to work with bytes though since that is what the rest of our
**	program is working in.
**	Example 1: our colors are ints which are in bytes.
**	Example 2: Our ft_bzero and ft_memset functions expect a size in bytes
**	Since 8 bits = 1 byte we just take our bpp and divide by 8 to get
**	BYTES per pixel
**	LET IT BE DECLARED HERE THAT img->bpp HENCEFORCE STANDS FOR BYTES PER PIXEL
*/

void	ft_init_new_img(t_info *info)
{
	t_img	*img;

	img = &info->img;
	img->img = mlx_new_image(info->mlx, info->w, info->h);
	img->ptr = mlx_get_data_addr(img->img, &img->bpp, &img->s_line,
								&img->endian);
	img->bpp /= 8;
}

void	ft_img_put_pix(t_info *info, double x, double y, int color)
{
	t_img *img;

	img = &(info->img);
	if (x >= 0 && x < info->w && y >= 0 && y < info->h)
		*(int *)(img->ptr + (int)(ft_id_x(y, x, info->w) * img->bpp)) = color;
}

/*
**	This function will draw all the pixels of a fractal for 1 quadrant of the
**	window. This allows multithreading so with 4 threads each can take care of 1
**	quadrant.
*/

void	*ft_rend_quads(void *as)
{
	int			x_ind;
	int			y_ind;
	int			x_end;
	int			y_end;
	t_info		*env;

	env = ((t_args *)as)->info;
	x_end = (LEFT(((t_args *)as)->quadr)) ? env->w / 2 : env->w;
	y_end = (TOP(((t_args *)as)->quadr)) ? env->h / 2 : env->h;
	x_ind = (LEFT(((t_args *)as)->quadr)) ? -1 : env->w / 2 - 1;
	while (++x_ind < x_end)
	{
		y_ind = (TOP(((t_args *)as)->quadr)) ? -1 : env->h / 2 - 1;
		while (++y_ind < y_end)
		{
			env->fract_func(env, ft_id_x(y_ind, x_ind, env->w));
		}
	}
	return (NULL);
}

/*
**	This will render(draw) our fractal. We do this by creating 4 threads
**  that will work on the 4 quadrants of the window.
**	Then we just wait for the threads to finish and we can put the resulting
**	image to the window.
*/

void	ft_render(t_info *info)
{
	int		i;
	t_args	as[4];

	ft_clear_image(info);
	i = -1;
	while (++i < 4)
	{
		as[i].info = info;
		as[i].quadr = i;
		pthread_create(&info->tids[i], NULL, ft_rend_quads, (void*)&as[i]);
	}
	i = -1;
	while (++i < 4)
		pthread_join(info->tids[i], NULL);
	mlx_put_image_to_window(info->mlx, info->wind, info->img.img, 0, 0);
}
