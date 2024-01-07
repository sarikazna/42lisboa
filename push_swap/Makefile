# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 12:15:01 by srudman           #+#    #+#              #
#    Updated: 2023/11/26 18:40:50 by srudman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c main.c error_handling.c linked_stacks_utils.c movements_push.c \
	movements_reverse_rotate.c movements_rotate.c movements_swap.c math_operations.c \
	stack_init.c

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)
	@make -C libft
	ar -crs $(NAME) $(LIBFT)
	
clean:
	rm -f $(OBJ)
	@make -C libft clean
	
fclean: clean
	rm -f $(NAME)
	@make -C libft fclean

re: fclean all