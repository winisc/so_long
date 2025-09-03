/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 10:38:23 by wini              #+#    #+#             */
/*   Updated: 2025/09/02 23:50:11 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_render_image_to_grid(t_game *game, void *assets, size_t x, size_t y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		assets, x * TILE_SIZE, y * TILE_SIZE);
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
				ft_render_image_to_grid(game, game->player->img_player_anim_1,
					x, y);
			else if (grid[y][x] == 'C')
				ft_render_image_to_grid(game,
					game->collectible->img_collectible_anim_1, x, y);
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
			"assets/bonus/wall.xpm", &w, &h);
	if (!game->img_wall)
		return (0);
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"assets/bonus/floor.xpm", &w, &h);
	if (!game->img_floor)
		return (0);
	game->player->img_player_anim_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/bonus/player_anim_1.xpm", &w, &h);
	if (!game->player->img_player_anim_1)
		return (0);
	game->player->img_player_anim_2 = mlx_xpm_file_to_image(game->mlx,
			"assets/bonus/player_anim_2.xpm", &w, &h);
	if (!game->player->img_player_anim_2)
		return (0);
	game->player->img_player_anim_3 = mlx_xpm_file_to_image(game->mlx,
			"assets/bonus/player_anim_3.xpm", &w, &h);
	if (!game->player->img_player_anim_3)
		return (0);
	game->player->img_player_anim_4 = mlx_xpm_file_to_image(game->mlx,
			"assets/bonus/player_anim_4.xpm", &w, &h);
	if (!game->player->img_player_anim_4)
		return (0);
	game->player->img_player_anim_5 = mlx_xpm_file_to_image(game->mlx,
			"assets/bonus/player_anim_5.xpm", &w, &h);
	if (!game->player->img_player_anim_5)
		return (0);
	game->img_exit_close = mlx_xpm_file_to_image(game->mlx,
			"assets/bonus/exit_close.xpm", &w, &h);
	if (!game->img_exit_close)
		return (0);
	game->img_exit_open = mlx_xpm_file_to_image(game->mlx,
			"assets/bonus/exit_open.xpm", &w, &h);
	if (!game->img_exit_open)
		return (0);
	game->collectible->img_collectible_anim_1 = mlx_xpm_file_to_image(game->mlx,
			"assets/bonus/collectible.xpm", &w, &h);
	if (!game->collectible->img_collectible_anim_1)
		return (0);
	return (1);
}

static void ft_init_images_null(t_game *game)
{
    game->img_wall = NULL;
    game->img_floor = NULL;
    game->img_exit_close = NULL;
    game->img_exit_open = NULL;
    if (game->player)
    {
        game->player->img_player_anim_1 = NULL;
        game->player->img_player_anim_2 = NULL;
        game->player->img_player_anim_3 = NULL;
        game->player->img_player_anim_4 = NULL;
        game->player->img_player_anim_5 = NULL;
        game->player->frame_controll = 0;
        game->player->frame_counter = 0;
        game->player->moves_now = 0;
    }
    if (game->collectible)
    {
        game->collectible->img_collectible_anim_1 = NULL;
        game->collectible->frame_controll = 0;
        game->collectible->frame_counter = 0;
    }
    if (game->enemy)
    {
        game->enemy->img_enemy_anim_1 = NULL;
        game->enemy->frame_controll = 0;
        game->enemy->frame_counter = 0;
    }
}

int	ft_start_game(t_game *game, t_map *map)
{
	game->map = map;
	game->collectible_now = 0;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, map->width * TILE_SIZE,
			map->height * TILE_SIZE, GAME_NAME);
	game->player = malloc(sizeof(t_player));
	if (!game->player)
		return (0);
	game->enemy = malloc(sizeof(t_enemy));
	if (!game->enemy)
		return (0);
	game->collectible = malloc(sizeof(t_collectible));
	if (!game->collectible)
		return (0);
	ft_init_images_null(game);
	return (1);
}

int	ft_load_game(t_map *map)
{
	t_game	game;

	if (!ft_start_game(&game, map))
	{
		ft_putendl_fd("Error\nInital allocated failed!", 2);
		return (ft_close_game(&game));
	}
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
