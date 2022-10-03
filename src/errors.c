/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:17:35 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/10/03 16:51:24 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	err_print_options(int errnum)
{
	char	*lines[10];
	int		i;

	lines[0] = "fractol uses:";
	lines[1] = "\t./fractol mandelbrot";
	lines[2] = "\t./fractol julia a b -or- ./fractol julia \"a b\"";
	lines[3] = "\t./fractol bship\n";
	lines[4] = "Julia set params: The julia set this program shows is";
	lines[5] = "f(z) = z^2 + c, where c is a complex number of the form";
	lines[6] = "a + bi. The parameters a and b must be dot-separated";
	lines[7] = "numbers with decimals. The numbers must fit in a 64bit";
	lines[8] = "double or behaviour will be undefined.\n";
	lines[9] = 0;
	printf("Error: %s\n\n", strerror(errnum));
	i = 0;
	while (lines[i])
		printf("%s\n", lines[i++]);
	exit(errnum);
}
