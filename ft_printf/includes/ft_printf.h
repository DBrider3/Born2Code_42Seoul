/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:14:55 by dcho              #+#    #+#             */
/*   Updated: 2021/03/25 22:03:49 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# define LL long long
# define ULL unsigned long long
# define ERORR -1
# define DEC "0123456789"
# define SHEX "0123456789abcdef"
# define HEX "0123456789ABCDEF"

typedef struct	s_options{
	char	flag;
	int		width;
	int		precision;
	char	type;
	int		sign;
	int		space;
	int		zero;
	int		jmp;
} t_options;

int			ft_printf(const char *format, ...);
int			ft_printf_internal(const char **format, va_list ap, t_options *options);
void		ft_option_init(t_options *options);
void		ft_parse_all(const char **format, va_list ap, t_options *options);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *s);

size_t		ft_len_decimal(LL num);
size_t		ft_len_unsigend(unsigned int num, int base);
size_t		ft_len_long(long long num, int base);
void		ft_get_padding(int len, t_options *options);

int			ft_print_main(va_list ap, t_options *options);
int			ft_print_logic_int(va_list ap, t_options *options);
int			ft_print_logic_uint(va_list ap, t_options *options, int base);
int			ft_print_logic_long(va_list ap, t_options *options);
int			ft_print_logic_char(va_list ap, t_options *options);
int			ft_print_logic_string(va_list ap, t_options *options);
int			ft_print_logic_percent(t_options *options);

int			ft_print_space(int space);
int			ft_print_sign(int sign);
int			ft_print_zero(int zero);
int			ft_print_int(LL n, char *base, int prec);
int			ft_print_uint(unsigned int n, char *base, int prec);
int			ft_print_long(unsigned long long n, char *base);

long long	ft_scale_finder_ll(LL n, int base_size);
unsigned long long		ft_scale_finder_ull(ULL n, int base_size);

#endif
