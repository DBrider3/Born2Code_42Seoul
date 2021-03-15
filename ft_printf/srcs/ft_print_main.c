/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:09:14 by dcho              #+#    #+#             */
/*   Updated: 2021/03/15 17:14:43 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int		ft_print_main(const char **format, va_list ap, t_options *options)
{
	if (options->type == 'd' || options->type == 'i' || options->type == 'o'
	|| options->type == 'u' || options->type == 'x' || options->type == 'X')
	{
		return (1);
	}
	else if (options->type == 'p')
		return (1);
	else if (options->type == 'c')
		return (1);
	else if (options->type == '%')
		return (1);
	else
		return (0);
}


