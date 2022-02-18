/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:56:41 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/18 19:06:08 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_list	**init_colorscheme_1()
{
	t_list			*colors;
	unsigned int	gsc;
	t_list			*tmp;

	gsc = 0x00000000;
	colors = ft_lstnew(gsc);
	gsc += 0x00080808;
	while (gsc < 0x00FFFFFF)
	{
		tmp = ft_lstnew(gsc);
		ft_lstadd_back(&colors, tmp);
		gsc += 0x00080808;
	}
	return (&colors);
}

unsigned int choose_color(unsigned int i,  t_vars *vars)
{
	if (i == vars->fd->iters)
		return (vars->fd->colors)
}
