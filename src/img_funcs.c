/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:22:42 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/07/26 17:11:56 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	img_pixel_put(t_imgdata *data, int x, int y, size_t color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(size_t *)dst = color;
}

void	paint_fractal(t_vars *vars)
{
	t_complex	*z;
	t_complex	*c;
	int			i;
	int			j;

	z = init_complex();
	c = 0;
	i = 0;
	while (i < vars->height)
	{
		j = 0;
		while (j < vars->width)
		{
			z->re = j;
			z->im = i;
			transform_z_assign_c(z, &c, vars);
			img_pixel_put(vars->id, j, i, \
				choose_color(vars->fd->fractal_func(*z, *c, \
				vars->fd->iters, 0), vars));
			j++;
		}
		i++;
	}
	free(z);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->id->img, 0, 0);
}

void	transform_z_assign_c(t_complex *z, t_complex **c, t_vars *vars)
{
	z = transform_coordinates(z, vars);
	if (vars->fd->fractal_func == &julia)
		*c = &vars->julia_c;
	else
		*c = z;
}
