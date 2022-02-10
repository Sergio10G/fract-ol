/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:11:35 by sdiez-ga          #+#    #+#             */
/*   Updated: 2021/09/27 17:57:43 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_fill_temp(char *temp, unsigned int un, int sign)
{
	size_t	i;

	i = 10;
	ft_bzero(temp, 12);
	while (un != 0 && i > 0)
	{
		temp[i] = un % 10 + '0';
		un /= 10;
		i--;
	}
	if (sign < 0)
	{
		temp[i] = '-';
		i--;
	}
	return (12 - (i + 2));
}

static char	*ft_fill_final_num(char *temp, size_t num_size)
{
	size_t	i;
	size_t	offset;
	char	*num;

	num = malloc(num_size + 1);
	if (!num)
		return (0);
	i = 0;
	offset = 0;
	while (!temp[offset])
		offset++;
	while (i < num_size)
	{
		num[i] = temp[offset + i];
		i++;
	}
	num[i] = '\0';
	return (num);
}

char	*ft_itoa(int n)
{
	unsigned int	un;
	int				sign;
	char			temp[12];
	size_t			num_size;

	sign = 1;
	if (n < 0)
	{
		un = n * -1;
		sign = -1;
	}
	else
		un = n;
	if (un != 0)
		num_size = ft_fill_temp(temp, un, sign);
	else
	{
		temp[0] = '0';
		num_size = 1;
	}
	return (ft_fill_final_num(temp, num_size));
}
