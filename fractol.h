/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbortnic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:14:29 by mbortnic          #+#    #+#             */
/*   Updated: 2018/09/06 15:14:30 by mbortnic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_HPP
# define FRACTOL_HPP

# include "./libft/libft.h"
# include <mlx.h>
# include <pthread.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define LEFT(x) ((x) == 0 || (x) == 2)
# define TOP(x) ((x) == 0 || (x) == 1)

typedef void (*t_fract_jt)(void *info, int pix_id);
typedef void (*t_f_set_jt)(void *info);

typedef struct s_img t_img;
typedef struct s_mouse t_mouse;
typedef struct s_plxdcm t_plxdcm;
typedef struct s_fract t_fract;
typedef struct s_clr t_clr;
typedef struct s_info t_info;
typedef struct s_trg t_trg;

struct s_trg
{
	t_info *info;
	int quadr;
};

struct s_img
{
	void *img;
	char *point;
	int bpp;
	int line_s;
	int endian;
};

struct s_mouse
{
	int stop;
	double ratio_x;
	double ratio_y;
	int pressed;
	double x_prev;
	double y_prev;
	double x;
	double y;
};

struct s_plxdcm
{
	double real_sqr;
	double imag_sqr;
	double real;
	double imag;
};

struct s_fract
{
	t_plxdcm z;
	t_plxdcm c;
	int d;
	int x;
	int y;
	double cent_x;
	double wid_x;
	double min_x;
	double max_x;
	double wid_y;
	double min_y;
	double max_y;
	double cent_y;
	double factor_z;
	int abs;
	int interact;
};

struct s_clr
{
	int centr;
	int wid;
	float r_gb;
	float r_g_b;
	float rg_b;
	float r_gb_phase;
	float r_g_b_phase;
	float rg_b_phase;
};

struct s_info
{
	int w;
	int h;
	float *buff_iter;
	t_fract fr;
	t_clr clr;
	t_mouse mouse;
	int choose_fract;
	t_fract_jt fract_func;
	t_f_set_jt fract_init;
	int size;
	double t_x;
	double t_y;
	int ccol;
	size_t limit_iter;
	void *mlx;
	void *wind;
	int clr_style;
	int psycho;
	t_img img;
	pthread_t t_ids[4];
};

/*
** ft_mandelbrot.c
*/

void ft_init_mandelbrot(void *env);
void ft_init_tribrot(void *env);
void ft_init_quabrot(void *env);
void ft_mandelbrot(void *env, int pix_id);

/*
** ft_julia.c
*/

void ft_init_julia(void *env);
void ft_init_trijulia(void *env);
void ft_init_quajulia(void *env);
void ft_julia(void *env, int pix_id);

/*
** ft_bship.c
*/

void ft_init_bship(void *env);
void ft_init_excalibur(void *env);
void ft_init_quaship(void *env);


/*
** ft_set_fract_table.c
*/

void ft_init_fract_table(t_fract_jt j_table[25]);
void ft_init_fract_init_table(t_f_set_jt j_table[25]);
t_plxdcm ft_abs_sqr(t_plxdcm p);

/*
** ft_get_fract.c
*/

int ft_get_fract(void *info, char *choice_line);
t_fract ft_calc_min_max_fractal(t_info *info, t_fract fract);

/*
** ft_color.c
*/

int ft_clr_choose(t_info *info, float it);

/*
** ft_palette.c
*/

void ft_surprise_clr(t_info *info);
void ft_psycho_surprise(t_info *info);
void ft_toggle_palette(t_info *info);

/*
** ft_keyhooks.c
*/

int ft_keydown(int key, t_info *info);
int ft_pressed_key(int key, t_info *info);
int ft_loop_hook(t_info *info);
void ft_init_mouse(t_info *info);
void ft_init_hooks(t_info *info);

/*
** ft_mousehooks.c
*/

int ft_moved_mouse(int x, int y, t_info *info);
int ft_released_mouse(int butt, int x, int y, t_info *info);
int ft_pressed_mouse(int butt, int x, int y, t_info *info);

/*
** ft_esc_time_fract.c
*/

float ft_esc_time(t_info *info, t_fract fract);

/*
** ft_render_image.c
*/

void ft_clear_image(t_info *info);
void ft_init_image(t_info *info);
void ft_image_put_pixel(t_info *info, double x, double y, int clr);
void *ft_render_quadrants(void *as);
void ft_render(t_info *info);

/*
** ft_tools.c
*/

void ft_show_info(int mod);
void ft_init_info(t_info *info);
void ft_init_color(t_info *info);
void ft_clean_info(t_info *info);
void ft_reset_info(t_info *info);

/*
** main.c
*/

double ft_lint(double st, double end, double dec_perc);
int id_x(int row, int col, int dimens);
void ft_calculate_z(t_info *info, t_plxdcm *z_tmp, t_plxdcm z, t_plxdcm v);

#endif
