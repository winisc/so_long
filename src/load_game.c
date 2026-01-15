/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 10:38:23 by wini              #+#    #+#             */
/*   Updated: 2025/09/02 23:50:11 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_image_to_grid(t_game *game, void *assets, size_t x, size_t y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		assets, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game, char **grid)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			render_image_to_grid(game, game->img_floor, x, y);
			if (grid[y][x] == '1')
				render_image_to_grid(game, game->img_wall, x, y);
			else if (grid[y][x] == 'P')
				render_image_to_grid(game, game->img_player, x, y);
			else if (grid[y][x] == 'C')
				render_image_to_grid(game, game->img_collectible, x, y);
			else if (grid[y][x] == 'E')
				render_image_to_grid(game, game->img_exit_close, x, y);
			x++;
		}
		y++;
	}
}

int	load_assets(t_game *game, int w, int h)
{
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"assets/mandatory/wall.xpm", &w, &h);
	if (!game->img_wall)
		return (0);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"assets/mandatory/floor.xpm", &w, &h);
	if (!game->img_floor)
		return (0);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"assets/mandatory/player.xpm", &w, &h);
	if (!game->img_player)
		return (0);
	game->img_exit_close = mlx_xpm_file_to_image(game->mlx,
			"assets/mandatory/exit_close.xpm", &w, &h);
	if (!game->img_exit_close)
		return (0);
	game->img_exit_open = mlx_xpm_file_to_image(game->mlx,
			"assets/mandatory/exit_open.xpm", &w, &h);
	if (!game->img_exit_open)
		return (0);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"assets/mandatory/collectible.xpm", &w, &h);
	if (!game->img_collectible)
		return (0);
	return (1);
}

int	start_game(t_game *game, t_map *map)
{
	game->map = map;
	game->collectible_now = 0;
	game->moves_now = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putendl_fd("Error\nMLX initialization failed!", 2);
		return (0);
	}
	game->win = mlx_new_window(game->mlx, map->width * TILE_SIZE,
			map->height * TILE_SIZE, GAME_NAME);
	if (!game->win)
	{
		ft_putendl_fd("Error\nWindow creation failed!", 2);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (0);
	}
	return (1);
}

int	load_game(t_map *map)
{
	t_game	game;

	if (!start_game(&game, map))
		return (0);
	if (!load_assets(&game, map->width, map->height))
	{
		ft_putendl_fd("Error\nLoad assets failed!", 2);
		return (close_game(&game));
	}
	render_map(&game, map->grid);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (1);
}
