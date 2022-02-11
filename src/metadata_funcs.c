/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metadata_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:21:02 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/11 17:30:35 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_metadata	*init_metadata(int width, int height)
{
	t_metadata	*md;

	md = malloc(sizeof(t_metadata));
	if (!md)
		return (0);
	md->width = width;
	md->height = height;
	md->scale = 1.0;
	md->offset_x = 0;
	md->offset_y = 0;
	return (md);
}
