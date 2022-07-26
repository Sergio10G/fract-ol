/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:33:46 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/07/25 19:27:49 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

size_t	mandelbrot(t_complex z, t_complex c, size_t iters, size_t i)
{
	double	x;
	double	y;
	double	x_sq;
	double	y_sq;

	x = z.re;
	y = z.im;
	x_sq = pow(x, 2);
	y_sq = pow(y, 2);
	if (iters == i)
		return (i);
	if (x_sq + y_sq > 4)
		return (i);
	else
	{
		z.re = x_sq - y_sq + c.re;
		z.im = 2 * x * y + c.im;
		return (mandelbrot(z, c, iters, ++i));
	}
}

size_t	julia(t_complex z, t_complex c, size_t iters, size_t i)
{
	double	x;
	double	y;
	double	x_sq;
	double	y_sq;

	x = z.re;
	y = z.im;
	x_sq = pow(x, 2);
	y_sq = pow(y, 2);
	if (iters == i)
		return (i);
	if (x_sq + y_sq > 4)
		return (i);
	else
	{
		z.re = x_sq - y_sq + c.re;
		z.im = 2 * x * y + c.im;
		return (julia(z, c, iters, ++i));
	}
}

size_t	burning_ship(t_complex z, t_complex c, size_t iters, size_t i)
{
	double	x;
	double	y;
	double	x_sq;
	double	y_sq;

	x = fabs(z.re);
	y = fabs(z.im);
	x_sq = pow(x, 2);
	y_sq = pow(y, 2);
	if (iters == i)
		return (i);
	if (x_sq + y_sq > 5)
		return (i);
	else
	{
		z.re = x_sq - y_sq + c.re;
		z.im = 2 * x * y + c.im;
		return (burning_ship(z, c, iters, ++i));
	}
}
