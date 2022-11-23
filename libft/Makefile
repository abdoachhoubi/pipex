# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aachhoub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 08:25:43 by aachhoub          #+#    #+#              #
#    Updated: 2022/10/21 15:36:37 by aachhoub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_strchr ft_strlen ft_putchar_fd \
      ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
      ft_strlcpy ft_strlcat ft_strdup ft_memset \
      ft_bzero ft_memcmp ft_memcpy ft_memmove \
      ft_isascii ft_isdigit ft_isalpha ft_isalnum \
      ft_isprint ft_toupper ft_tolower ft_atoi \
      ft_calloc ft_strjoin ft_strnstr ft_memchr \
      ft_strncmp ft_substr ft_itoa ft_split \
      ft_strtrim ft_strrchr ft_strmapi ft_striteri
BSRC =  ft_lstnew_bonus ft_lstsize_bonus ft_lstlast_bonus \
		ft_lstadd_back_bonus ft_lstadd_front_bonus \
		ft_lstdelone_bonus ft_lstclear_bonus ft_lstiter_bonus \
		ft_lstmap_bonus
OBJ = $(SRC:=.o)
BOBJ = $(BSRC:=.o)
NAME = libft.a
AR = ar -rc
RM = rm -f
CC = cc
FLAGS = -Wall -Wextra -Werror

%.o : %.c
	@$(CC) $(FLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[1;32mlibft: Compiled all .c files successfully!\033[0m"
	@$(AR) $(NAME) $(OBJ)
	@echo "\033[1;32mlibft: Archived all .o files into libft.a successfully\033[0m"


bonus: $(NAME) $(BOBJ)
	@$(AR) $(NAME) $(BOBJ)
	@echo "\033[1;32mlibft: Archived _bonus.o files into libft.a successfully\033[0m"

clean:
	@$(RM) $(OBJ) $(BOBJ)
	@echo "\033[1;31mlibft: Removed all .o files\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[1;31mlibft: Removed libft.a\033[0m"

re: fclean all
	@echo "\033[1;32mlibft: Re-creating libft.a\033[0m"
