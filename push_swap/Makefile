# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 12:15:01 by srudman           #+#    #+#              #
#    Updated: 2023/11/23 14:37:17 by srudman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c main.c

LIBFT = libft/libft.a

FT_PRINTF = ft_printf/ft_printf.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)
	@make -C libft
	@make -C ft_printf
	ar -crs $(NAME) $(LIBFT) $(FT_PRINTF)
	
clean:
	rm -f $(OBJ)
	@make -C libft clean
	@make -C ft_printf clean
	
fclean: clean
	rm -f $(NAME)
	@make -C libft fclean
	@make -C ft_printf fclean

re: fclean all