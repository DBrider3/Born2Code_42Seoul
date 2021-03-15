/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 07:32:29 by dcho              #+#    #+#             */
/*   Updated: 2021/03/14 03:46:28 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int	parsing_flag(const char *format, t_options *options)
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

static int	parsing_width(const char *format, va_list ap, int i,
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

static int	parsing_prec(const char *format, va_list ap, int i,
						t_options *options)
{
	int		insert;

	if (*(format + i) != '.')
		return (i);
	if (options->flag == '0')
		options->flag = 0;
	if (*(format + ++i) == '*')
	{
		insert = va_arg(ap, int);
		if (insert < 0)
			insert = 1;
	}
	else
	{
		insert = 0;
		while (ft_isdigit(*(format + ++i)))
		{
			insert += (*(format + i - 1) - '0');
			if (ft_isdigit(*(format + i)))
				insert *= 10;
		}
	}
	options->precision = insert;
	return (++i);
}

static char	parsing_type(const char *format, int i)
{
	if (*(format + i) == 'd')
		return ('d');
	else if (*(format + i) == 'i')
		return ('i');
	else if (*(format + i) == 'u')
		return ('u');
	else if (*(format + i) == 'x')
		return ('u');
	else if (*(format + i) == 'X')
		return ('u');
	else if (*(format + i) == 'c')
		return ('u');
	else if (*(format + i) == 's')
		return ('u');
	else if (*(format + i) == '%')
		return ('%');
	else
		return (0);
}

t_options	ft_parse_all(const char **format, va_list ap, t_options *options)
{
	int		index;

	index = 0;
	index = parsing_flag(*format, options);
	index = parsing_width(*format, ap, index, options);
	index = parsing_prec(*format, ap, index, options);
	options->type = parsing_type(*format, index);

	return (*options);
}
