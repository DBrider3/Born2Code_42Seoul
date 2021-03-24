/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 05:11:29 by dcho              #+#    #+#             */
/*   Updated: 2021/03/24 14:12:20 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_options	options;
	int			count;
	int			i;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (*(format + i))
	{
		if (*(format + i) == '%')
		{
			write(1, format, i);
			format += i++;
			count += ft_printf_internal(&format, ap, &options);
			format += options.jmp;
			i = 0;
			continue;
		}
		count++;
		i++;
	}
	write(1, format, i);
	va_end(ap);
	return (count);
}
