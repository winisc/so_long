/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_erros.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsilveir <wsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 00:51:28 by wini              #+#    #+#             */
/*   Updated: 2025/08/24 15:33:16 by wsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(char **grid)
{
	size_t	i;

	i = 0;
	while (grid && grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	*free_load_map(t_map *map)
{
	if (!map)
		return (NULL);
	if (!map->grid)
	{
		free (map);
		map = NULL;
		return (NULL);
	}
	free_grid(map->grid);
	map->grid = NULL;
	free (map);
	map = NULL;
	return (NULL);
}

void	*free_map_file(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (NULL);
}

void	*handle_error(char *msg, t_map *map, int fd, char **grid)
{
	if (map)
		free_load_map(map);
	if (fd)
		free_map_file(fd);
	else if (grid)
		free_grid(grid);
	if (msg)
		ft_putendl_fd(msg, 2);
	return (NULL);
}

int	check_extension_fd(char *map_file)
{
	size_t	len;

	len = ft_strlen(map_file);
	len = len - 4;
	if (ft_strncmp(map_file + len, ".ber", 4))
		return (0);
	return (1);
}
