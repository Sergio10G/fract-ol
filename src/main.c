/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:47:51 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/10 19:18:24 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	img_pixel_put(t_imgdata *data, int x, int y, int color);

int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_imgdata	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "fract-ol");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	for (int i = 0; i < 1080; i++)
	{
		for (int j = 0; j < 1920; j++)
		{
			int r = (int) sqrt(pow(abs(j - 1920/2), 2) + pow(abs(i - 1080/2), 2));
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
