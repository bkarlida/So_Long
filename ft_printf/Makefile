# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/19 14:50:44 by bkarlida          #+#    #+#              #
#    Updated: 2022/11/19 14:54:04 by bkarlida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

SRCS= ft_printf.c\
	ft_unsigned.c ft_add.c ft_pointer.c\
	ft_lowerx.c ft_upperx.c

OBJS= $(SRCS:.c=.o)	

CC=gcc

RM= rm -rf

CFLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean: clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re