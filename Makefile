# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wini <wini@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 19:14:29 by wini              #+#    #+#              #
#    Updated: 2025/08/17 00:52:53 by wini             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRCS_DIR = srcs
MLX_DIR = mlx
LIBFT_DIR = libs/libft

INCLUDES = -Iincludes -Imlx -I$(LIBFT_DIR)

SRCS = $(SRCS_DIR)/main.c \
		$(SRCS_DIR)/ft_check_map.c \
		$(SRCS_DIR)/ft_load_map.c \
		$(SRCS_DIR)/ft_so_long_utils.c \
		$(SRCS_DIR)/ft_check_path_map.c \
		$(SRCS_DIR)/ft_map_erros.c \
		
OBJS = $(SRCS:.c=.o)

MLX_LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT_A = $(LIBFT_DIR)/libft.a

all: mlx libft $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -L$(LIBFT_DIR) -lft $(MLX_LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

libft:
	@$(MAKE) -C $(LIBFT_DIR)

mlx:
	@$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re mlx libft