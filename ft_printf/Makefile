# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/24 16:21:32 by dcho              #+#    #+#              #
#    Updated: 2021/03/24 16:35:24 by dcho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR = ar
ARFLAGS = rcs

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC_DIR = ./srcs
SRCS = $(notdir $(wildcard $(SRC_DIR)/*.c))

OBJ_DIR = ./objs
OBJS = $(SRCS:.c=.o)
OBJECTS = $(patsubst %.o, $(OBJ_DIR)/%.o,$(OBJS))

all : $(NAME)

$(NAME) : $(OBJECTS)
		$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
		$(CC) $(CFLAGS) -o $@ -c $<

clean :
		rm -f $(OBJECTS)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re

