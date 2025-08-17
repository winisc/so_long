/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:49:11 by wini              #+#    #+#             */
/*   Updated: 2025/08/17 17:44:49 by wini             ###   ########.fr       */
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

	new_node = ft_lstnew(ft_strdup_nl(current_row));
	if (!new_node)
	{
		ft_putendl_fd("Error\nallocated lst failed!", 2);
		ft_lstclear(lst_grid, free);
		return (0);
	}
	ft_lstadd_back(lst_grid, new_node);
	if (!ft_validate_components(new_node->content))
	{
		ft_putendl_fd("Error\ninvalid characters!", 2);
		ft_lstclear(lst_grid, free);
		return (0);
	}
	return (1);
}

int	ft_populate_map(char *current_row, t_map *map, t_list **lst_grid)
{
	if (!ft_check_rectangle_map(current_row, map))
	{
		ft_putendl_fd("Error\nnot rectangle!", 2);
		free(current_row);
		ft_lstclear(lst_grid, free);
		ft_free_load_map(map);
		return (0);
	}
	if (!ft_insert_lst_grid(current_row, lst_grid))
	{
		free(current_row);
		ft_free_load_map(map);
		return (0);
	}
	ft_count_components(current_row, map);
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
		grid[i] = ft_strdup((char *)tmp->content);
		if (!grid[i])
		{
			ft_lstclear(lst_grid, free);
			return (0);
		}
		tmp = tmp->next;
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
		return ((t_map *) ft_handle_error("Error\nempty file!", 0, fd, 0));
	map = malloc(sizeof(t_map));
	if (!map)
		return ((t_map *) ft_handle_error("Error\nallocated filed!", 0, fd, 0));
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
	if (!ft_create_map_grid(map, &lst_grid))
		return ((t_map *) ft_handle_error("Error\ngrid allocated filed!",
				map, fd, 0));
	return (map);
}
