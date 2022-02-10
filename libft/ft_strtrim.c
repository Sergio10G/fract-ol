/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:52:26 by sdiez-ga          #+#    #+#             */
/*   Updated: 2021/09/27 18:02:06 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1);
	start = 0;
	while (ft_is_in_set(s1[start], set))
		start++;
	if (start == len)
		return (ft_strdup(""));
	end = len - 1;
	while (ft_is_in_set(s1[end], set))
		end--;
	return (ft_substr(s1 + start, 0, len - (start + (len - end - 1))));
}
