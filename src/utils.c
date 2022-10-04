/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:32:06 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/10/04 16:56:17 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	ft_atod(char *num)
{
	double	out;
	int		i;
	int		int_part;

	out = 0.0;
	i = ft_strlen(num) - 1;
	while (num[i] != '.')
	{
		out += num[i] - '0';
		out /= 10;
		i--;
	}
	i = -1;
	if (num[0] == '-')
		i++;
	int_part = 0;
	while (num[++i] != '.')
	{
		int_part *= 10;
		int_part += num[i] - '0';
	}
	out += int_part;
	if (num[0] == '-')
		out *= -1;
	return (out);
}

void	free_mat(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
