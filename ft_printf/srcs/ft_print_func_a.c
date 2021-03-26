/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_func_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:02:07 by dcho              #+#    #+#             */
/*   Updated: 2021/03/26 17:50:09 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_int(LL n, char *base, int prec)
{
	LL		scale;
	int		base_size;
	int		digit;
	int		result;

	if (n == 0 && prec == 0)
		return (0);
	base_size = ft_strlen(base);
	result = 0;
	scale = ft_scale_finder_ll(n, base_size);
	while (scale > 0)
	{
		digit = n / scale;
		if (write(1, &base[digit], 1) == 1)
			result++;
		n %= scale;
		scale /= base_size;
	}
	return (result);
}

int		ft_print_uint(unsigned int n, char *base, int prec)
{
	int				scale;
	int				base_size;
	int				digit;
	int				result;

	if (n == 0 && prec == 0)
		return (0);
	base_size = ft_strlen(base);
	scale = 1;
	result = 0;
	scale = (unsigned int)ft_scale_finder_ull(n, base_size);
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

int		ft_print_long(ULL n, char *base, int prec)
{
	ULL			scale;
	int			base_size;
	int			digit;
	int			result;

	if (n == 0 && prec == 0)
		return (0);
	base_size = ft_strlen(base);
	scale = 1;
	result = 0;
	scale = ft_scale_finder_ull(n, base_size);
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

long long		ft_scale_finder_ll(LL n, int base_size)
{
	int		scale;

	scale = 1;
	while (n >= (LL)base_size)
	{
		n /= base_size;
		scale *= base_size;
	}
	return (scale);
}

unsigned long long	ft_scale_finder_ull(ULL n, int base_size)
{
	ULL		scale;

	scale = 1;
	while (n >= (ULL)base_size)
	{
		n /= base_size;
		scale *= base_size;
	}
	return (scale);
}


