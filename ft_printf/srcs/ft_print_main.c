/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:09:14 by dcho              #+#    #+#             */
/*   Updated: 2021/03/29 01:51:03 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_main(va_list ap, t_options *options)
{
	if (options->type == 'c' || options->type == '%')
		return (ft_print_logic_char(ap, options));
	else if (options->type == 's')
		return (ft_print_logic_string(ap, options));
	else
		return (ft_print_logic_number(ap, options));
}
