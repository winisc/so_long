/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 04:41:59 by wini              #+#    #+#             */
/*   Updated: 2025/08/11 05:07:17 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(t_map initial_map)
{

}

t_map	*ft_load_map(char *map_file)
{
	int		fd;
	t_map	*initial_map;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	initial_map = ft_check_map(fd);
	if (!initial_map)
	{
		close(fd);
		return (NULL);
	}
	ft_parse_map(fd, initial_map);
	close(fd);
	return (initial_map);
}
    // o mapa é cercado por paredes ? (linhas e colunas extremas só possuem o numero 1 ?)
    // existe apenas uma E ?
    // existe apenas um P ?
    // Existe pelo menos um C ?

    //SECONDS VALIDATES

    // a saída é acessivel ? (existe um caminho viavel ?)
    // todos os coletáveis são acessiveis ? => Realizar uma propagação e validar o caminho de cada coletavel ate o P