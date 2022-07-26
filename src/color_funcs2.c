/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_funcs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:55:03 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/07/26 19:58:36 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

UINT	*init_colorscheme_4(t_vars *vars)
{
	UINT	*colors;
	UINT	gsc;
	UINT	augment;
	UINT	i;

	colors = ft_calloc(1, (vars->fd->iters + 1) * sizeof(UINT));
	if (!colors)
		return (0);
	gsc = 0x00000000;
	colors[0] = gsc;
	augment = 256 / vars->fd->iters;
	i = 1;
	while (i < vars->fd->iters)
	{
		gsc += augment;
		colors[i] = gsc;
		i++;
	}
	colors[i++] = 0x00000000;
	vars->fd->color_count = vars->fd->iters;
	return (colors);
}

UINT	*init_colorscheme_5(t_vars *vars)
{
	UINT	*colors;
	UINT	gsc;
	UINT	augment;
	UINT	i;

	colors = ft_calloc(1, (vars->fd->iters + 1) * sizeof(UINT));
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
		colors[i] = gsc;
		i++;
	}
	colors[i++] = 0x00000000;
	vars->fd->color_count = vars->fd->iters;
	return (colors);
}

UINT	*init_colorscheme_6(t_vars *vars)
{
	UINT	*colors;
	UINT	gsc;
	UINT	augment;
	UINT	i;

	colors = ft_calloc(1, (vars->fd->iters + 1) * sizeof(UINT));
	if (!colors)
		return (0);
	gsc = 0x00000000;
	colors[0] = gsc;
	augment = 256 / vars->fd->iters;
	i = 1;
	while (i < vars->fd->iters)
	{
		gsc += augment << 8;
		gsc += augment << 16;
		colors[i] = gsc;
		i++;
	}
	colors[i++] = 0x00000000;
	vars->fd->color_count = vars->fd->iters;
	return (colors);
}

UINT	*init_colorscheme_7(t_vars *vars)
{
	UINT	*colors;
	UINT	gsc;
	UINT	augment;
	UINT	i;

	colors = ft_calloc(1, (vars->fd->iters + 1) * sizeof(UINT));
	if (!colors)
		return (0);
	gsc = 0x00000000;
	colors[0] = gsc;
	augment = 256 / vars->fd->iters;
	i = 1;
	while (i < vars->fd->iters)
	{
		gsc += augment;
		gsc += augment << 16;
		colors[i] = gsc;
		i++;
	}
	colors[i++] = 0x00000000;
	vars->fd->color_count = vars->fd->iters;
	return (colors);
}

UINT	*init_colorscheme_8(t_vars *vars)
{
	UINT	*colors;

	colors = ft_calloc(10, sizeof(UINT));
	if (!colors)
		return (0);
	colors[0] = 0x00000000;
	colors[1] = 0x0046B57C;
	colors[2] = 0X0035982C;
	colors[3] = 0X0043B6CB;
	colors[4] = 0X00934D38;
	colors[5] = 0X006C7230;
	colors[6] = 0X009BD3BF;
	colors[7] = 0X004B7618;
	colors[8] = 0X00CDCE34;
	colors[9] = 0X002D7C8C;
	vars->fd->color_count = 10;
	return (colors);
}
