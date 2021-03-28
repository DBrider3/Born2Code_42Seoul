/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_func_number.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:02:07 by dcho              #+#    #+#             */
/*   Updated: 2021/03/29 02:41:37 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int						ft_print_number(t_ull n, t_options options)
{
	t_ull	scale;
	int		base_size;
	int		digit;
	int		result;
	char	*base;

	base = ft_check_base(options);
	if (n == 0 && options.precision == 0)
		return (0);
	base_size = ft_strlen(base);
	result = 0;
	scale = ft_scale_finder(n, base_size);
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

char					*ft_check_base(t_options options)
{
	char	*base;

	if (options.type == 'd' || options.type == 'i' || options.type == 'u')
		base = DEC;
	else if (options.type == 'x' || options.type == 'p')
		base = SHEX;
	else
		base = HEX;
	return (base);
}

unsigned long long		ft_scale_finder(t_ull n, int base_size)
{
	t_ull		scale;

	scale = 1;
	while (n >= (t_ull)base_size)
	{
		n /= base_size;
		scale *= base_size;
	}
	return (scale);
}
