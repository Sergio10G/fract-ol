/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_funcs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 17:55:03 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/25 18:00:37 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	*init_colorscheme_5(t_vars *vars)
{
	int				*colors;
	unsigned int	gsc;
	unsigned int	augment;
	unsigned int	i;

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
		colors[i] = gsc;
		i++;
	}
	colors[i++] = 0x00000000;
	vars->fd->color_count = vars->fd->iters;
	return (colors);
}

int	*init_colorscheme_6(t_vars *vars)
{
	int				*colors;
	unsigned int	gsc;
	unsigned int	augment;
	unsigned int	i;

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
		gsc += augment << 16;
		colors[i] = gsc;
		i++;
	}
	colors[i++] = 0x00000000;
	vars->fd->color_count = vars->fd->iters;
	return (colors);
}

int	*init_colorscheme_7(t_vars *vars)
{
	int				*colors;
	unsigned int	gsc;
	unsigned int	augment;
	unsigned int	i;

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
		gsc += augment << 16;
		colors[i] = gsc;
		i++;
	}
	colors[i++] = 0x00000000;
	vars->fd->color_count = vars->fd->iters;
	return (colors);
}
