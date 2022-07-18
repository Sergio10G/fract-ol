/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:42:46 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/07/18 19:54:17 by sdiez-ga         ###   ########.fr       */
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
	//printf("keycode: %d\n", keycode);
	change_colors(keycode, vars);
	if (keycode == 53)
	{
		free_all(vars);
		exit(0);
	}
	else if (keycode == 126)
		vars->offset_y += 0.1;
	else if (keycode == 125)
		vars->offset_y -= 0.1;
	else if (keycode == 123)
		vars->offset_x += 0.1;
	else if (keycode == 124)
		vars->offset_x -= 0.1;
	else
		return (0);
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
		vars->scale -= vars->scale / 10.0;
	else if (button == 5)
		vars->scale += vars->scale / 10.0;
	else
		return (0);
	paint_fractal(vars);
	return (0);
}

void	change_colors(int keycode, t_vars *vars)
{
	if (keycode >= 18 && keycode <= 21)
		assign_fractal_colors(keycode - 18, vars);
	else if (keycode == 23)
		assign_fractal_colors(4, vars);
	else if (keycode == 22)
		assign_fractal_colors(5, vars);
	else if (keycode == 26)
		assign_fractal_colors(6, vars);
	else
		return ;
	paint_fractal(vars);
}
