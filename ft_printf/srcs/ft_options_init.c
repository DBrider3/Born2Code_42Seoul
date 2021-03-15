/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 05:35:15 by dcho              #+#    #+#             */
/*   Updated: 2021/03/14 04:22:05 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

void		ft_option_init(t_options *options)
{
	options->flag = 0;
	options->width = 1;
	options->precision = 1;
	options->type = 0;
}
