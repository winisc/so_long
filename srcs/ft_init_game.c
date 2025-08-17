/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 10:38:23 by wini              #+#    #+#             */
/*   Updated: 2025/08/17 17:22:08 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_image_to_grid(t_game *game, void *asset, size_t x, size_t y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		asset, x * TILE_SIZE, y * TILE_SIZE);
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
				ft_render_image_to_grid(game, game->img_exit, x, y);
			x++;
		}
		y++;
	}
}

int	ft_load_assets(t_game *game, int w, int h)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &w, &h);
	if (!game->img_wall)
		return (0);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &w, &h);
	if (!game->img_floor)
		return (0);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &w, &h);
	if (!game->img_player)
		return (0);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &w, &h);
	if (!game->img_exit)
		return (0);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &w, &h);
	if (!game->img_collectible)
		return (0);
	return (1);
}

int	ft_load_game(t_map *map)
{
	t_game	game;

	game.map = map;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, map->width * TILE_SIZE,
			map->height * TILE_SIZE, GAME_NAME);
	if (!ft_load_assets(&game, map->width, map->height))
		return (printf("load assets failed!\n"), 0);
	ft_render_map(&game, map->grid);
	mlx_key_hook(game.win, ft_key_hook, &game);
	mlx_hook(game.win, 17, 0, ft_close_game, &game);
	mlx_loop(game.mlx);
	return (1);
}
