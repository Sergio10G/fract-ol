/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:07:05 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/18 19:03:59 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int argc, char **argv)
{
	t_vars			*vars;
	t_fractaldata	*fd;
	t_imgdata		*id;

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
	assign_fractal_func(argv[1], fd);
	assign_fractal_colors(0, fd);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, "fract-ol");
	// print image
	mlx_loop(vars->mlx);
}

void	assign_fractal_func(char *fractal_name, t_fractaldata *fd)
{
	if (ft_strncmp(fractal_name, "mandelbrot", 11) == 0)
		fd->fractal = &mandelbrot;
	else if (ft_strncmp(fractal_name, "julia", 6) == 0)
		fd->fractal = &julia;
	else if (ft_strncmp(fractal_name, "bship", 6) == 0)
		fd->fractal = &burning_ship;
}

void	assign_fractal_colors(int index, t_fractaldata *fd)
{
	fd->colors = init_colorscheme_1();
	fd->color_count = ft_lstsize(*(fd->colors));
}

void	init_img()
{

}
