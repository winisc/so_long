/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsilveir <wsilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:49:11 by wini              #+#    #+#             */
/*   Updated: 2025/08/24 18:08:48 by wsilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_rectangle_map(char *current_row, t_map *map)
{
	size_t	current_width;

	current_width = ft_width_len(current_row);
	if (current_width != map->width)
		return (0);
	return (1);
}

int	ft_insert_lst_grid(char *current_row, t_list **lst_grid)
{
	t_list	*new_node;
	char	*content_row;

	content_row = ft_strdup_nl(current_row);
	if (!ft_validate_components(content_row))
	{
		ft_putendl_fd("Error\nInvalid components!", 2);
		free (content_row);
		return (0);
	}
	new_node = ft_lstnew(content_row);
	if (!new_node)
	{
		ft_putendl_fd("Error\nAllocated lst failed!", 2);
		return (0);
	}
	ft_lstadd_back(lst_grid, new_node);
	return (1);
}

int	ft_populate_map(char *current_row, t_map *map, t_list **lst_grid)
{
	if (!ft_check_rectangle_map(current_row, map))
	{
		ft_putendl_fd("Error\nMap is not rectangular!", 2);
		free(current_row);
		ft_lstclear(lst_grid, free);
		return (0);
	}
	if (!ft_insert_lst_grid(current_row, lst_grid))
	{
		free(current_row);
		ft_lstclear(lst_grid, free);
		return (0);
	}
	ft_add_count_components(current_row, map);
	return (1);
}

int	ft_create_map_grid(t_map *map, t_list **lst_grid)
{
	char	**grid;
	t_list	*tmp;
	size_t	i;

	grid = (char **)malloc((map->height + 1) * sizeof(char *));
	if (!grid)
		return (0);
	map->grid = grid;
	i = 0;
	tmp = *lst_grid;
	while (tmp)
	{
		grid[i] = ft_strdup((char *)(tmp)->content);
		if (!grid[i])
		{
			ft_lstclear(lst_grid, free);
			return (0);
		}
		tmp = (tmp)->next;
		i++;
	}
	grid[i] = NULL;
	ft_lstclear(lst_grid, free);
	return (1);
}

t_map	*ft_parse_map(int fd)
{
	char	*row;
	t_map	*map;
	t_list	*lst_grid;

	row = get_next_line(fd);
	if (!row)
		return (ft_handle_error("Error\nEmpty file!", 0, 0, 0));
	map = malloc(sizeof(t_map));
	if (!map)
		return (ft_handle_error("Error\nAllocated map failed!", 0, 0, 0));
	ft_start_map(map);
	lst_grid = NULL;
	map->width = ft_width_len(row);
	while (row)
	{
		if (!ft_populate_map(row, map, &lst_grid))
			return (ft_handle_error(0, map, fd, 0));
		free(row);
		row = get_next_line(fd);
		map->height++;
	}
	if (!ft_create_map_grid(map, &lst_grid))
		return (ft_handle_error("Error\nCreate map grid failed!", 0, 0, 0));
	return (map);
}
