/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:56:41 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/10/04 16:27:26 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

UINT	choose_color(UINT i, t_vars *vars)
{
	return (vars->fd->colors[i % vars->fd->color_count]);
}

void	assign_fractal_colors(int index, t_vars *vars)
{
	if (vars->fd->colors)
		free(vars->fd->colors);
	if (index == 1)
		vars->fd->colors = init_colorscheme_2(vars);
	else if (index == 2)
		vars->fd->colors = init_colorscheme_3(vars);
	else if (index == 3)
		vars->fd->colors = init_colorscheme_4(vars);
	else if (index == 4)
		vars->fd->colors = init_colorscheme_5(vars);
	else if (index == 5)
		vars->fd->colors = init_colorscheme_6(vars);
	else if (index == 6)
		vars->fd->colors = init_colorscheme_7(vars);
	else if (index == 7)
		vars->fd->colors = init_colorscheme_8(vars);
	else
		vars->fd->colors = init_colorscheme_1(vars);
}

UINT	*init_colorscheme_1(t_vars *vars)
{
	UINT	*colors;
	UINT	gsc;
	UINT	augment;
	UINT	i;

	colors = ft_calloc(1, (vars->fd->iters) * sizeof(UINT));
	if (!colors)
		return (0);
	gsc = 0x00000000;
	colors[0] = gsc;
	augment = 256 / vars->fd->iters;
	i = 1;
	while (i < vars->fd->iters)
	{
		gsc += augment;
		gsc += augment << 8;
		gsc += augment << 16;
		colors[i] = gsc;
		i++;
	}
	vars->fd->color_count = vars->fd->iters;
	return (colors);
}

UINT	*init_colorscheme_2(t_vars *vars)
{
	UINT	*colors;
	UINT	gsc;
	UINT	augment;
	UINT	i;

	colors = ft_calloc(1, (vars->fd->iters) * sizeof(UINT));
	if (!colors)
		return (0);
	gsc = 0x00000000;
	colors[0] = gsc;
	augment = 256 / vars->fd->iters;
	i = 1;
	while (i < vars->fd->iters)
	{
		gsc += augment << 16;
		colors[i] = gsc;
		i++;
	}
	vars->fd->color_count = vars->fd->iters;
	return (colors);
}

UINT	*init_colorscheme_3(t_vars *vars)
{
	UINT	*colors;
	UINT	gsc;
	UINT	augment;
	UINT	i;

	colors = ft_calloc(1, (vars->fd->iters) * sizeof(UINT));
	if (!colors)
		return (0);
	gsc = 0x00000000;
	colors[0] = gsc;
	augment = 256 / vars->fd->iters;
	i = 1;
	while (i < vars->fd->iters)
	{
		gsc += augment << 8;
		colors[i] = gsc;
		i++;
	}
	vars->fd->color_count = vars->fd->iters;
	return (colors);
}
