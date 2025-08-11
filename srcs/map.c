/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:49:11 by wini              #+#    #+#             */
/*   Updated: 2025/08/10 22:03:27 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int populate_map(int fd)
{
    char    *line;
    
    line = get_next_line(fd);
    if (!line)
        return (0);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    return (1);
}


int is_valid_map(char *map)
{
    // FIRST VALIDATES

    //o file existe ?
    int     fd;

    fd = open(map, O_RDONLY);
    if (fd == -1)
        return (0);
    // existe algo dentro do file ?
    if (!populate_map(fd))
        return (0);
    close(fd);
    return (1);
    // o mapa é rentangular ? (todas as linhas possuem a mesma dimensão ?)
    // o mapa é cercado por paredes ? (linhas e colunas extremas só possuem o numero 1 ?)
    // existe apenas uma E ?
    // existe apenas um P ?
    // Existe pelo menos um C ?

    //SECONDS VALIDATES

    // a saída é acessivel ? (existe um caminho viavel ?)
    // todos os coletáveis são acessiveis ? => Realizar uma propagação e validar o caminho de cada coletavel ate o P
}
