/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmei <nmei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:42:17 by nmei              #+#    #+#             */
/*   Updated: 2018/01/19 13:40:00 by nmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stddef.h>
# include <pthread.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include "../libft/libft.h"

# define LEFT(x) 			((x) == 0 || (x) == 2)
# define TOP(x) 			((x) == 0 || (x) == 1)

typedef struct s_fract	t_fract;
typedef struct s_clr	t_clr;
typedef struct s_info	t_info;
typedef struct s_args	t_args;
typedef struct s_plxdcm	t_plxdcm;
typedef struct s_mouse	t_mouse;
typedef struct s_img	t_img;

struct					s_img
{
	void		*img;
	int			endian;
	int			bpp;
	char		*ptr;
	int			s_line;
};

struct					s_mouse
{
	int			stop;
	int			pressed;
	double		x;
	double		y;
	double		x_prv;
	double		y_prv;
	double		ratio_x;
	double		ratio_y;
};

struct					s_plxdcm
{
	double		real;
	double		imag;
	double		rsqr;
	double		isqr;
};

struct					s_fract
{
	t_plxdcm	z;
	t_plxdcm	c;
	int			d;
	int			x;
	int			y;
	int			abs;
	int			interact;
	double		factor_z;
	double		cent_x;
	double		cent_y;
	double		wid_x;
	double		wid_y;
	double		min_x;
	double		min_y;
	double		max_x;
	double		max_y;
};

struct					s_clr
{
	float		r_gb;
	float		r_g_b;
	float		rg_b;
	float		r_gb_ps;
	float		r_g_b_ps;
	float		rg_b_ps;
	int			centr;
	int			wid;
};

typedef void			(*t_fract_jt)(void *environ, int pix_ind);
typedef	void			(*t_f_set_jt)(void *environ);

struct					s_info
{
	t_fract		fr;
	t_clr		c;
	t_fract_jt	fract_func;
	t_f_set_jt	fract_init;
	t_img		img;
	t_mouse		mouse;
	void		*mlx;
	void		*wind;
	size_t		limit_iter;
	int			w;
	int			h;
	int			size;
	int			choice_of_fract;
	int			clr_style;
	int			psycho;
	int			cllr;
	float		*buff_iter;
	double		t_x;
	double		t_y;
	pthread_t	tids[4];
};

struct					s_args
{
	t_info		*info;
	int			quadr;
};

/*
** ft_bship.c
*/

void					ft_init_bship(void *en);
void					ft_init_excalibur(void *en);
void					ft_init_quadroship(void *en);

/*
** ft_color.c
*/

int						ft_choose_clr(t_info *info, float iter);

/*
** ft_esc_time_fr.c
*/

float					ft_fr_esc_time(t_info *info, t_fract f);

/*
** ft_get_fract.c
*/

int						ft_get_fractal(void *env, char *ch_line);
t_fract					ft_calc_min_max_fract(t_info *info, t_fract f);

/*
** ft_julia.c
*/

void					ft_julia(void *en, int pix_id);
void					ft_init_julia(void *en);
void					ft_init_trijulia(void *en);
void					ft_init_quadjulia(void *en);

/*
** ft_keyhooks.c
*/

int						ft_keydown(int key, t_info *info);
int						ft_keypressed(int key, t_info *info);
int						ft_loop_hook(t_info *info);
void					ft_init_mouse(t_info *info);
void					ft_start_hooks(t_info *info);

/*
** ft_mandelbrot.c
*/

void					ft_mandelbrot(void *en, int pix_id);
void					ft_init_mandelbrot(void *en);
void					ft_init_tribrot(void *en);
void					ft_init_quadrobrot(void *en);

/*
** ft_mousehooks.c
*/

int						ft_pressed_mouse(int button, int x, int y, \
								t_info *info);
int						ft_released_mouse(int button, int x, int y, \
								t_info *info);
int						ft_moved_mouse(int x, int y, t_info *info);

/*
** ft_palette.c
*/

void					ft_toggle_palette(t_info *info);
void					ft_surprise_color(t_info *info);
void					ft_psycho_surprise(t_info *info);

/*
** ft_render_image.c
*/

void					ft_init_new_img(t_info *info);
void					ft_img_put_pix(t_info *info, double x, double y, \
								int color);
void					ft_clear_image(t_info *info);
void					*ft_rend_quads(void *as);
void					ft_render(t_info *info);

/*
** ft_set_fract_table.c
*/

void					ft_init_fract_table(t_fract_jt j_table[25]);
void					ft_init_fract_init_table(t_f_set_jt j_table[25]);
t_plxdcm				ft_abs_sqr(t_plxdcm z);

/*
** ft_tools.c
*/

void					ft_show_info(int mod);
void					ft_init_info(t_info *info);
void					ft_init_clr(t_info *info);
void					ft_clear_info(t_info *info);
void					ft_reset_info(t_info *info);

/*
** main.c
*/

int						ft_id_x(int row, int col, int dim);
double					ft_linint(double st, double end, \
								double dec_perc);
void					ft_calculate_z(t_info *info, t_plxdcm *tmp_z, \
								t_plxdcm z, t_plxdcm c);

#endif
