/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:54:40 by dcho              #+#    #+#             */
/*   Updated: 2021/03/25 20:36:10 by dcho             ###   ########.fr       */
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

void			ft_putnbr(int n)
{
	char		s[12];
	char		*ps;
	int			numlen;
	int			sign;

	sign = 1;
	ps = s + 11;
	*ps = 0;
	if (n < 0)
		sign = -1;
	while (n)
	{
		*--ps = (n % 10) * sign + '0';
		n /= 10;
	}
	if (n == 0)
		*--ps = '0';
	numlen = ft_strlen(ps);
	write(1, ps, numlen);
}
