/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:47:51 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/10 21:26:32 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	img_pixel_put(t_imgdata *data, int x, int y, int color);

int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_imgdata	img;

	int	width = 1366;
	int height = 768;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, width, height, "fract-ol");
	img.img = mlx_new_image(mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int r = (int) sqrt(pow(abs(j - width/2), 2) + pow(abs(i - height/2), 2));
			img_pixel_put(&img, j, i, (r * i) ^ 0x000000FF);
		}
	}
	//img_pixel_put(&img, 0, 0, 0x0000FF00);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

void	img_pixel_put(t_imgdata *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
