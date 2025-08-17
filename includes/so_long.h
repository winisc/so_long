/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:17:39 by wini              #+#    #+#             */
/*   Updated: 2025/08/17 20:09:01 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>

# ifndef TILE_SIZE
#  define TILE_SIZE 64
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
	size_t	px;
	size_t	py;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collectible;
	size_t	collectible_now;
	size_t	moves;
}	t_game;

t_map	*ft_load_map(char *map_file);
t_map	*ft_parse_map(int fd);
size_t	ft_width_len(char *row);
void	*ft_free_map_file(int fd);
void	*ft_free_load_map(t_map *map);
void	ft_free_grid(char **grid);
void	ft_start_map(t_map *map);
void	*ft_handle_error(char *msg, t_map *map, int fd, char **grid);
void	ft_count_components(char *current_row, t_map *map);
void	ft_player_move(t_game *game, char *direction);
void	ft_render_image_to_grid(t_game *game, void *texture, size_t x,
			size_t y);
char	*ft_strdup_nl(const char *src);
int		ft_check_path(t_map *map);
int		ft_check_extension(char *map_file);
int		ft_load_game(t_map *map);
int		ft_close_game(t_game *game);
int		ft_key_hook(int keycode, t_game *game);
int		ft_validate_components(char *current_row);

#endif