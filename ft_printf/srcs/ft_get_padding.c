/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:20:07 by dcho              #+#    #+#             */
/*   Updated: 2021/03/25 21:16:56 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_get_padding(int len, t_options *options)
{
	int		sign;

	sign = 0;
	if (options->sign == 0)
		sign = 1;
	if (options->flag == '0')
		options->zero = options->width - len - sign;
	else
	{
		if (options->width >= len)
			options->space = options->width - len - sign;
		if (options->precision > len)
		{
			if (options->type == 'd' || options->type == 'i' ||
			options->type == 'u' || options->type == 'x'
			|| options->type == 'X')
				options->zero = options->precision - len - sign;
			if (options->width > options->precision)
				options->space = options->width - options->precision - len - sign;
		}
		else if (options->precision <= len)
		{
			if (options->width > len)
				options->space = options->width - len - sign;
		}
	}
}
