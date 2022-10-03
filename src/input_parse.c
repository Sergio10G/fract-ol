/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:40:09 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/10/03 17:46:17 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	check_params(int argc, char **argv, char *fractal)
{
	t_complex	julia_c;

	julia_c.re = 0;
	julia_c.im = 0;
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		*fractal = 'm';
	else if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		if (argc < 3)
			err_print_options(22);
		*fractal = 'j';
		julia_c = check_julia_params(argc, argv);
	}
	else if (ft_strncmp(argv[1], "bship", 6) == 0)
		*fractal = 'b';
	else
		err_print_options(22);
	return (julia_c);
}

char	**extract_julia_nums(int argc, char **argv)
{
	char	**num_strs;
	int		i;

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
	return (num_strs);
}

t_complex	check_julia_params(int argc, char **argv)
{
	char		**num_strs;
	int			nums_ok;
	t_complex	julia_c;

	julia_c.re = 0;
	julia_c.im = 0;
	num_strs = extract_julia_nums(argc, argv);
	nums_ok = check_julia_nums(num_strs);
	if (nums_ok)
	{
		julia_c.re = ft_atod(num_strs[0]);
		julia_c.im = ft_atod(num_strs[1]);
	}
	free_mat(num_strs);
	if (!nums_ok)
		err_print_options(22);
	return (julia_c);
}

int	check_julia_nums(char **julia_nums)
{
	int	i;
	int	j;
	int	dot_index;
	int	dot_count;

	i = -1;
	while (julia_nums[++i])
	{
		dot_count = 0;
		j = -1;
		while (julia_nums[i][++j])
		{
			if (julia_nums[i][j] == '.')
			{
				dot_index = j;
				dot_count++;
			}
			else
				if (!ft_isdigit(julia_nums[i][j]) && julia_nums[i][j] != '-')
					return (0);
		}
		if (dot_count > 1 || dot_index == (int) ft_strlen(julia_nums[i]) - 1)
			return (0);
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
