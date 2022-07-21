/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:42:46 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/07/21 15:21:08 by sergiodg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_hook(int keycode, t_vars *vars)
{
	// Up: 126
	// Down: 125
	// Left: 123
	// Right: 124
	// Esc: 53
	printf("keycode: %d\n", keycode);
	change_colors(keycode, vars);
	if (keycode == 65307)
	{
		free_all(vars);
		exit(0);
	}
	else if (keycode == 65362)
		vars->offset_y += 0.1;
	else if (keycode == 65364)
		vars->offset_y -= 0.1;
	else if (keycode == 65361)
		vars->offset_x += 0.1;
	else if (keycode == 65363)
		vars->offset_x -= 0.1;
	else if (keycode == 65451)
		vars->scale += vars->scale / 10.0;
	else if (keycode == 65453)
		vars->scale -= vars->scale / 10.0;
	paint_fractal(vars);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	// ScrollUp: 4
	// ScrollDown: 5
	(void) x;
	(void) y;
	if (button == 4)
		vars->scale += vars->scale / 10.0;
	else if (button == 5)
		vars->scale -= vars->scale / 10.0;
	paint_fractal(vars);
	return (0);
}

void	change_colors(int keycode, t_vars *vars)
{
	if (keycode >= 49 && keycode <= 55)
		assign_fractal_colors(keycode - 49, vars);
}
