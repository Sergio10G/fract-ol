/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:39:57 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/22 19:28:54 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

//	Libraries
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

//	Macros
# define DEF_WIDTH 889
# define DEF_HEIGHT 500

// Structs

typedef struct	s_imgdata 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_imgdata;

typedef struct	s_complex
{
	double re;
	double im;
}				t_complex;

typedef struct	s_fractaldata
{
	void			(*paint_fractal)(void *);
	unsigned int	iters;
	int				*colors;
	unsigned int	color_count;
}				t_fractaldata;

typedef struct	s_vars
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	double			scale;
	double			offset_x;
	double			offset_y;
	t_imgdata		*id;
	t_fractaldata	*fd;
}				t_vars;
//	Functions

/* fractol.c functions */
void	print_image(t_vars *vars);
void	stage_2(char **argv, t_vars *vars);
void	assign_fractal_func(char *fractal_name, t_vars *vars);
void	assign_fractal_colors(int index, t_vars *vars);
void	free_all(t_vars *vars);

/* img_funcs.c functions */
void	img_pixel_put(t_imgdata *data, int x, int y, unsigned int color);
void	paint_mandelbrot(void *param);
void	paint_julia(void *param);
void	paint_bship(void *param);

/* color_funcs.c functions */
int				*init_colorscheme_1(t_vars *vars);
unsigned int	choose_color(unsigned int i, t_vars *vars);

/* key_funcs.c functions */
int	key_hook(int keycode, void *param);
int	mouse_hook(int button, int x, int y, void *param);

/* input_parse.c functions */
void	check_params(int argc, char **argv);
void	check_julia_params(char *params_cli);
void	free_mat(char **str);

/* utils.c functions */
void	ft_strtoupper(char *str);

/* init_structs.c functions */
t_vars			*init_vars();
t_complex		*init_complex();
t_fractaldata	*init_fractaldata();
t_imgdata		*init_imgdata(t_vars *vars);

/* algorithm.c functions */
unsigned int	mandelbrot(t_complex z, t_complex c, unsigned int iters, unsigned int i);
unsigned int	julia(t_complex z, t_complex c, unsigned int iters, unsigned int i);
unsigned int	burning_ship(t_complex z, t_complex c, unsigned int iters, unsigned int i);

/* errors.c functions */
void	err_print_options(int errnum);

#endif
