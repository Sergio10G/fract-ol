/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <sdiez-ga@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:47:53 by sdiez-ga          #+#    #+#             */
/*   Updated: 2022/02/15 20:06:56 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	is_in_base(char c)
{
	char	*base;
	int		i;

	base = "0123456789ABCDEF";
	i = 0;
	while (i < 16)
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	pos_in_base(char c)
{
	char	*base;
	int		i;

	base = "0123456789ABCDEF";
	i = 0;
	while (i < 16)
	{
		if (base[i] == c)
			break ;
		i++;
	}
	return (i);
}

int	is_valid_hex(char *hex)
{
	int	i;

	if (ft_strncmp(colors[i], "0x", 2) != 0 || ft_strlen(colors[i]) != 10)
		return (0);
	i = 2;
	while (i < 10)
	{
		if (!is_in_base(hex[i]))
			return (0);
		i++;
	}
	return (1);
}

unsigned int	hextoui(char *hex)
{
	unsigned int	out;
	int				i;

	out = 0;
	i = 2;
	while (i < 10)
	{
		out += pos_in_base(hex[i]);
		out *= 16;
		//out << 4;
		i--;
	}
	return (out);
}
