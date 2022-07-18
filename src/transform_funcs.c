/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:17:40 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/07/18 19:54:48 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex *transform_coordinates(t_complex *coords, t_vars *vars)
{
	*coords = apply_transform(*coords, vars);
	return (coords);
}

t_complex apply_transform(t_complex coords, t_vars *vars)
{
	coords.re = (double)(coords.re * 5.0) / vars->width * vars->scale;
	coords.im = (double)(coords.im * 3.0) / vars->height * vars->scale;
	coords.re -= (double)vars->offset_x * vars->scale;
	coords.im -= (double)vars->offset_y * vars->scale;
	return (coords);
}
