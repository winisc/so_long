/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:17:39 by wini              #+#    #+#             */
/*   Updated: 2025/09/02 23:49:04 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>

# ifndef TILE_SIZE
#  define TILE_SIZE 48
# endif

# ifndef GAME_NAME
#  define GAME_NAME "test so_long"
# endif

typedef struct s_map
{
	size_t	width;
	size_t	height;
	size_t	count_collectibles;
	size_t	count_player;
	size_t	count_exit;
	char	**grid;
	size_t	player_x;
	size_t	player_y;
	size_t	exit_x;
	size_t	exit_y;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit_close;
	void	*img_exit_open;
	void	*img_collectible;
	size_t	collectible_now;
	int		moves_now;
}	t_game;

t_map	*load_map(char *map_file);
t_map	*parse_map(int fd);
size_t	width_len(char *row);
void	*free_map_file(int fd);
void	*free_load_map(t_map *map);
void	free_grid(char **grid);
void	start_map(t_map *map);
void	*handle_error(char *msg, t_map *map, int fd, char **grid);
void	add_count_components(char *current_row, t_map *map);
void	player_move(t_game *game, char *direction);
void	render_image_to_grid(t_game *game, void *assets, size_t x,
			size_t y);
char	*ft_strdup_nl(const char *src);
int		check_path(t_map *map);
int		check_extension_fd(char *map_file);
int		load_game(t_map *map);
int		close_game(t_game *game);
int		key_hook(int keycode, t_game *game);
int		validate_components(char *current_row);

#endif