/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_funcs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:55:03 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/10/04 16:28:12 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

UINT	*init_colorscheme_4(t_vars *vars)
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
		colors[i] = gsc;
		i++;
	}
	vars->fd->color_count = vars->fd->iters;
	return (colors);
}

UINT	*init_colorscheme_5(t_vars *vars)
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
		colors[i] = gsc;
		i++;
	}
	vars->fd->color_count = vars->fd->iters;
	return (colors);
}

UINT	*init_colorscheme_6(t_vars *vars)
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
		gsc += augment << 16;
		colors[i] = gsc;
		i++;
	}
	vars->fd->color_count = vars->fd->iters;
	return (colors);
}

UINT	*init_colorscheme_7(t_vars *vars)
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
		gsc += augment << 16;
		colors[i] = gsc;
		i++;
	}
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
	colors[1] = 0x00403741;
	colors[2] = 0X00DA3E5C;
	colors[3] = 0X00A83AA8;
	colors[4] = 0X00BA5CCA;
	colors[5] = 0X0006D5FC;
	colors[6] = 0X000794FA;
	colors[7] = 0X00AAAAFF;
	colors[8] = 0X008888FF;
	colors[9] = 0X004444FF;
	vars->fd->color_count = 10;
	return (colors);
}
