/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:23:54 by sdiez-ga          #+#    #+#             */
/*   Updated: 2021/09/27 18:00:55 by sdiez-ga         ###   ########.fr       */
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
	return (12 - (i + 1));
}

static void	ft_write_to_file(char *temp, int fd)
{
	int	i;

	i = 0;
	while (!temp[i])
		i++;
	while (temp[i])
	{
		ft_putchar_fd(temp[i], fd);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;
	int				sign;
	char			temp[12];

	if (fd == -1)
		return ;
	sign = 1;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	else if (n < 0)
	{
		un = n * -1;
		sign *= -1;
	}
	else
		un = n;
	ft_fill_temp(temp, un, sign);
	ft_write_to_file(temp, fd);
}
