/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:17:39 by wini              #+#    #+#             */
/*   Updated: 2025/09/02 23:15:22 by wini             ###   ########.fr       */
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

# ifndef GAME_NAME
#  define GAME_NAME "test so_long_bonus"
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
	size_t	ex;
	size_t	ey;
}	t_map;

typedef struct s_enemy
{
	void	*img_enemy_anim_1;
	int		frame_controll;
	int		frame_counter;
}	t_enemy;

typedef struct s_collectible
{
	void	*img_collectible_anim_1;
	int		frame_controll;
	int		frame_counter;
}	t_collectible;

typedef struct s_player
{
	void	*img_player_anim_1;
	void	*img_player_anim_2;
	void	*img_player_anim_3;
	void	*img_player_anim_4;
	void	*img_player_anim_5;
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
	void			*img_exit_close;
	void			*img_exit_open;
	size_t			collectible_now;
	t_map			*map;
	t_player		*player;
	t_enemy			*enemy;
	t_collectible	*collectible;

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
void	ft_render_image_to_grid(t_game *game, void *texture, size_t x,
			size_t y);
char	*ft_strdup_nl(const char *src);
int		ft_check_path(t_map *map);
int		ft_check_extension_fd(char *map_file);
int		ft_load_game(t_map *map);
int		ft_close_game(t_game *game);
int		ft_key_hook(int keycode, t_game *game);
int		ft_validate_components(char *current_row);

int		ft_handle_animation(t_game *game);

#endif