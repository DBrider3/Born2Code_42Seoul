/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_logic_numberic.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:20:19 by dcho              #+#    #+#             */
/*   Updated: 2021/03/24 14:27:50 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_logic_int(va_list ap, t_options *options)
{
	int		len;
	int		num;
	int		result;

	result = 0;
	if ((num = va_arg(ap, int)) < 0)
	{
		options->sign = 0;
		num = ft_abs(num);
	}
	len = ft_len_decimal(num);
	ft_get_padding(len, options);
	if (options->flag != '-')
		result += ft_print_space(options->space);
	result += ft_print_sign(options->sign);
	result += ft_print_zero(options->zero);
	result += ft_print_int(num, DEC);
	if (options->flag == '-')
		result += ft_print_space(options->space);
	return (result);
}

int		ft_print_logic_uint(va_list ap, t_options *options, int base)
{
	int				len;
	unsigned int	num;
	int				result;

	result = 0;
	num = va_arg(ap, unsigned int);
	len = ft_len_unsigend(num, base);
	ft_get_padding(len, options);
	if (options->flag != '-')
		result += ft_print_space(options->space);
	result += ft_print_sign(options->sign);
	result += ft_print_zero(options->zero);
	if (options->type == 'x')
		result += ft_print_uint(num, SHEX);
	else if (options->type == 'X')
		result += ft_print_uint(num, HEX);
	else
		result += ft_print_uint(num, DEC);
	if (options->flag == '-')
		result += ft_print_space(options->space);
	return (result);
}

int		ft_print_logic_long(va_list ap, t_options *options, int base)
{
	int						len;
	unsigned long long		num;
	int						result;

	result = 0;
	num = va_arg(ap, unsigned long long);
	len = ft_len_long(num, base);
	ft_get_padding(len, options);
	if (options->flag != '-')
		result += ft_print_space(options->space);
	result += ft_print_sign(options->sign);
	result += ft_print_zero(options->zero);
	result += ft_print_long(num, SHEX);
	if (options->flag == '-')
		result += ft_print_space(options->space);
	return (result);
}

int		ft_print_logic_char(va_list ap, t_options *options)
{
	int			len;
	long long	num;
	int			result;

	result = 0;
	if ((num = (long long)va_arg(ap, int)) < 0)
	{
		options->sign = 0;
		num = ft_abs(num);
	}
	len = ft_len_decimal(num);
	ft_get_padding(len, options);
	if (options->flag != '-')
		result += ft_print_space(options->space);
	result += ft_print_sign(options->sign);
	result += ft_print_zero(options->zero);
	result += ft_print_int(num, DEC);
	if (options->flag == '-')
		result += ft_print_space(options->space);
	return (result);
}
