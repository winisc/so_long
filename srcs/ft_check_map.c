/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:49:11 by wini              #+#    #+#             */
/*   Updated: 2025/08/17 00:54:43 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_rectangle_map(char *current_row, t_map *map)
{
	size_t	current_width;

	current_width = ft_width_len(current_row);
	if (current_width != map->width)
	{
		free(current_row);
		free(map);
		return (0);
	}
	return (1);
}

int	ft_insert_lst_grid(char *current_row, t_list **lst_grid)
{
	t_list	*new_node;

	new_node = ft_lstnew(ft_strdup_nl(current_row));
	if (!new_node)
	{
		ft_lstclear(lst_grid, free);
		return (0);
	}
	ft_lstadd_back(lst_grid, new_node);
	return (1);
}

int	ft_populate_map(char *current_row, t_map *map, t_list **lst_grid)
{
	if (!ft_check_rectangle_map(current_row, map))
	{
		printf("(not rectangle)\n");
		return (0);
	}
	if (!ft_insert_lst_grid(current_row, lst_grid))
	{
		printf("(allocated node failed)\n");
		return (0);
	}
	ft_count_components(current_row, map);
	return (1);
}

int	ft_create_map_grid(t_map *map, t_list *lst_grid)
{
	char	**grid;
	size_t	i;

	grid = (char **)malloc((map->height + 1) * sizeof(char *));
	if (!grid)
		return (0);
	i = 0;
	while (lst_grid)
	{
		grid[i] = ft_strdup((char *)lst_grid->content);
		if (!grid[i])
		{
			ft_free_load_map(map);
			return (0);
		}
		lst_grid = lst_grid->next;
		i++;
	}
	grid[i] = NULL;
	map->grid = grid;
	ft_lstclear(&lst_grid, free);
	return (1);
}

t_map	*ft_parse_map(int fd)
{
	char	*row;
	t_map	*map;
	t_list	*lst_grid;

	row = get_next_line(fd);
	if (!row)
		return (printf("(empty map_file)\n"), NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	ft_start_map(map);
	lst_grid = NULL;
	map->width = ft_width_len(row);
	while (row)
	{
		if (!ft_populate_map(row, map, &lst_grid))
			return ((t_map *) ft_free_map_file(fd));
		free(row);
		row = get_next_line(fd);
		map->height++;
	}
	if (!ft_create_map_grid(map, lst_grid))
		return (printf("(create grid failed)\n"), NULL);
	return (map);
}

