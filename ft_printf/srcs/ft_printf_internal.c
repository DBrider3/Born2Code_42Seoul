/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 05:17:44 by dcho              #+#    #+#             */
/*   Updated: 2021/03/30 17:05:09 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_printf_main(const char **format, va_list ap, \
				t_options *options)
{
	int		count;

	count = 0;
	ft_option_init(options);
	ft_parse_all(format, ap, options);
	if (!(options->type))
		return (ERORR);
	count += ft_print_main(ap, options);
	*format += options->jmp;
	return (count);
}

int				ft_printf_scan(const char **format, va_list ap, \
				t_options *options)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (*(*format + i))
	{
		if (*(*format + i) == '%')
		{
			write(1, *format, i);
			*format += (++i);
			count += ft_printf_main(format, ap, options);
			if (!(options->type))
				return (ERORR);
			i = 0;
			continue;
		}
		count++;
		i++;
	}
	write(1, *format, i);
	return (count);
}
