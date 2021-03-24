CC = gcc

CFAGS = -Wall -Wextra -Werror

SRC_DIR = ./srcs

OBJ_DIR = ./objs

TARGET = main

# Make 할 소스 파일들
# wildcard로 SRC_DIR에서 *.c로 된 파일들 목록을 뽑아낸 뒤에
# notdir로 파일 이름만 뽑아낸다.
# (e.g SRCS는 foo.c bar.c main.c 가 된다.)
# SRCS = $(notdir $(wildcard $(SRC_DIR)/*.c))
SRCS =	ft_printf.c	\
		ft_printf_internal.c	\
		ft_option_init.c		\
		ft_parse_all.c			\
		ft_printf_utils.c		\

OBJS = $(SRCS:.c=.o)

