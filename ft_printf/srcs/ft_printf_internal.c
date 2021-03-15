/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_internal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 05:17:44 by dcho              #+#    #+#             */
/*   Updated: 2021/03/15 17:09:07 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int		ft_printf_internal(const char **format, va_list ap, t_options *options)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	ft_option_init(options);
	*options = ft_parse_all(format, ap, options);

	return (count);
}
