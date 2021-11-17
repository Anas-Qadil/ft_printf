# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/14 19:21:20 by aqadil            #+#    #+#              #
#    Updated: 2021/11/17 16:31:57 by aqadil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= cc
SRCS		= ft_printf.c \
			  print_hex_p.c \
			  print_unsigned_int.c \
			  print_x_and_X.c	\
			  printf_char_str.c

FLAGS	= -Wall -Wextra -Werror

OBJS	=	ft_printf.o \
			print_hex_p.o \
			print_unsigned_int.o \
			print_x_and_X.o	\
			printf_char_str.o


HEADER = ft_printf.h

$(NAME): $(Name) $(OBJS) $(HEADER)
	ar rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(FLAGS) -o $@ -c $<

all: $(NAME)

clean:
	rm -f $(OBJS) $(BNS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all