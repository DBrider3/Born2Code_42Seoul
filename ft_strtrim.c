/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:39:41 by dcho              #+#    #+#             */
/*   Updated: 2020/11/06 21:31:14 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	while (ft_strchr(set, *(s1 + i)))
		i++;
	start = i;
	i = ft_strlen(s1);
	while (ft_strchr(set, *(s1 + i)) && i > start)
		i--;
	end = i;
	if (start == end || *s1 == 0)
	{
		s = malloc(1);
		*s = 0;
	}
	else
		s = ft_substr(s1, start, end - start + 1);
	return (s);
}
