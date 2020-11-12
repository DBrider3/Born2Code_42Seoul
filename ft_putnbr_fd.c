/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 22:05:09 by dcho              #+#    #+#             */
/*   Updated: 2020/11/11 20:24:52 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned	ft_abs(int n)
{
	return (n > 0 ? n : -n);
}

void			ft_putnbr_fd(int n, int fd)
{
	char		s[20];
	char		*ps;
	unsigned	un;

	ps = s + 19;
	*ps = 0;
	un = ft_abs(n);
	while (un)
	{
		*--ps = un % 10 + '0';
		un /= 10;
	}
	if (n < 0)
		*--ps = '-';
	else if (n == 0)
		*--ps = '0';
	ft_putstr_fd(ps, fd);
}
