/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_logic_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:20:19 by dcho              #+#    #+#             */
/*   Updated: 2021/03/29 02:40:36 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int					ft_print_logic_number(va_list ap, t_options *options)
{
	int		len;
	t_ll	num;
	int		result;

	result = 0;
	num = ft_check_varg(ap, options);
	len = ft_len_number(num, options->type);
	if (options->type == 'p')
		len += 2;
	ft_get_padding(len, options);
	if (options->width > 0 && options->precision == 0 && num == 0)
		options->space++;
	if (options->flag != '-')
		result += ft_print_space(options->space);
	result += ft_print_sign(options->sign);
	result += ft_print_zero(options->zero);
	result += ft_print_number(num, *options);
	if (options->flag == '-')
		result += ft_print_space(options->space);
	return (result);
}

unsigned long long	ft_check_varg(va_list ap, t_options *options)
{
	t_ull	pnum;
	t_ll	num;

	pnum = 0;
	num = 0;
	if (options->type == 'p')
	{
		pnum = va_arg(ap, t_ull);
		return (pnum);
	}
	if (options->type == 'd' || options->type == 'i')
	{
		if ((num = (t_ll)va_arg(ap, int)) < 0)
		{
			options->sign = 0;
			num *= -1;
		}
	}
	else if (options->type == 'u' || options->type == 'x' || \
		options->type == 'X')
		num = va_arg(ap, unsigned int);
	return (num);
}
