/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:14:55 by dcho              #+#    #+#             */
/*   Updated: 2021/03/15 17:15:52 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# define ERORR -1
# define DEC "0123456789"
# define SHEX "0123456789abcdef"
# define HEX "0123456789ABCDEF"

typedef struct	s_options{
	char	flag;
	int		width;
	int		precision;
	char	type;
} t_options;

int			ft_printf(const char *format, ...);
int			ft_printf_internal(const char **format, va_list ap, t_options *options);
void		ft_option_init(t_options *options);
t_options	ft_parse_all(const char **format, va_list ap, t_options *options);
int			ft_isdigit(int c);
size_t		ft_decimal_len(int num);
size_t		ft_unsigend_len(unsigned int num, int base);

int			ft_print_main(const char **format, va_list ap, t_options *options);

#endif
