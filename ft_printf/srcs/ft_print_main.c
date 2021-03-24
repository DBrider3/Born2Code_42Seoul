/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:09:14 by dcho              #+#    #+#             */
/*   Updated: 2021/03/24 17:06:14 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_main(va_list ap, t_options *options)
{
	if (options->type == 'd' || options->type == 'i')
		return (ft_print_logic_int(ap, options));
	else if (options->type == 'u')
		return (ft_print_logic_uint(ap, options, 10));
	else if (options->type == 'x' || options->type == 'X')
		return (ft_print_logic_uint(ap, options, 16));
	else if (options->type == 'p')
		return (ft_print_logic_long(ap, options));
	else if (options->type == 'c')
		return (ft_print_logic_char(ap, options));
	else if (options->type == 's')
		return (ft_print_logic_string(ap, options));
	else if (options->type == '%')
		return (ft_print_logic_percent(options));
	else
		return (0);
}


