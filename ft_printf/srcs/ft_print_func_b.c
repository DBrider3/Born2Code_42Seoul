/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_func_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:37:24 by dcho              #+#    #+#             */
/*   Updated: 2021/03/24 15:37:40 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_space(int space)
{
	int		i;

	i = 0;
	while (i < space)
		write(1, " ", 1);
	return (space);
}

int		ft_print_sign(int sign)
{
	if (sign == 0)
	{
		write(1, "-", 1);
		return (1);
	}
	else if (sign == 2)
	{
		write(1, "0x", 2);
		return (2);
	}
	return (0);
}

int		ft_print_zero(int zero)
{
	int		i;

	i = 0;
	while (i < zero)
	{
		write(1, "0", 1);
		i++;
	}
	return (zero);
}
