# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wsilveir <wsilveir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 19:14:29 by wini              #+#    #+#              #
#    Updated: 2025/10/17 20:55:18 by wsilveir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g

SRC_DIR			= src
SRC_DIR_BONUS	= src_bonus
MLX_DIR			= mlx
LIBFT_DIR		= libs/libft

INCLUDES		= -Iincludes -Imlx -I$(LIBFT_DIR)
INCLUDES_BONUS	= -Iincludes_bonus -Imlx -I$(LIBFT_DIR)

SRC				= $(SRC_DIR)/so_long.c \
				  $(SRC_DIR)/check_map.c \
				  $(SRC_DIR)/load_map.c \
				  $(SRC_DIR)/so_long_utils.c \
				  $(SRC_DIR)/check_path_map.c \
				  $(SRC_DIR)/map_erros.c \
				  $(SRC_DIR)/load_game.c \
				  $(SRC_DIR)/state_game.c \
				  $(SRC_DIR)/player_controll.c

SRC_BONUS		= $(SRC_DIR_BONUS)/so_long_bonus.c \
				  $(SRC_DIR_BONUS)/check_map_bonus.c \
				  $(SRC_DIR_BONUS)/load_map_bonus.c \
				  $(SRC_DIR_BONUS)/so_long_utils_bonus.c \
				  $(SRC_DIR_BONUS)/check_path_map_bonus.c \
				  $(SRC_DIR_BONUS)/map_erros_bonus.c \
				  $(SRC_DIR_BONUS)/load_game_bonus.c \
				  $(SRC_DIR_BONUS)/state_game_bonus.c \
				  $(SRC_DIR_BONUS)/player_controll_bonus.c \
				  $(SRC_DIR_BONUS)/animation_controll_bonus.c \
				  $(SRC_DIR_BONUS)/collectible_controll_bonus.c \
				  $(SRC_DIR_BONUS)/enemy_controll_bonus.c \
				  $(SRC_DIR_BONUS)/init_entitys_bonus.c \
				  $(SRC_DIR_BONUS)/load_assets_bonus.c \
				  $(SRC_DIR_BONUS)/close_game_bonus.c \
				  $(SRC_DIR_BONUS)/end_game.c

OBJS			= $(SRC:.c=.o)
OBJS_BONUS		= $(SRC_BONUS:.c=.o)

MLX_LIBS		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT_A			= $(LIBFT_DIR)/libft.a

# ------------------------------------------------------------------------------

all: mlx libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -L$(LIBFT_DIR) -lft $(MLX_LIBS) -o $(NAME)
	@echo "\033[32m[OK]\033[0m $(NAME) compiled (mandatory version)."

bonus: mlx libft .bonus

.bonus: $(OBJS_BONUS)
	@echo "\033[33m[INFO]\033[0m Building bonus version..."
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(INCLUDES_BONUS) -L$(LIBFT_DIR) -lft $(MLX_LIBS) -o $(NAME)
	@touch .bonus
	@echo "\033[33m[OK]\033[0m Bonus version compiled as $(NAME)."

# ------------------------------------------------------------------------------

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(SRC_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	$(CC) $(CFLAGS) $(INCLUDES_BONUS) -c $< -o $@

# ------------------------------------------------------------------------------

libft:
	@$(MAKE) -C $(LIBFT_DIR)

mlx:
	@$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@echo "\033[31m[Cleaned]\033[0m object files."

fclean: clean
	rm -f $(NAME) .bonus
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "\033[31m[Removed]\033[0m all binaries and libraries."

re: fclean all

.PHONY: all bonus clean fclean re mlx libft
