/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 05:17:44 by dcho              #+#    #+#             */
/*   Updated: 2021/03/26 16:35:44 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf_internal(const char **format, va_list ap, t_options *options)
{
	int		count;

	count = 0;
	ft_option_init(options);
	ft_parse_all(format, ap, options);
	if (!(options->type))
		return (ERORR);
	count += ft_print_main(ap, options);
	return (count);
}
