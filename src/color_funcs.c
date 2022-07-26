/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:56:41 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/07/26 17:04:23 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

size_t	choose_color(size_t i, t_vars *vars)
{
	if (vars->fd->iters == vars->fd->color_count)
		return (vars->fd->colors[i]);
	else
		return (vars->fd->colors[i % vars->fd->color_count]);
	return (0);
}

int	*init_colorscheme_1(t_vars *vars)
{
	int		*colors;
	size_t	gsc;
	size_t	augment;
	size_t	i;

	colors = ft_calloc(1, (vars->fd->iters + 1) * sizeof(int));
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
	colors[i++] = 0x00FFFFFF;
	vars->fd->color_count = vars->fd->iters;
	return (colors);
}

int	*init_colorscheme_2(t_vars *vars)
{
	int		*colors;
	size_t	gsc;
	size_t	augment;
	size_t	i;

	colors = ft_calloc(1, (vars->fd->iters + 1) * sizeof(int));
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
	colors[i++] = 0x00000000;
	vars->fd->color_count = vars->fd->iters;
	return (colors);
}

int	*init_colorscheme_3(t_vars *vars)
{
	int		*colors;
	size_t	gsc;
	size_t	augment;
	size_t	i;

	colors = ft_calloc(1, (vars->fd->iters + 1) * sizeof(int));
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
	colors[i++] = 0x00000000;
	vars->fd->color_count = vars->fd->iters;
	return (colors);
}

int	*init_colorscheme_4(t_vars *vars)
{
	int		*colors;
	size_t	gsc;
	size_t	augment;
	size_t	i;

	colors = ft_calloc(1, (vars->fd->iters + 1) * sizeof(int));
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
