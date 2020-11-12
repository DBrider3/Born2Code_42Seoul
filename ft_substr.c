/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:29:17 by dcho              #+#    #+#             */
/*   Updated: 2020/11/06 20:15:33 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	slen;
	size_t	i;

	slen = ft_strlen(s);
	if (!(res = malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	if (slen >= start + len)
	{
		while (i < len)
		{
			*(res + i) = *(s + start + i);
			i++;
		}
		*(res + i) = 0;
	}
	return (res);
}
