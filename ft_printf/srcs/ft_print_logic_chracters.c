/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_logic_chracters.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:56:02 by dcho              #+#    #+#             */
/*   Updated: 2021/03/24 17:04:11 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_logic_char(va_list ap, t_options *options)
{
	char	ch;
	int		result;

	result = 0;
	ch = va_arg(ap, int);
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
	str = va_arg(ap, char*);
	len = ft_strlen(str);
	ft_get_padding(len, options);
	if (options->flag != '-')
		result += ft_print_space(options->space);
	result += (write(1, str, len));
	if (options->flag == '-')
		result += ft_print_space(options->space);
	return (result);
}

int		ft_print_logic_percent(t_options *options)
{
	int		result;

	result = 0;
	if (options->flag != '-')
		result += ft_print_space(options->space);
	result += ft_print_zero(options->zero);
	result += (write(1, "%", 1));
	if (options->flag == '-')
		result += ft_print_space(options->space);
	return (result);
}
