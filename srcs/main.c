/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:44:14 by wini              #+#    #+#             */
/*   Updated: 2025/08/11 05:00:45 by wini             ###   ########.fr       */
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
		return (printf("invalid map!\n"), 1);
	printf("valid map!\n");
	free (map);
	return (0);
}
