/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:52:16 by sdiez-ga          #+#    #+#             */
/*   Updated: 2021/09/22 17:05:28 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	if (dst >= src)
	{
		while (i < len)
		{
			*((char *) dst + (len - 1) - i) = *((char *) src + (len - 1) - i);
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			*((char *) dst + i) = *((char *) src + i);
			i++;
		}
	}
	return (dst);
}
