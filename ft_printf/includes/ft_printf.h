/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 21:14:55 by dcho              #+#    #+#             */
/*   Updated: 2021/03/29 02:45:54 by dcho             ###   ########.fr       */
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

typedef unsigned long long t_ull;
typedef long long t_ll;

typedef struct		s_options
{
	char	flag;
	int		width;
	int		precision;
	char	type;
	int		sign;
	int		space;
	int		zero;
	int		jmp;
}					t_options;

int					ft_printf(const char *format, ...);
int					ft_printf_scan(const char **format, va_list ap, \
					t_options *options);
int					ft_printf_main(const char **format, va_list ap, \
					t_options *options);
void				ft_option_init(t_options *options);
void				ft_parse_all(const char **format, va_list ap, \
					t_options *options);
int					ft_isdigit(int c);
size_t				ft_strlen(const char *s);
size_t				ft_len_number(t_ull num, char type);
void				ft_get_padding(int len, t_options *options);
int					ft_print_main(va_list ap, t_options *options);
int					ft_print_logic_number(va_list ap, t_options *options);
unsigned long long	ft_check_varg(va_list ap, t_options *options);
int					ft_print_logic_char(va_list ap, t_options *options);
int					ft_print_logic_string(va_list ap, t_options *options);
int					ft_print_space(int space);
int					ft_print_sign(int sign);
int					ft_print_zero(int zero);
int					ft_print_number(t_ull n, t_options options);
int					ft_print_string(char *str, t_options options, int len);
char				*ft_check_base(t_options options);
unsigned long long	ft_scale_finder(t_ull n, int base_size);
int					ft_check_type(char type);
void				ft_get_padding_s(int len, t_options *options);

#endif
