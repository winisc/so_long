/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:17:39 by wini              #+#    #+#             */
/*   Updated: 2025/09/07 03:07:22 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>

# ifndef TILE_SIZE
#  define TILE_SIZE 48
# endif

# ifndef FRAME_RATE_ANIMATIONS
#  define FRAME_RATE_ANIMATIONS 5000
# endif

# ifndef FRAME_RATE_EVENTS
#  define FRAME_RATE_EVENTS 40000
# endif

# ifndef GAME_NAME
#  define GAME_NAME "NAO ENTRE EM PANICO"
# endif

typedef struct s_map
{
	size_t	width;
	size_t	height;
	size_t	count_collectibles;
	size_t	count_enemys;
	size_t	count_player;
	size_t	count_exit;
	char	**grid;
	size_t	player_x;
	size_t	player_y;
	size_t	exit_x;
	size_t	exit_y;
}	t_map;

typedef struct s_enemy
{
	void	*img_enemy_1;
	int		frame_controll;
	int		frame_counter;
	int		*enemy_x;
	int		*enemy_y;
	int		*reset_move;
}	t_enemy;

typedef struct s_collectible
{
	void	*img_collectible_1;
	int		frame_controll;
	int		frame_counter;
}	t_collectible;

typedef struct s_exit
{
	void	*frames_open[3];
	void	*img_exit_close;
	int		frame_controll;
	int		frame_counter;
	int		open;
}	t_exit;

typedef struct s_player
{
	void	*frames[5];
	int		frame_controll;
	int		frame_counter;
	int		moves_now;
}	t_player;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	void			*img_wall;
	void			*img_floor;
	size_t			collectible_now;
	t_map			*map;
	t_player		*player;
	t_enemy			*enemy;
	t_exit			*exit;
	t_collectible	*collectible;
	int				frame_controll;
	int				frame_counter;

}	t_game;

t_map	*ft_load_map(char *map_file);
t_map	*ft_parse_map(int fd);
size_t	ft_width_len(char *row);
void	*ft_free_map_file(int fd);
void	*ft_free_load_map(t_map *map);
void	ft_free_grid(char **grid);
void	ft_start_map(t_map *map);
void	*ft_handle_error(char *msg, t_map *map, int fd, char **grid);
void	ft_add_count_components(char *current_row, t_map *map);
void	ft_player_move(t_game *game, char *direction);
void	ft_render_image_to_grid(t_game *game, void *assets, size_t x,
			size_t y);
char	*ft_strdup_nl(const char *src);
int		ft_check_path(t_map *map);
int		ft_check_extension_fd(char *map_file);
int		ft_load_game(t_map *map);
int		ft_close_game(t_game *game);
int		ft_key_hook(int keycode, t_game *game);
int		ft_validate_components(char *current_row);

void		ft_handle_animation(t_game *game);
void	ft_handle_player_animation(t_game *game);
void	ft_handle_exit_animation(t_game *game);
int		ft_load_assets(t_game *game, int w, int h);
void	ft_init_entitys(t_game *game);
int		ft_controll_state_game(t_game *game);
int		ft_save_enemy_positions(t_game *game);
void	ft_move_enemy_controll(t_game *game);

#endif