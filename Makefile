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

SRC = $(addprefix src/, pipex.c utils.c)
BSRC =  $(addprefix src/, pipex_bonus.c utils.c utils_bonus.c)
LIBFT = ./libft/libft.a
NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
MAKE = make

all: ${NAME}

${NAME}: ${LIBFT}
	@${CC} ${CFLAGS} ${SRC} ${LIBFT} -o ${NAME}
	@echo "\033[1;33mpipex: pipex program compiled successfully!\033[0m"

${LIBFT}:
	@${MAKE} -C ./libft; ${MAKE} clean -C ./libft

bonus: fclean
	@${MAKE} -C ./libft; ${MAKE} clean -C ./libft
	@${CC} ${CFLAGS} ${BSRC} ${LIBFT} -o ${NAME}
	@echo "\033[1;33mpipex: pipex bonus program compiled successfully!\033[0m"

clean:
	@${RM} */*.o
	@${RM} *.o
	@${MAKE} clean -C libft
	@echo "\033[1;31mpipex: Removed all .o files!\033[0m"

fclean: clean
	@${RM} ${NAME}
	@${MAKE} fclean -C libft 
	@echo "\033[1;31mpipex: Removed pipex program!\033[0m"

re: fclean all
	@echo "\033[1;32mpipex: Re-creating pipex program!\033[0m"