/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 01:39:33 by wini              #+#    #+#             */
/*   Updated: 2025/09/09 01:22:20 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_render_image_to_grid(t_game *game, void *assets, size_t x, size_t y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		assets, x * TILE_SIZE, (y + 1) * TILE_SIZE);
}

void	ft_render_menu_hud(t_game *game)
{
	size_t	x;

	x = 0;
	while (x < game->map->width)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_floor, x * TILE_SIZE, 0);
		x++;
	}
	mlx_string_put(game->mlx, game->win, 10, 21, 0x000000, "MOVES");
	mlx_string_put(game->mlx, game->win, 22, 37, 0x000000, "0");
	mlx_string_put(game->mlx, game->win, 55, 21, 0x000000, "CADETS");
	mlx_string_put(game->mlx, game->win, 70, 37, 0x000000, "0");
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
				ft_render_image_to_grid(game, game->player->frames[0], x, y);
			else if (grid[y][x] == 'C')
				ft_render_image_to_grid(game, game->collectible->frames[0],
					x, y);
			else if (grid[y][x] == 'E')
				ft_render_image_to_grid(game, game->exit->frame_close[0], x, y);
			else if (grid[y][x] == 'T')
				ft_render_image_to_grid(game, game->enemy->frame_down, x, y);
			x++;
		}
		y++;
	}
}

int	ft_start_entity_game(t_game *game, t_map *map)
{
	game->frame_controll = 0;
	game->frame_counter = 0;
	game->map = map;
	game->collectible_now = 0;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, map->width * TILE_SIZE,
			(map->height + 1) * TILE_SIZE, GAME_NAME);
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		return (0);
	game->enemy = malloc(sizeof(t_enemy));
	if (!game->enemy)
		return (0);
	game->collectible = malloc(sizeof(t_collectible));
	if (!game->collectible)
		return (0);
	game->exit = malloc(sizeof(t_exit));
	if (!game->exit)
		return (0);
	ft_init_entitys(game);
	return (1);
}

int	ft_load_game(t_map *map)
{
	t_game	game;

	if (!ft_start_entity_game(&game, map))
	{
		ft_putendl_fd("Error\nInital allocated failed!", 2);
		return (ft_close_game(&game));
	}
	if (!ft_load_assets(&game, map->width, map->height))
	{
		ft_putendl_fd("Error\nLoad assets failed!", 2);
		return (ft_close_game(&game));
	}
	ft_save_enemy_positions(&game);
	ft_save_collectible_positions(&game);
	ft_render_menu_hud(&game);
	ft_render_map(&game, map->grid);
	mlx_key_hook(game.win, ft_key_hook, &game);
	mlx_hook(game.win, 17, 0, ft_close_game, &game);
	mlx_loop_hook(game.mlx, ft_controll_state_game, &game);
	mlx_loop(game.mlx);
	return (1);
}
