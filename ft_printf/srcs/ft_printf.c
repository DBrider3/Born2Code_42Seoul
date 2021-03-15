/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 05:11:29 by dcho              #+#    #+#             */
/*   Updated: 2021/03/14 03:46:43 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_options	options;
	int			count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_printf_internal(&format, ap, &options);
		}
		write(1, format, 1);
		count++;
		format++;
	}
	printf("\n[%c] [%d] [%d] [%c]\n", options.flag, options.width, options.precision, options.type);
	va_end(ap);
	return (count);
}

int		main(void)
{
	int		i;

	// i = ft_printf("%0*.*d",1,2, 7);
	i = ft_printf("%0*.*d",-1,100, 7);
	printf("%d\n",i);
}
