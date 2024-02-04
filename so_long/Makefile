# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srudman <srudman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 13:15:01 by srudman           #+#    #+#              #
#    Updated: 2024/02/02 21:45:24 by srudman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
# or is it gcc?

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

INC	= -I ./inc -I ./libft -I ./mlx

SRC = src/main.c \

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean:
	rm -f $(OBJ)
	@make -C libft clean
	
fclean: clean
	rm -f $(NAME)
	@make -C libft fclean

re: fclean all