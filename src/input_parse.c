/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:40:09 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/22 19:07:18 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	check_params(int argc, char **argv)
{
	int	is_mandel;
	int	is_julia;
	int	is_bship;

	is_mandel = ft_strncmp(argv[1], "mandelbrot", 11) == 0;
	is_julia = ft_strncmp(argv[1], "julia", 6) == 0;
	is_bship = ft_strncmp(argv[1], "bship", 6) == 0;
	if (!is_mandel && !is_julia && !is_bship)
		err_print_options(22);
	if ((is_mandel || is_bship) && argc > 2)
		err_print_options(22);
	else if (is_julia)
	{
		if (argc < 3)
			err_print_options(22);
		check_julia_params(argv[2]);
	}
}

void	check_julia_params(char *params_cli)
{
	(void) params_cli;
	printf("Work in progress :D\n");
}

void	free_mat(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
