/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:17:35 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/15 18:25:50 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	err_print_options(int errnum)
{
	char	*lines[8];
	int		i;

	lines[0] = "fractol uses:";
	lines[1] = "\t./fractol mandelbrot (Optional) <colors>";
	lines[2] = "\t./fractol julia <params> (Optional) <colors>";
	lines[3] = "\tWork in progress...\n";
	lines[4] = "Julia params: Work in progress...\n";
	lines[5] = "Colors: 4 byte ints in hex format separated by commas inside double-quotes.";
	lines[6] = "Example: \"0x00000000,0x00FF0000,0x0000FF00,0x000000FF\"";
	lines[7] = 0;

	printf("Error: %s\n\n", strerror(errnum));
	i = 0;
	while (lines[i])
		printf("%s\n", lines[i++]);
	exit(errnum);
}
