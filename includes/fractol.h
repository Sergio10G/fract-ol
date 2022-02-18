/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:39:57 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/18 19:02:56 by sdiez-ga         ###   ########.fr       */
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
# define DEF_WIDTH 1920
# define DEF_HEIGHT 1080

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
	unsigned int	(*fractal)(t_complex*, t_complex*, unsigned int, unsigned int);
	unsigned int	iters;
	t_list			**colors;
	int				color_count;
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

/* input_parse.c */
void	check_params(int argc, char **argv);
void	check_julia_params(char *params_cli);

/* utils.c functions */
void	ft_strtoupper(char *str);

/* init_structss.c functions */
t_complex		*init_complex();
t_vars			*init_vars();
t_fractaldata	*init_fractaldata();

/* algorithm.c functions */
unsigned int	mandelbrot(t_complex z, t_complex c, unsigned int iters, unsigned int i);
unsigned int	julia(t_complex z, t_complex c, unsigned int iters, unsigned int i);
unsigned int	burning_ship(t_complex z, t_complex c, unsigned int iters, unsigned int i);

/* errors.c functions */
void	err_print_options(int errnum);

#endif
