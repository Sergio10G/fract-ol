/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:39:57 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/15 20:19:39 by sdiez-ga         ###   ########.fr       */
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

// Structs

typedef struct s_metadata
{
	int		width;
	int		height;
	double	scale;
	double	offset_x;
	double	offset_y;
}				t_metadata;

typedef struct	s_mlxvars
{
	void		*mlx;
	void		*win;
	t_metadata	*md;
}				t_mlxvars;

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

//	Functions

/* fractol.c functions */


/* input_parse.c */
void	check_params(int argc, char **argv);
void	check_colors(char *colors_cli);
void	check_julia_params(char *params_cli);
void	free_mat(char **str);

/* hex_utils.c functions */
int				is_in_base(char c);
int				pos_in_base(char c);
int				is_valid_hex(char *hex);
unsigned int	hextoui(char *hex);

/* utils.c functions */
void	ft_strtoupper(char *str);

/* metadata_funcs.c functions */
t_metadata *init_metadata(int width, int height);

/* complex_funcs.c functions */
t_complex	*init_complex();

/* algorithm.c functions */
unsigned int	mandelbrot(t_complex z, t_complex c, unsigned int iters, unsigned int i);

/* errors.c functions */
void	err_print_options(int errnum);

#endif
