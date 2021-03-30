/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:20:07 by dcho              #+#    #+#             */
/*   Updated: 2021/03/29 18:44:53 by dcho             ###   ########.fr       */
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
		if (options->precision > len && ft_check_type(options->type))
		{
			options->zero = options->precision - len;
		}
		else if (options->precision <= len)
		{
			if (options->width > len)
				options->space = options->width - len - sign;
		}
		if (options->width > options->precision)
			options->space = options->width - len - options->zero - sign;
	}
}

void	ft_get_padding_s(int len, t_options *options)
{
	if (options->precision < len && options->precision != -1)
		len = options->precision;
	if (options->width > len)
		options->space = options->width - len;
}

int		ft_check_type(char type)
{
	if (type == 'd' || type == 'i' || type == 'u' || type == 'x'
	|| type == 'X')
		return (1);
	return (0);
}
