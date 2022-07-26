/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:07:05 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/07/26 20:06:39 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_vars			*vars;
	t_fractaldata	*fd;
	t_complex		julia_c;
	char			fractal;

	fractal = 'e';
	if (argc < 2)
		err_print_options(1);
	julia_c = check_params(argc, argv, &fractal);
	fd = init_fractaldata();
	if (!fd)
		err_print_options(12);
	vars = init_vars();
	if (!vars)
	{
		free(fd);
		err_print_options(12);
	}
	vars->julia_c = julia_c;
	vars->fd = fd;
	assign_fractal_func(fractal, vars);
	assign_fractal_colors(0, vars);
	stage_2(vars);
}

void	stage_2(t_vars *vars)
{
	vars->id = init_imgdata(vars);
	if (!(vars->id))
	{
		free_all(vars);
		err_print_options(1);
	}
	vars->win = \
		mlx_new_window(vars->mlx, vars->width, vars->height, "fract-ol");
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_mouse_hook(vars->win, mouse_hook, vars);
	paint_fractal(vars);
	mlx_loop(vars->mlx);
}

void	assign_fractal_func(char fractal, t_vars *vars)
{
	if (fractal == 'm')
		vars->fd->fractal_func = &mandelbrot;
	else if (fractal == 'j')
	{
		vars->fd->fractal_func = &julia;
		vars->offset_x -= 0.5;
	}
	else if (fractal == 'b')
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

void	free_all(t_vars *vars)
{
	if (!vars)
		return ;
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
