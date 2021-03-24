/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_func_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:02:07 by dcho              #+#    #+#             */
/*   Updated: 2021/03/19 04:56:28 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_space(int space)
{
	int		i;

	i = 0;
	while (i < space)
		write(1, " ", 1);
	return (space);
}

int		ft_print_sign(int sign)
{
	if (sign == 0)
	{
		write(1, "-", 1);
		return (1);
	}
	else if (sign == 2)
	{
		write(1, "0x", 2);
		return (2);
	}
	return (0);
}

int		ft_print_zero(int zero)
{
	int		i;

	i = 0;
	while (i < zero)
	{
		write(1, "0", 1);
		i++;
	}
	return (zero);
}

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
	while (m >= base_size)
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
