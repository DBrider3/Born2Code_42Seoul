/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:20:07 by dcho              #+#    #+#             */
/*   Updated: 2021/03/18 22:53:03 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_get_padding(int len, t_options *options)
{
	if (options->flag == '0')
		options->zero = options->width - len; // width - 숫자 길이 (width > 숫자 길이, 양수일때만)
	else
	{
		if (options->precision > len)
		{
			options->zero = options->precision - len;
			if (options->width > options->precision)
				options->space = options->width - options->precision;
		}
		else if (options->precision <= len)
		{
			if (options->width > len)
				options->space = options->width - len;
		}
	}
}
