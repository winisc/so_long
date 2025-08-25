/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsilveir <wsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:40:05 by wsilveir          #+#    #+#             */
/*   Updated: 2025/08/25 20:28:03 by wsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

size_t	ft_width_len(char *row)
{
	size_t	len;

	len = 0;
	while (row[len])
	{
		if (row[len] == '\n')
			return (len);
		len++;
	}
	return (len);
}

void	ft_start_map(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->count_collectibles = 0;
	map->count_player = 0;
	map->count_exit = 0;
	map->grid = NULL;
	map->px = 0;
	map->py = 0;
	map->ex = 0;
	map->ey = 0;
}

char	*ft_strdup_nl(const char *src)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	if (src[len - 1] != '\n')
		len = len + 1;
	str = (char *)malloc(len * sizeof(char));
	i = 0;
	if (!str)
		return (NULL);
	while (src[i] != '\n' && src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

void	ft_add_count_components(char *current_row, t_map *map)
{
	if (!current_row || !map)
		return ;
	while (*current_row)
	{
		if (*current_row == 'C')
			map->count_collectibles++;
		if (*current_row == 'P')
			map->count_player++;
		if (*current_row == 'E')
			map->count_exit++;
		current_row++;
	}
}

int	ft_validate_components(char *current_row)
{
	if (!current_row)
		return (0);
	while (*current_row)
	{
		if (*current_row != 'C' && *current_row != '1' && *current_row != '0'
			&& *current_row != 'E' && *current_row != 'P')
			return (0);
		current_row++;
	}
	return (1);
}
