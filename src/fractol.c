/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:07:05 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/22 19:29:09 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_vars			*vars;
	t_fractaldata	*fd;

	if (argc < 2 || argc > 3)
		err_print_options(1);
	check_params(argc, argv);
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
	vars->id = init_imgdata(vars);
	if (!(vars->id))
	{
		free_all(vars);
		err_print_options(1);
	}
	stage_2(argv, vars);
}

void	stage_2(char **argv, t_vars *vars)
{
	assign_fractal_func(argv[1], vars);
	assign_fractal_colors(0, vars);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "fract-ol");
	vars->fd->paint_fractal(vars);
	mlx_loop(vars->mlx);
}

void	assign_fractal_func(char *fractal_name, t_vars *vars)
{
	if (ft_strncmp(fractal_name, "mandelbrot", 11) == 0)
		vars->fd->paint_fractal = &paint_mandelbrot;
	else if (ft_strncmp(fractal_name, "julia", 6) == 0)
		printf("Work in progress :D\n");
		//vars->fd->paint_fractal = &julia;
	else if (ft_strncmp(fractal_name, "bship", 6) == 0)
		vars->fd->paint_fractal = &paint_bship;
	else
	{
		free_all(vars);
		err_print_options(1);
	}
}

void	assign_fractal_colors(int index, t_vars *vars)
{
	if (index == 0)
		vars->fd->colors = init_colorscheme_1(vars);
}

void	free_all(t_vars *vars)
{
	if (!vars)
		return ;
	if (vars->id)
	{
		if (vars->id->img)
			mlx_destroy_image(vars->mlx, vars->id->img);
		if (vars->id->addr)
			free(vars->id->addr);
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
