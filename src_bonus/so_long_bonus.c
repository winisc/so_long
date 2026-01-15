/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:44:14 by wini              #+#    #+#             */
/*   Updated: 2025/09/04 02:47:07 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	int		game;
	char	*map_file;

	if (argc != 2)
	{
		ft_putendl_fd("Error\nInvalid arguments!", 2);
		return (1);
	}
	map_file = argv[1];
	map = load_map(map_file);
	if (!map)
		return (1);
	game = load_game(map);
	if (!game)
		return (1);
	return (0);
}
