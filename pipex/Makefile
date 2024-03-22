# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srudman <srudman@student.42lisboa.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 14:51:52 by srudman           #+#    #+#              #
#    Updated: 2024/03/22 17:07:16 by srudman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pixex_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src
SRC_DIR_BONUS = src_bonus
OBJ_DIR = obj
OBJ_DIR_BONUS = obj_bonus
LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf

SRCS = 		src/main.c
SRCS_BONUS = 
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:$(SRC_DIR_BONUS)/%.c=$(OBJ_DIR_BONUS)/%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@make --directory=$(LIBFT_DIR)
	@make --directory=$(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR) $(PRINTF_DIR) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@make --directory=$(LIBFT_DIR)
	@make --directory=$(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT_DIR) $(PRINTF_DIR) -o $(NAME_BONUS)

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c | $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR_BONUS):
	mkdir -p $(OBJ_DIR_BONUS)

clean:
	@make clean --directory=$(LIBFT_DIR)
	$(RM) -r $(OBJ_DIR) $(OBJ_DIR_BONUS)

fclean: clean
	@make fclean --directory=$(LIBFT_DIR)
	@make fclean --directory=$(PRINTF_DIR)
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all bonus