/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:39:57 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/07/26 20:05:45 by sdiez-ga         ###   ########.fr       */
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
# define DEF_WIDTH 1024
# define DEF_HEIGHT 576
# define ITERS 100
# define UINT unsigned int

// Structs

typedef struct s_imgdata
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_imgdata;

typedef struct s_complex
{
	double	re;
	double	im;
}				t_complex;

typedef struct s_fractaldata
{
	unsigned int	(*fractal_func)(t_complex, t_complex, \
			unsigned int, unsigned int);
	UINT			iters;
	UINT			*colors;
	UINT			color_count;
}				t_fractaldata;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	double			scale;
	double			offset_x;
	double			offset_y;
	t_complex		julia_c;
	t_imgdata		*id;
	t_fractaldata	*fd;
}				t_vars;
//	Functions

/* fractol.c functions */
void			print_image(t_vars *vars);
void			stage_2(t_vars *vars);
void			assign_fractal_func(char farctal, t_vars *vars);
void			free_all(t_vars *vars);

/* transform_funcs.c functions */
t_complex		*transform_coordinates(t_complex *coords, t_vars *vars);
t_complex		apply_transform(t_complex coords, t_vars *vars);

/* img_funcs.c functions */
void			img_pixel_put(t_imgdata *data, int x, int y, UINT color);
void			paint_fractal(t_vars *vars);
void			transform_z_assign_c(t_complex *z, t_complex *c, t_vars *vars);

/* color_funcs.c & color_funcs2.c functions */
UINT			choose_color(UINT i, t_vars *vars);
void			assign_fractal_colors(int index, t_vars *vars);
UINT			*init_colorscheme_1(t_vars *vars);
UINT			*init_colorscheme_2(t_vars *vars);
UINT			*init_colorscheme_3(t_vars *vars);
UINT			*init_colorscheme_4(t_vars *vars);
UINT			*init_colorscheme_5(t_vars *vars);
UINT			*init_colorscheme_6(t_vars *vars);
UINT			*init_colorscheme_7(t_vars *vars);
UINT			*init_colorscheme_8(t_vars *vars);

/* key_funcs.c functions */
int				key_hook(int keycode, t_vars *vars);
int				mouse_hook(int button, int x, int y, t_vars *vars);
void			change_colors(int keycode, t_vars *vars);

/* input_parse.c functions */
t_complex		check_params(int argc, char **argv, char *fractal);
t_complex		check_julia_params(int argc, char **argv);
int				check_julia_nums(char **julia_nums);
void			free_mat(char **str);

/* utils.c functions */
void			ft_strtoupper(char *str);
double			ft_atod(char *num);

/* init_structs.c functions */
t_vars			*init_vars(void);
t_complex		*init_complex(void);
t_fractaldata	*init_fractaldata(void);
t_imgdata		*init_imgdata(t_vars *vars);

/* algorithm.c functions */
UINT			mandelbrot(t_complex z, t_complex c, UINT iters, UINT i);
UINT			julia(t_complex z, t_complex c, UINT iters, UINT i);
UINT			burning_ship(t_complex z, t_complex c, UINT iters, UINT i);

/* errors.c functions */
void			err_print_options(int errnum);

#endif
