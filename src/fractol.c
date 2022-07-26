/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:07:05 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/07/26 17:01:48 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_vars			*vars;
	t_fractaldata	*fd;
	t_complex		julia_c;

	if (argc < 2)
		err_print_options(1);
	julia_c.re = 0;
	julia_c.im = 0;
	check_params(argc, argv, &julia_c);
	fd = init_fractaldata();
	if (!fd)
		err_print_options(12);
	vars = init_vars();
	if (!vars)
	{
		free(fd);
		err_print_options(12);
	}
	vars->fd = fd;
	stage_2(argv, vars, julia_c);
}

void	stage_2(char **argv, t_vars *vars, t_complex julia_c)
{
	vars->id = init_imgdata(vars);
	if (!(vars->id))
	{
		free_all(vars);
		err_print_options(1);
	}
	assign_fractal_func(argv[1], vars, julia_c);
	assign_fractal_colors(0, vars);
	vars->mlx = mlx_init();
	vars->win = \
		mlx_new_window(vars->mlx, vars->width, vars->height, "fract-ol");
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	paint_fractal(vars);
	mlx_loop(vars->mlx);
}

void	assign_fractal_func(char *frctl_name, t_vars *vars, t_complex julia_c)
{
	vars->julia_c->re = julia_c.re;
	vars->julia_c->im = julia_c.im;
	if (ft_strncmp(frctl_name, "mandelbrot", 11) == 0)
		vars->fd->fractal_func = &mandelbrot;
	else if (ft_strncmp(frctl_name, "julia", 6) == 0)
	{
		vars->fd->fractal_func = &julia;
		vars->offset_x -= 0.5;
	}
	else if (ft_strncmp(frctl_name, "bship", 6) == 0)
	{
		vars->fd->fractal_func = &burning_ship;
		vars->offset_y += 0.4;
	}
	else
	{
		free_all(vars);
		err_print_options(1);
	}
}

void	assign_fractal_colors(int index, t_vars *vars)
{
	if (vars->fd->colors)
		free(vars->fd->colors);
	if (index == 1)
		vars->fd->colors = init_colorscheme_2(vars);
	else if (index == 2)
		vars->fd->colors = init_colorscheme_3(vars);
	else if (index == 3)
		vars->fd->colors = init_colorscheme_4(vars);
	else if (index == 4)
		vars->fd->colors = init_colorscheme_5(vars);
	else if (index == 5)
		vars->fd->colors = init_colorscheme_6(vars);
	else if (index == 6)
		vars->fd->colors = init_colorscheme_7(vars);
	else if (index == 7)
		vars->fd->colors = init_colorscheme_8(vars);
	else
		vars->fd->colors = init_colorscheme_1(vars);
	vars->fd->color_count = vars->fd->iters;
}

void	free_all(t_vars *vars)
{
	if (!vars)
		return ;
	if (vars->julia_c)
		free(vars->julia_c);
	if (vars->id)
	{
		if (vars->id->img)
			mlx_destroy_image(vars->mlx, vars->id->img);
		free(vars->id);
	}
	if (vars->fd)
	{
		if (vars->fd->colors)
			free(vars->fd->colors);
		free(vars->fd);
	}
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars);
}
