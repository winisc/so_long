/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:49:11 by wini              #+#    #+#             */
/*   Updated: 2025/08/11 05:01:55 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_validate_rectangle_map(char *row, int width)
{
	int	check_width;

	check_width = 0;
	while (row[check_width] && row[check_width] != '\n')
		check_width++;
	if (check_width != width)
	{
		free(row);
		return (0);
	}
	return (1);
}

static int	ft_get_dimensions(int fd, int *ptr_height, int *ptr_width)
{
	char	*row;

	row = get_next_line(fd);
	if (!row)
		return (0);
	(*ptr_height)++;
	while (row[*ptr_width] && row[*ptr_width] != '\n')
		(*ptr_width)++;
	free(row);
	while (row)
	{
		row = get_next_line(fd);
		if (row)
		{
			if (!ft_validate_rectangle_map(row, (*ptr_width)))
				return (0);
			free(row);
			(*ptr_height)++;
		}
	}
	return (1);
}

t_map	*ft_check_map(int fd)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = 0;
	map->width = 0;
	if (!ft_get_dimensions(fd, &map->height, &map->width))
	{
		free(map);
		return (NULL);
	}
	return (map);
}
