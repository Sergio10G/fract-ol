/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:22:42 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/18 19:00:49 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	img_pixel_put(t_imgdata *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	paint_and_put_mandelbrot(t_vars *vars)
{
	t_complex		*z;
	int				i;
	int				j;
	unsigned int	color;

	z = init_complex();
	while (i < vars->height)
	{
		while (j < vars->width)
		{
			z->re = (double)(j * 5) / vars->width * vars->scale;
			z->im = (double)(i * 3) / vars->height * vars->scale;
			z->re -= (double)(vars->offset_x) * vars->scale;
			z->im -= (double)(vars->offset_y) * vars->scale;
			color = choose_color(mandelbrot(*z, *z, vars->fd->iters, 0), vars);
			img_pixel_put(vars->img, j, i, color);
			j++;
		}
		i++;
	}
	free(z);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}
