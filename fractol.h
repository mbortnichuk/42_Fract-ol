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

# include "/libft/libft.h"
# include <mlx.h>
# include <pthread.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define LEFT(x) ((x) == 0 || (x) == 2)
# define TOP(x) ((x) == 0 || (x) == 1)

typedef struct s_img t_img;
typedef struct s_mouse t_mouse;
typedef struct s_plxdcm t_plxdcm;
typedef struct s_fract t_fract;
typedef struct s_clr t_clr;
typedef struct s_info t_info;
typedef struct s_trg t_trg;

struct s_img
{
	
};

struct s_mouse
{
	
};

struct s_plxdcm
{
	
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
	// int size;
	// double t_x;
	// double t_y;
	// int ccol;
	// size_t limit_iter;
	void *mlx;
	void *wind;
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
** ft_set_fract_table.c
*/

void ft_init_fract_table(t_fract_jt j_table[25]);
void ft_init_fract_init_table(t_f_set_jt j_table[25]);

/*
** ft_get_fract.c
*/

int ft_get_fract(void *info, char *choice_line);

/*
** ft_tools.c
*/

void ft_show_info(int mod);
void ft_init_info(t_info *info);

/*
** main.c
*/

double ft_lint(double st, double end, double dec_perc);

#endif
