/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:54:40 by dcho              #+#    #+#             */
/*   Updated: 2021/03/19 04:19:51 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (*(s1 + i))
	{
		*(res + i) = *(s1 + i);
		i++;
	}
	*(res + i) = 0;
	return (res);
}

unsigned	ft_abs(int n)
{
	return (n > 0 ? n : -n);
}

void			ft_putnbr(int n)
{
	char		s[12];
	char		*ps;
	unsigned	un;
	int			numlen;

	ps = s + 11;
	*ps = 0;
	un = ft_abs(n);
	while (un)
	{
		*--ps = un % 10 + '0';
		un /= 10;
	}
	if (n == 0)
		*--ps = '0';
	numlen = ft_strlen(ps);
	write(1, ps, numlen);
}
