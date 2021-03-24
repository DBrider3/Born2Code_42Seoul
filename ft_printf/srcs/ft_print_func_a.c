/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_func_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:02:07 by dcho              #+#    #+#             */
/*   Updated: 2021/03/24 17:03:20 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_int(int n, char *base)
{
	int		m;
	int		scale;
	int		base_size;
	int		digit;
	int		result;

	base_size = ft_strlen(base);
	scale = 1;
	m = n;
	result = 0;
	while (m >= 10)
	{
		m /= base_size;
		scale *= base_size;
	}
	while (scale > 0)
	{
		digit = n / scale;
		if (write(1, &base[digit], 1))
			result += 1;
		n %= scale;
		scale /= base_size;
	}
	return (result);
}

int		ft_print_uint(unsigned int n, char *base)
{
	unsigned int	m;
	int				scale;
	int				base_size;
	int				digit;
	int				result;

	base_size = ft_strlen(base);
	scale = 1;
	m = n;
	result = 0;
	while (m >= (unsigned int)base_size)
	{
		m /= base_size;
		scale *= base_size;
	}
	while (scale > 0)
	{
		digit = n / scale;
		if (write(1, &base[digit], 1))
			result += 1;
		n %= scale;
		scale /= base_size;
	}
	return (result);
}

int		ft_print_long(unsigned long long n, char *base)
{
	unsigned long long		m;
	unsigned long long		scale;
	int						base_size;
	int						digit;
	int						result;

	base_size = ft_strlen(base);
	scale = 1;
	m = n;
	result = 0;
	while (m >= (unsigned long long)base_size)
	{
		m /= base_size;
		scale *= base_size;
	}
	while (scale > 0)
	{
		digit = n / scale;
		if (write(1, &base[digit], 1))
			result += 1;
		n %= scale;
		scale /= base_size;
	}
	return (result);
}
