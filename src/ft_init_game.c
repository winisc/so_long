/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsilveir <wsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 10:38:23 by wini              #+#    #+#             */
/*   Updated: 2025/08/24 18:36:12 by wsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_image_to_grid(t_game *game, void *texture, size_t x, size_t y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		texture, x * TILE_SIZE, y * TILE_SIZE);
}

void	ft_render_map(t_game *game, char **grid)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			ft_render_image_to_grid(game, game->img_floor, x, y);
			if (grid[y][x] == '1')
				ft_render_image_to_grid(game, game->img_wall, x, y);
			else if (grid[y][x] == 'P')
				ft_render_image_to_grid(game, game->img_player, x, y);
			else if (grid[y][x] == 'C')
				ft_render_image_to_grid(game, game->img_collectible, x, y);
			else if (grid[y][x] == 'E')
				ft_render_image_to_grid(game, game->img_exit_close, x, y);
			x++;
		}
		y++;
	}
}

int	ft_load_assets(t_game *game, int w, int h)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"textures/mandatory/wall.xpm", &w, &h);
	if (!game->img_wall)
		return (0);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"textures/mandatory/floor.xpm", &w, &h);
	if (!game->img_floor)
		return (0);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"textures/mandatory/player.xpm", &w, &h);
	if (!game->img_player)
		return (0);
	game->img_exit_close = mlx_xpm_file_to_image(game->mlx,
			"textures/mandatory/exit_close.xpm", &w, &h);
	if (!game->img_exit_close)
		return (0);
	game->img_exit_open = mlx_xpm_file_to_image(game->mlx,
			"textures/mandatory/exit_open.xpm", &w, &h);
	if (!game->img_exit_open)
		return (0);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/mandatory/collectible.xpm", &w, &h);
	if (!game->img_collectible)
		return (0);
	return (1);
}

void	ft_start_game(t_game *game, t_map *map)
{
	game->map = map;
	game->collectible_now = 0;
	game->moves_now = 0;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, map->width * TILE_SIZE,
			map->height * TILE_SIZE, GAME_NAME);
	game->frame_controll = 1;
	game->frame_counter = 0;
}

int	ft_load_game(t_map *map)
{
	t_game	game;

	ft_start_game(&game, map);
	if (!ft_load_assets(&game, map->width, map->height))
	{
		ft_putendl_fd("Error\nLoad assets failed!", 2);
		return (ft_close_game(&game));
	}
	ft_render_map(&game, map->grid);
	mlx_key_hook(game.win, ft_key_hook, &game);
	mlx_hook(game.win, 17, 0, ft_close_game, &game);
	mlx_loop_hook(game.mlx, ft_handle_animation, &game);
	mlx_loop(game.mlx);
	return (1);
}
