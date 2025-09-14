/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsilveir <wsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:44:14 by wini              #+#    #+#             */
/*   Updated: 2025/08/24 16:23:20 by wsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	map = ft_load_map(map_file);
	if (!map)
		return (1);
	game = ft_load_game(map);
	if (!game)
		return (1);
	ft_free_load_map(map);
	return (0);
}
