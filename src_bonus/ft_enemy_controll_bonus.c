/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_controll_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:40:14 by wini              #+#    #+#             */
/*   Updated: 2025/09/04 02:28:51 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_save_enemy_positions(t_game *game)
{
    char    **grid;
    size_t  total_enemy;
	size_t	y;
	size_t	x;

    total_enemy = game->map->count_enemys;
    grid = game->map->grid;
    game->enemy->enemy_x = malloc(total_enemy * sizeof(int));
    if (!game->enemy->enemy_x)
    {
        return (0);
    }  
    game->enemy->enemy_y = malloc(total_enemy * sizeof(int));
    if (!game->enemy->enemy_y)
    {
        free(game->enemy->enemy_x); // evita vazamento
        return (0);
    }
    y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'T')
            {
                total_enemy--;
			    game->enemy->enemy_x[total_enemy] = x;
			    game->enemy->enemy_y[total_enemy] = y;
            }
			x++;
		}
		y++;
	}
	return (1);
}

void ft_move_enemy_controll(t_game *game)
{
    size_t i;

    i = 0;
    while (i < game->map->count_enemys)
    {
        printf("Enemy 1 [x] => %d\n", game->enemy->enemy_x[i]);
        printf("Enemy 1 [y] => %d\n", game->enemy->enemy_y[i]);
        i++;
    }
}
