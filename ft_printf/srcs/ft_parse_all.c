/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 07:32:29 by dcho              #+#    #+#             */
/*   Updated: 2021/03/30 17:56:10 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		parsing_flag(const char *format, t_options *options)
{
	int		i;
	int		hyphen_flag;
	int		zero_flag;

	i = 0;
	hyphen_flag = 0;
	zero_flag = 0;
	while (*(format + i) == '0' || *(format + i) == '-')
	{
		if (*(format + i) == '-')
			hyphen_flag = 1;
		else
			zero_flag = 1;
		i++;
	}
	if (hyphen_flag == 1)
		options->flag = '-';
	else if (zero_flag == 1)
		options->flag = '0';
	return (i);
}

static int		parsing_width(const char *format, va_list ap, int i,
						t_options *options)
{
	int		insert;

	if (*(format + i) == '*')
	{
		insert = va_arg(ap, int);
		if (insert < 0)
		{
			options->flag = '-';
			insert *= -1;
		}
		i++;
	}
	else
	{
		insert = 0;
		while (ft_isdigit(*(format + i)))
		{
			insert += (*(format + i) - '0');
			if (ft_isdigit(*(format + i + 1)))
				insert *= 10;
			i++;
		}
	}
	options->width = insert;
	return (i);
}

static int		parsing_prec(const char *format, va_list ap, int i,
						t_options *options)
{
	if (*(format + i) != '.')
		return (i);
	if (*(format + ++i) == '*')
		options->precision = va_arg(ap, int);
	else
	{
		options->precision = 0;
		if (!ft_isdigit(*(format + i)))
			return (i);
		while (ft_isdigit(*(format + i)))
		{
			options->precision += (*(format + i) - '0');
			if (!ft_isdigit(*(format + i + 1)))
				break ;
			options->precision *= 10;
			i++;
		}
	}
	return (++i);
}

static char		parsing_type(const char *format, int i)
{
	if (*(format + i) == 'd')
		return ('d');
	else if (*(format + i) == 'i')
		return ('i');
	else if (*(format + i) == 'u')
		return ('u');
	else if (*(format + i) == 'x')
		return ('x');
	else if (*(format + i) == 'X')
		return ('X');
	else if (*(format + i) == 'p')
		return ('p');
	else if (*(format + i) == 'c')
		return ('c');
	else if (*(format + i) == 's')
		return ('s');
	else if (*(format + i) == '%')
		return ('%');
	else
		return (0);
}

void			ft_parse_all(const char **format, va_list ap, \
				t_options *options)
{
	int		index;

	index = 0;
	index = parsing_flag(*format, options);
	index = parsing_width(*format, ap, index, options);
	index = parsing_prec(*format, ap, index, options);
	options->type = parsing_type(*format, index);
	if (options->precision < 0)
		options->precision = -1;
	else if (options->flag == '0' && options->type != '%')
		options->flag = 0;
	if (options->type == '%')
		options->precision = -1;
	else if (options->type == 'p')
		options->sign = 2;
	options->jmp += (index + 1);
}
