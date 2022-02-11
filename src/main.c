/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:47:51 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/11 18:02:56 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	img_pixel_put(t_imgdata *data, int x, int y, int color);

int	keypress(int keycode, t_mlxvars *vars)
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
	}
	else if (keycode == 125)
	{
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
	return (0);
}

int	main(void)
{
	t_mlxvars	*vars;
	void		*mlx;
	void		*mlx_win;
	t_imgdata	img;
	t_metadata	*md;

	vars = malloc(sizeof(t_mlxvars));
	if (!vars)
		return (0);
	md = init_metadata(1920, 1080);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, md->width, md->height, "fract-ol");
	vars->mlx = mlx;
	vars->win = mlx_win;
	vars->md = md;
	img.img = mlx_new_image(mlx, md->width, md->height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	t_complex	*z;
	z = init_complex();
	md->offset_x = 1;
	md->scale = 0.5;
	for (int i = 0; i < md->height; i++)
	{
		for (int j = 0; j < md->width; j++)
		{
			z->re = (double) (j * 5) / md->width * md->scale;
			z->im = (double) (i * 3) / md->height * md->scale;
			z->re -= (double) (3 + md->offset_x) * md->scale;
			z->im -= (double) (1.5 + md->offset_y) * md->scale;
			//z->re = j - 960;
			//z->im = i - 540;
			unsigned int m = mandelbrot(*z, *z, 30, 0);
			int color;
			color = (m / 30.0) * 0x0000FF00;
			//printf("(%f + %fi) %u\n",z->re, z->im,  m);
			img_pixel_put(&img, j, i, color);
		}
	}
	//img_pixel_put(&img, 0, 0, 0x0000FF00);
	mlx_hook(mlx_win, 2, 1L<<0, keypress, vars);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

void	img_pixel_put(t_imgdata *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
