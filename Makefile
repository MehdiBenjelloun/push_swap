# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/25 17:01:40 by mbenjell          #+#    #+#              #
#    Updated: 2018/01/06 11:08:03 by mbenjell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_CK = checker

SRC = 	ft_libft.c \
		ft_libft_b.c \
		get_line.c \
		get_next_line.c \
		tools.c \
		free_it.c \
		error.c \
		action.c \
		parser.c \
		buffer.c \
		play.c \
		couper.c \
		instructions.c \
		sort.c \
		optimum.c \
		little_sort.c \
		algo.c \

SRC_PS = push_swap.c \

SRC_CK = checker.c \

FLAG = -Wall -Werror -Wextra

RM = /bin/rm -rf

HEAD = $(addsuffix .h, $(NAME))
OBJ = $(addsuffix .o, $(basename $(SRC)))
OBJ_PS = $(addsuffix .o, $(basename $(SRC_PS)))
OBJ_CK = $(addsuffix .o, $(basename $(SRC_CK)))

.PHONY: all clean fclean re

all: $(NAME) $(NAME_CK)

%.o : %.c
			@gcc -c $(FLAG) -o $@ $^

$(NAME): $(OBJ) $(OBJ_PS) $(HEAD)
			@gcc $(FLAG) $(SRC) $(SRC_PS) -o $(NAME)

$(NAME_CK): $(OBJ) $(OBJ_CK) $(HEAD)
			@gcc $(FLAG) $(SRC) $(SRC_CK) -o $(NAME_CK)

clean:
			@$(RM) $(OBJ) $(OBJ_PS) $(OBJ_CK)

fclean:		clean
			@$(RM) $(NAME) $(NAME_CK)

re:			fclean all
