/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:56:41 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/22 19:58:36 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	*init_colorscheme_1(t_vars *vars)
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
		gsc += augment << 16;
		colors[i] = gsc;
		i++;
	}
	colors[i++] = 0x00FFFFFF;
	vars->fd->color_count = vars->fd->iters;
	return (colors);
}

unsigned int choose_color(unsigned int i,  t_vars *vars)
{
	if (vars->fd->iters == vars->fd->color_count)
	{
		return (vars->fd->colors[i]);
	}
	return (0);
}
