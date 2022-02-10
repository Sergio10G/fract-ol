/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:35:53 by sdiez-ga          #+#    #+#             */
/*   Updated: 2021/09/27 18:01:24 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*mod_str;
	size_t	i;
	size_t	s_size;

	if (!f || !s)
		return (0);
	s_size = ft_strlen(s);
	mod_str = malloc(s_size + 1);
	if (!mod_str)
		return (0);
	ft_memcpy(mod_str, s, s_size);
	mod_str[s_size] = '\0';
	i = 0;
	while (mod_str[i])
	{
		mod_str[i] = (f)(i, s[i]);
		i++;
	}
	return (mod_str);
}
