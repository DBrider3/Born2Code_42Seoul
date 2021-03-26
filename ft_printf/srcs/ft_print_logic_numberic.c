/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_logic_numberic.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:20:19 by dcho              #+#    #+#             */
/*   Updated: 2021/03/26 17:13:59 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_logic_int(va_list ap, t_options *options)
{
	int		len;
	LL		num;
	int		result;

	result = 0;
	if ((num = (LL)va_arg(ap, int)) < 0)
	{
		options->sign = 0;
		num *= -1;
	}
	len = ft_len_decimal(num);
	ft_get_padding(len, options);
	if (options->width > 0 && options->precision == 0 && num == 0)
		options->space++;
	if (options->flag != '-')
		result += ft_print_space(options->space);
	result += ft_print_sign(options->sign);
	result += ft_print_zero(options->zero);
	result += ft_print_int(num, DEC, options->precision);
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
	if (options->width > 0 && options->precision == 0 && num == 0)
		options->space++;
	if (options->flag != '-')
		result += ft_print_space(options->space);
	result += ft_print_zero(options->zero);
	if (options->type == 'x')
		result += ft_print_uint(num, SHEX, options->precision);
	else if (options->type == 'X')
		result += ft_print_uint(num, HEX, options->precision);
	else
		result += ft_print_uint(num, DEC, options->precision);
	if (options->flag == '-')
		result += ft_print_space(options->space);
	return (result);
}

int		ft_print_logic_long(va_list ap, t_options *options)
{
	ULL		num;
	int		result;
	int		len;

	result = 0;
	num = va_arg(ap, ULL);
	len = ft_len_long(num, 16) + 2;
	ft_get_padding(len, options);
	if (options->width > 0 && options->precision == 0 && num == 0)
		options->space++;
	if (options->flag != '-')
		result += ft_print_space(options->space);
	result += ft_print_sign(options->sign);
	result += ft_print_long(num, SHEX, options->precision);
	if (options->flag == '-')
		result += ft_print_space(options->space);
	return (result);
}
