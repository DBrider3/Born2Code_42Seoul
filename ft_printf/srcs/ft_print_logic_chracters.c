/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_logic_chracters.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:56:02 by dcho              #+#    #+#             */
/*   Updated: 2021/03/26 16:19:26 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_logic_char(va_list ap, t_options *options)
{
	char	ch;
	int		result;

	result = 0;
	ch = va_arg(ap, int);
	ft_get_padding(1, options);
	if (options->flag != '-')
		result += ft_print_space(options->space);
	result += (write(1, &ch, 1));
	if (options->flag == '-')
		result += ft_print_space(options->space);
	return (result);
}

int		ft_print_logic_string(va_list ap, t_options *options)
{
	int		len;
	char	*str;
	int		result;

	result = 0;
	if (!(str = va_arg(ap, char*)))
		str = "(null)";
	len = ft_strlen(str);
	if (options->precision == 0)
		len = 0;
	ft_get_padding_s(len, options);
	if (options->flag != '-')
		result += ft_print_space(options->space);
	if (options->precision == 0)
		result += 0;
	else
	{
		if (options->precision < len && options->precision != -1)
		{
			int i = 0;
			while (i < options->precision)
				write(1, str + i++, 1);
			result += i;
		}
		else
			result += (write(1, str, len));
	}
	if (options->flag == '-')
		result += ft_print_space(options->space);
	return (result);
}

int		ft_print_logic_percent(t_options *options)
{
	int		result;

	result = 0;
	ft_get_padding(1, options);
	if (options->flag != '-')
		result += ft_print_space(options->space);
	result += ft_print_zero(options->zero);
	result += (write(1, "%", 1));
	if (options->flag == '-')
		result += ft_print_space(options->space);
	return (result);
}
