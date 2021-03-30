# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/24 16:21:32 by dcho              #+#    #+#              #
#    Updated: 2021/03/29 18:44:16 by dcho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR = ar
ARFLAGS = rcs
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = libftprintf.a

SRC_DIR = ./srcs
SRCS =	ft_printf.c \
		ft_printf_internal.c \
		ft_printf_utils.c \
		ft_print_main.c \
		ft_options_init.c \
		ft_parse_all.c \
		ft_print_logic_number.c \
		ft_print_logic_etc.c \
		ft_print_func_number.c \
		ft_print_func_etc.c \
		ft_len_number.c \
		ft_get_padding.c \

OBJ_DIR = ./objs
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(AR) $(ARFLAGS) $@ $^

%.o : $(SRC_DIR)/%.c
		$(CC) $(CFLAGS) -o $@ -c $<

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

