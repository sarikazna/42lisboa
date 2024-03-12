# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srudman <srudman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 14:51:52 by srudman           #+#    #+#              #
#    Updated: 2024/03/11 22:31:11 by srudman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
INCLUDES = -I/usr/include -Imlx -I./inc

SRC_DIR = src
SRC_DIR_BONUS = src_bonus
OBJ_DIR = obj
OBJ_DIR_BONUS = obj_bonus
LIBFT_DIR = ./libft
MLX_DIR = ./mlx

SRCS = $(wildcard $(SRC_DIR)/*.c)
SRCS_BONUS = $(wildcard $(SRC_DIR_BONUS)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS = $(SRCS_BONUS:$(SRC_DIR_BONUS)/%.c=$(OBJ_DIR_BONUS)/%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@make --directory=$(LIBFT_DIR)
	@make --directory=$(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@make --directory=$(LIBFT_DIR)
	@make --directory=$(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) $(MLX_FLAGS) -o $(NAME_BONUS)

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c | $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR_BONUS):
	mkdir -p $(OBJ_DIR_BONUS)

clean:
	@make clean --directory=$(LIBFT_DIR)
	@make clean --directory=$(MLX_DIR)
	$(RM) -r $(OBJ_DIR) $(OBJ_DIR_BONUS)

fclean: clean
	@make fclean --directory=$(LIBFT_DIR)
	@make fclean --directory=$(MLX_DIR)
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all
