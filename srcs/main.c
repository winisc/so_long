/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:44:14 by wini              #+#    #+#             */
/*   Updated: 2025/08/17 15:13:32 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;
	char	*map_file;

	if (argc != 2)
		return (printf("invalid arguments!\n"), 1);
	map_file = argv[1];
	map = ft_load_map(map_file);
	if (!map)
		return (1);
	printf("valid map!\n");
	if (!ft_load_game(map)) 
		return (printf("mlx failed!\n"), 1);
	ft_free_load_map(map);
	return (0);
}
