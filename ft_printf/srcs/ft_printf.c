/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 05:11:29 by dcho              #+#    #+#             */
/*   Updated: 2021/03/29 02:57:11 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_options	options;
	int			result;

	va_start(ap, format);
	result = ft_printf_scan(&format, ap, &options);
	if (result == ERORR)
		return (ERORR);
	va_end(ap);
	return (result);
}
