/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:47:51 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/17 19:20:02 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	img_pixel_put(t_imgdata *data, int x, int y, int color);

int	keypress(int keycode, t_vars *vars)
{
	//Arriba: 126
	//Abajo: 125
	//Izquierda: 123
	//Derecha: 124
	(void) vars;
	printf("%d\n", keycode);
	if (keycode == 126)
	{
		printf("UP");
		vars->scale -= 0.1;
	}
	else if (keycode == 125)
	{
		vars->scale += 0.1;
		printf("DOWN");
	}
	else if (keycode == 123)
	{
		printf("LEFT");
	}
	else if (keycode == 124)
	{
		printf("RIGHT");
	}
	print_image(vars);
	return (0);
}

int	main(void)
{
	t_vars	*vars;
	void		*mlx;
	void		*mlx_win;
	t_imgdata	img;

	vars = init_vars();
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, vars->width, vars->height, "fract-ol");
	vars->mlx = mlx;
	vars->win = mlx_win;
	img.img = mlx_new_image(mlx, vars->width, vars->height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	vars->img = &img;
	print_image(vars);
	
	mlx_hook(mlx_win, 2, 1L<<0, keypress, vars);
	mlx_loop(mlx);
}

void	img_pixel_put(t_imgdata *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
} 

void	print_image(t_vars *vars)
{
	t_complex	*z;
	z = init_complex();
	for (int i = 0; i < vars->height; i++)
	{
		for (int j = 0; j < vars->width; j++)
		{
			z->re = (double) (j * 5) / vars->width * vars->scale;
			z->im = (double) (i * 3) / vars->height * vars->scale;
			z->re -= (double) (vars->offset_x) * vars->scale;
			z->im -= (double) (vars->offset_y) * vars->scale;
			//z->re = j - 960;
			//z->im = i - 540;
			unsigned int m = mandelbrot(*z, *z, 30, 0);
			int color;
			color = (m / 30.0) * 0x0000FF00;
			//printf("(%f + %fi) %u\n",z->re, z->im,  m);
			img_pixel_put(vars->img, j, i, color);
		}
	}
	//img_pixel_put(&img, 0, 0, 0x0000FF00);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}
