# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 15:09:59 by aachhoub          #+#    #+#              #
#    Updated: 2022/11/15 16:18:48 by aachhoub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make
SRC = ./pipex.a ./libft/libft.a ./ft_printf/libftprintf.a
PSRC = $(addprefix src/, ft_printerr utils)
POBJ = ${PSRC:=.o}
PLIB = pipex.a
CD = cd
CC = cc
RM = rm -rf
AR = ar -rc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex

%.o:%.c
	@$(CC) ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: lib ${PLIB}
	${CC} ${CFLAGS} pipex.c ${SRC} -o ${NAME}
	@echo "\033[1;33mpipex: pipex program compiled successfully!\033[0m"

${PLIB}: ${POBJ}
	@${AR} ${PLIB} ${POBJ}

lib:
	@${MAKE} -C libft; ${MAKE} clean -C libft
	@${MAKE} -C ft_printf; ${MAKE} clean -C ft_printf

clean:
	@${RM} *.o

fclean: clean
	@${RM} ${NAME}
	@${RM} ${PLIB}
	@echo "\033[1;31mpipex: Deleted pipex program successfully!\033[0m"

re: fclean all
	@echo "\033[1;32mpipex: Re-creating pipex program!\033[0m"