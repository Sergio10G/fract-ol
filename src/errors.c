/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:17:35 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/17 16:46:23 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	err_print_options(int errnum)
{
	char	*lines[6];
	int		i;

	lines[0] = "fractol uses:";
	lines[1] = "\t./fractol mandelbrot";
	lines[2] = "\t./fractol julia <params>";
	lines[3] = "\t./fractol bship\n";
	lines[4] = "Julia params: Work in progress...\n";
	lines[5] = 0;

	printf("Error: %s\n\n", strerror(errnum));
	i = 0;
	while (lines[i])
		printf("%s\n", lines[i++]);
	exit(errnum);
}
