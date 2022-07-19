/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:22:42 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/07/19 19:05:08 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	img_pixel_put(t_imgdata *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	paint_fractal(t_vars *vars)
{
	t_complex		*z;
	int				i;
	int				j;
	unsigned int	color;

	z = init_complex();
	i = 0;
	while (i < vars->height)
	{
		j = 0;
		while (j < vars->width)
		{
			z->re = j;
			z->im = i;
			z = transform_coordinates(z, vars);
			if (vars->fd->fractal_func == &julia)
				color = choose_color(vars->fd->fractal_func(*z, *vars->julia_c, vars->fd->iters, 0), vars);
			else
				color = choose_color(vars->fd->fractal_func(*z, *z, vars->fd->iters, 0), vars);
			img_pixel_put(vars->id, j, i, color);
			j++;
		}
		i++;
	}
	free(z);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->id->img, 0, 0);
}
