# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 12:34:19 by aachhoub          #+#    #+#              #
#    Updated: 2022/10/22 12:34:21 by aachhoub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_putchar ft_putstr ft_putnbr ft_putnbr_u \
      ft_putnbr_base ft_print_memory ft_printf
OBJ = $(SRC:=.o)
NAME = libftprintf.a
LIBR = ar -rc
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

%.o:%.c
	@$(CC) $(CFLAGS) -c $<

all : $(NAME)

$(NAME): $(OBJ)
	@echo "\033[1;32mft_printf: Compiled all .c files successfully!\033[0m"
	@$(LIBR) $(NAME) $(OBJ)
	@echo "\033[1;32mft_printf: Archived all .o files into libftprintf.a successfully\033[0m"

clean:
	@$(RM) $(OBJ)
	@echo "\033[1;34mft_printf: Removed all .o files\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[1;34mft_printf: Removed libftprintf.a\033[0m"

re: fclean all
	@echo "\033[1;32mft_printf: Re-creating libftprintf.a\033[0m"
