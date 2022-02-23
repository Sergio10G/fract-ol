/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:42:46 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/22 18:18:12 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	key_hook(int keycode, void *param)
{
	t_vars	*vars;
	// Up: 126
	// Down: 125
	// Left: 123
	// Right: 124
	// Esc: 53
	vars = (t_vars *)param;
	if (keycode == 126)
		vars->offset_y -= 0.1;
	else if (keycode == 125)
		vars->offset_y = += 0.1;
	else if (keycode == 123)
		vars->offset_x += 0.1;
	else if (keycode == 124)
		vars->offset_x -= 0.1;
	else if (keycode == 53)
	{
	
	}
	printf("keycode: %d\n" + keycode);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_vars	*vars;
	// ScrollUp: 4
	// ScrollDown: 5
	vars = (t_vars *)param;
	if (button = 4)
		vars->scale += 0.1;
	else if (button = 5)
		vars->scale += 0.1;
	vars->
}
