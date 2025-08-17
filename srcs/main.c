/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:44:14 by wini              #+#    #+#             */
/*   Updated: 2025/08/17 02:19:01 by wini             ###   ########.fr       */
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
			"assets/wall.xpm", &w, &h);
	if (!game->img_wall)
		return (0);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"assets/floor.xpm", &w, &h);
	if (!game->img_floor)
		return (0);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"assets/player.xpm", &w, &h);
	if (!game->img_player)
		return (0);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"assets/exit.xpm", &w, &h);
	if (!game->img_exit)
		return (0);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"assets/collectible.xpm", &w, &h);
	if (!game->img_collectible)
		return (0);
	return (1);
}

int	ft_load_game(t_map *map)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, map->width * TILE_SIZE,
			map->height * TILE_SIZE, GAME_NAME);
	if (!ft_load_assets(&game, map->width, map->height))
		return (printf("load assets failed!\n"), 0);
	ft_render_map(&game, map->grid);
	mlx_loop(game.mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	char	*map_file;

	if (argc != 2)
		return (printf("invalid arguments!\n"), 1);
	map_file = argv[1];
	map = ft_load_map(map_file);
	if (!map)
		return (printf("invalid map!\n"), 1);
	printf("valid map!\n");
	if (!ft_load_game(map))
		return (printf("mlx failed!\n"), 1);
	ft_free_load_map(map);
	return (0);
}
