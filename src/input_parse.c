/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:40:09 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/07/26 17:15:01 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	check_params(int argc, char **argv, t_complex *julia_c)
{
	int	is_mandel;
	int	is_julia;
	int	is_bship;

	is_mandel = ft_strncmp(argv[1], "mandelbrot", 11) == 0;
	is_julia = ft_strncmp(argv[1], "julia", 6) == 0;
	is_bship = ft_strncmp(argv[1], "bship", 6) == 0;
	if (!is_mandel && !is_julia && !is_bship)
		err_print_options(22);
	else if (is_julia)
	{
		if (argc < 3)
			err_print_options(22);
		check_julia_params(argc, argv, julia_c);
	}
}

void	check_julia_params(int argc, char **argv, t_complex *julia_c)
{
	char	**num_strs;
	int		i;
	int		nums_ok;

	if (argc == 3)
	{
		num_strs = ft_split(argv[2], ' ');
		i = 0;
		while (num_strs[i])
			i++;
		if (i != 2)
			err_print_options(22);
	}
	else
	{
		num_strs = ft_calloc(3, sizeof(char *));
		num_strs[0] = ft_strdup(argv[2]);
		num_strs[1] = ft_strdup(argv[3]);
		num_strs[2] = 0;
	}
	nums_ok = check_julia_nums(num_strs);
	if (nums_ok)
	{
		julia_c->re = ft_atod(num_strs[0]);
		julia_c->im = ft_atod(num_strs[1]);
	}
	free_mat(num_strs);
	if (!nums_ok)
		err_print_options(22);
}

int	check_julia_nums(char **julia_nums)
{
	int	i;
	int	j;
	int	dot_index;
	int	dot_count;

	i = 0;
	while (julia_nums[i])
	{
		dot_count = 0;
		j = 0;
		while (julia_nums[i][j])
		{
			if (julia_nums[i][j] == '.')
			{
				dot_index = j;
				dot_count++;
			}
			else
			{
				if (!ft_isdigit(julia_nums[i][j]) && julia_nums[i][j] != '-')
					return (0);
			}
			j++;
		}
		if (dot_count != 1 || dot_index == 0 || dot_index == (int) ft_strlen(julia_nums[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_mat(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
