/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:07:05 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/17 18:43:06 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_vars			*vars;
	t_fractaldata	*frcd;

	if (argc < 2 || argc > 3)
		err_print_options(1);
	check_params(argc, argv);
	frcd = init_fractaldata();
	if (!frcd)
		err_print_options(12);
	vars = init_vars();
	if (!vars)
	{
		free(frcd);
		err_print_options(12);
	}
	assign_fractal_func(argv[1], frcd);
	assign_fractal_colors(0, frcd);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "fract-ol");

}

void	assign_fractal_func(char *fractal_name, t_fractaldata *frcd)
{
	if (ft_strncmp(fractal_name, "mandelbrot", 11) == 0)
		frcd->fractal = &mandelbrot;
	else if (ft_strncmp(fractal_name, "julia", 6) == 0)
		frcd->fractal = &julia;
	else if (ft_strncmp(fractal_name, "bship", 6) == 0)
		frcd->fractal = &burning_ship;
}

void	assign_fractal_colors(int index, t_fractaldata *frcd)
{
	if (frcd->colors)
		ft_lstclear(frcd->colors);
	if (index == 1)
	{
	
	}
	else if(index == 2)
	{
	
	}
	else if(index == 3)
	{
	
	}
	else
	{
	
	}
}

void	stage_2(t_vars *vars, t_fractaldata *frcd)
{

}
