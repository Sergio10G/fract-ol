/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:22:42 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/25 18:47:01 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	img_pixel_put(t_imgdata *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	paint_mandelbrot(void *param)
{
	t_complex		*z;
	int				i;
	int				j;
	unsigned int	color;
	t_vars			*vars;

	vars = (t_vars *)param;
	z = init_complex();
	i = 0;
	while (i < vars->height)
	{
		j = 0;
		while (j < vars->width)
		{
			z->re = (double)(j * 5.0) / vars->width / vars->scale;
			z->im = (double)(i * 3.0) / vars->height / vars->scale;
			z->re -= (double)(vars->offset_x) / vars->scale;
			z->im -= (double)(vars->offset_y) / vars->scale;
			color = choose_color(mandelbrot_iter(*z, *z, vars->fd->iters, 0), vars);
			img_pixel_put(vars->id, j, i, color);
			j++;
		}
		i++;
	}
	free(z);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->id->img, 0, 0);
}

void	paint_julia(void *param)
{
	t_complex		*z;
	int				i;
	int				j;
	unsigned int	color;
	t_vars			*vars;

	vars = (t_vars *)param;
	z = init_complex();
	i = 0;
	while (i < vars->height)
	{
		j = 0;
		while (j < vars->width)
		{
			z->re = (double)(j * 5.0) / vars->width / vars->scale;
			z->im = (double)(i * 3.0) / vars->height / vars->scale;
			z->re -= (double)(vars->offset_x) / vars->scale;
			z->im -= (double)(vars->offset_y) / vars->scale;
			color = choose_color(mandelbrot(*z, *z, vars->fd->iters, 0), vars);
			img_pixel_put(vars->id, j, i, color);
			j++;
		}
		i++;
	}
	free(z);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->id->img, 0, 0);
}

void	paint_bship(void *param)
{
	t_complex		*z;
	int				i;
	int				j;
	unsigned int	color;
	t_vars			*vars;

	vars = (t_vars *)param;
	z = init_complex();
	i = 0;
	while (i < vars->height)
	{
		j = 0;
		while (j < vars->width)
		{
			z->re = (double)(j * 5.0) / vars->width / vars->scale;
			z->im = (double)(i * 3.0) / vars->height / vars->scale;
			z->re -= (double)(vars->offset_x) / vars->scale;
			z->im -= (double)(vars->offset_y) / vars->scale;
			color = choose_color(burning_ship(*z, *z, vars->fd->iters, 0), vars);
			img_pixel_put(vars->id, j, i, color);
			j++;
		}
		i++;
	}
	free(z);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->id->img, 0, 0);
}
