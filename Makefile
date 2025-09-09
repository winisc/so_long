# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wini <wini@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 19:14:29 by wini              #+#    #+#              #
#    Updated: 2025/09/09 02:04:04 by wini             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src
SRC_DIR_BONUS = src_bonus
MLX_DIR = mlx
LIBFT_DIR = libs/libft

INCLUDES = -Iincludes -Imlx -I$(LIBFT_DIR)
INCLUDES_BONUS = -Iincludes_bonus -Imlx -I$(LIBFT_DIR)

SRC = $(SRC_DIR)/main.c \
	$(SRC_DIR)/ft_check_map.c \
	$(SRC_DIR)/ft_load_map.c \
	$(SRC_DIR)/ft_so_long_utils.c \
	$(SRC_DIR)/ft_check_path_map.c \
	$(SRC_DIR)/ft_map_erros.c \
	$(SRC_DIR)/ft_load_game.c \
	$(SRC_DIR)/ft_state_game.c \
	$(SRC_DIR)/ft_player_controll.c

SRC_BONUS = $(SRC_DIR_BONUS)/main_bonus.c \
	$(SRC_DIR_BONUS)/ft_check_map_bonus.c \
	$(SRC_DIR_BONUS)/ft_load_map_bonus.c \
	$(SRC_DIR_BONUS)/ft_so_long_utils_bonus.c \
	$(SRC_DIR_BONUS)/ft_check_path_map_bonus.c \
	$(SRC_DIR_BONUS)/ft_map_erros_bonus.c \
	$(SRC_DIR_BONUS)/ft_load_game_bonus.c \
	$(SRC_DIR_BONUS)/ft_state_game_bonus.c \
	$(SRC_DIR_BONUS)/ft_player_controll_bonus.c \
	$(SRC_DIR_BONUS)/ft_animation_controll_bonus.c \
	$(SRC_DIR_BONUS)/ft_collectible_controll_bonus.c \
	$(SRC_DIR_BONUS)/ft_enemy_controll_bonus.c \
	$(SRC_DIR_BONUS)/ft_init_entitys_bonus.c \
	$(SRC_DIR_BONUS)/ft_load_assets_bonus.c \
	$(SRC_DIR_BONUS)/ft_close_game_bonus.c \

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

MLX_LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT_A = $(LIBFT_DIR)/libft.a

all: mlx libft $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -L$(LIBFT_DIR) -lft $(MLX_LIBS) -o $(NAME)

bonus: mlx libft $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(INCLUDES_BONUS) -L$(LIBFT_DIR) -lft $(MLX_LIBS) -o $(NAME_BONUS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(SRC_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	$(CC) $(CFLAGS) $(INCLUDES_BONUS) -c $< -o $@

libft:
	@$(MAKE) -C $(LIBFT_DIR)

mlx:
	@$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all bonus clean fclean re mlx libft
