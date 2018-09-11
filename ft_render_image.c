/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:49:30 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/11 10:49:32 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Our image is WIN_W * WIN_H * 32 bits per pixel large. But out ft_memset and
** ft_bzero funcs take a size in BYTES though.
*/

void ft_clear_image(t_info *info)
{
	t_img *image;

	image = &(info->img);
	ft_bzero(image->point, info->size * image->bpp);
}

/*
** Using mlx funcs to initialize our image that will be drawing our maps on.
** The initial bits per pixel that mlx_get_data_addr func returns is 32 bits.
** We working with bytes though since that's what the rest of our program is
** working in.
** Since 8 bits = 1 byte we just take our bpp and divide by 8
** to get bytes per pixel.
** Let it be declared here that image->bpp henceforce stands
** for bytes per pixel.
*/

void ft_init_image(t_info *info)
{
	t_img *image;

	image = &info->img;
	image->img = mlx_new_image(info->mlx, info->w, info->h);
	image->point = mlx_get_data_addr(image->img, &image->bpp, &image->line_s, &image->endian);
	image->bpp /= 8;
}

void ft_image_put_pixel(t_info *info, double x, double y, int clr)
{
	t_img *image;

	image = &(info->img);
	if (x >= 0 && x < info->w && y >= 0 && y < info->h)
		*(int*)(image->point + (int)(id_x(y, x, info->w) * image->bpp)) = clr;
}

/*
** Function will draw all the pixels of a fractal for 1 quadrant of the
** window.
** This allows multithreading so with 4 threads each can take care
** of 1 quadrant.
*/

void *ft_render_quadrants(void *as)
{
	t_info *info;
	int x_id;
	int x_end;
	int y_id;
	int y_end;

	info = ((t_trg*)as)->info;
	x_end = (LEFT(((t_trg*)as)->quadr)) ? info->w / 2 : info->w;
	y_end = (TOP(((t_trg*)as)->quadr)) ? info->h / 2 : info->h;
	x_id = (LEFT(((t_trg*)as)->quadr)) ? -1 : info->w / 2 - 1;
	while (++x_id < x_end)
	{
		y_id = (TOP(((t_trg*)as)->quadr)) ? -1 : info->h / 2 - 1;
		while (++y_id < y_end)
			info->fract_func(info, id_x(y_id, x_id, info->w));
	}
	return (NULL);
}

/*
** Func will render fractal. We do this by creating 4 threads that will work
** on the 4 quadrants of the window. Then we wait for the threads to finish
** and we can put the resulting image to the window.
*/

void ft_render(t_info *info)
{
	t_trg as[4];
	int i;

	ft_clear_image(info);
	i = -1;
	while (++i < 4)
	{
		as[i].info = info;
		as[i].quadr = i;
		pthread_create(&info->t_ids[i], NULL, ft_render_quadrants, (void*)&as[i]);
	}
	i = -1;
	while (++i < 4)
		pthread_join(info->t_ids[i], NULL);
	mlx_put_image_to_window(info->mlx, info->wind, info->img.img, 0, 0);
}

/*#include <time.h>
#include <stdio.h>

	struct timespec start, finish;
	double elapsed = 0;
	clock_gettime(CLOCK_MONOTONIC, &start);

	"function you care about and like to time goes here"

	clock_gettime(CLOCK_MONOTONIC, &finish);
	elapsed = (finish.tv_sec - start.tv_sec);
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
	ft_printf("time elapsed: %lf\n", elapsed);*/
