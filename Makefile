# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wini <wini@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 19:14:29 by wini              #+#    #+#              #
#    Updated: 2025/08/07 21:37:15 by wini             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS_DIR = srcs
INCLUDES = -Iincludes -Imlx
MLX_DIR = mlx

SRCS = $(SRCS_DIR)/main.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_LIBS = -Lmlx -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIBS) -o $(NAME)

clean:
	rm -f $(OBJS)
	@$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
