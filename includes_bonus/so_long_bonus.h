/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsilveir <wsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:17:39 by wini              #+#    #+#             */
/*   Updated: 2025/09/16 19:06:05 by wsilveir         ###   ########.fr       */
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
#  define FRAME_RATE_ANIMATIONS 50000
# endif

# ifndef FRAME_RATE_EVENTS
#  define FRAME_RATE_EVENTS 150000
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
	void	*frame_down;
	void	*frame_up;
	int		frame_controll;
	int		frame_counter;
	size_t	*enemy_x;
	size_t	*enemy_y;
	int		*reset_move;
}	t_enemy;

typedef struct s_collectible
{
	void	*frames[4];
	size_t	*collectible_x;
	size_t	*collectible_y;
	int		frame_controll;
	int		frame_counter;
	int		*active;
}	t_collectible;

typedef struct s_exit
{
	void	*frame_open[4];
	void	*frame_close[4];
	int		frame_controll;
	int		frame_counter;
	int		open;
}	t_exit;

typedef struct s_player
{
	void	*frames[4];
	int		frame_controll;
	int		frame_counter;
	int		moves_now;
}	t_player;

typedef struct s_game
{
	int				state;
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

void	handle_animation(t_game *game);
void	handle_player_animation(t_game *game);
void	handle_exit_animation(t_game *game);
int		load_assets(t_game *game, int w, int h);
void	init_entitys(t_game *game);
int		controll_state_game(t_game *game);
int		save_enemy_positions(t_game *game);
int		save_collectible_positions(t_game *game);
int		init_collectible_arrays(t_game *game, size_t total_collectible);
void	disable_collectible_now(t_game *game, size_t x, size_t y);
void	move_enemy_controll(t_game *game);

void	render_game_over(t_game *game);
void	render_victory(t_game *game);

#endif