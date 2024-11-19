# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: ynoujoum <marvin@42.fr>                    #+#  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2024-11-17 23:04:48 by ynoujoum          #+#    #+#             #
#   Updated: 2024-11-17 23:04:48 by ynoujoum         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

CC = CC
CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

SRC = ft_printf.c ft_io.c ft_putptr.c
	
OBJ = $(SRC:.c=.o)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@
	ar -rc $(NAME) $@

all: $(NAME)

$(NAME): $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all