/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:00:26 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/17 18:04:12 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_vars	*init_vars()
{
	t_vars	*vars;

	vars = ft_calloc(1, sizeof(t_vars));
	if (!vars)
		return (0);
	vars->width = DEF_WIDTH;
	vars->height = DEF_HEIGHT;
	vars->scale = 1.0;
	vars->offset_x = 3.0;
	vars->offset_y = 1.5;
	return (vars);
}

t_complex	*init_complex()
{
	t_complex	*comp;

	comp = malloc(sizeof(t_complex));
	if (!comp)
		return (0);
	comp->re = 0;
	comp->im = 0;
	return (comp);
}

t_fractaldata	*init_fractaldata()
{
	t_fractaldata	*fd;

	fd = ft_calloc(1, sizeof(t_fractaldata));
	return (fd);
}
