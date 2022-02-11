/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:40:09 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/11 15:51:03 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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
