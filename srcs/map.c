/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:49:11 by wini              #+#    #+#             */
/*   Updated: 2025/08/10 06:26:18 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int is_valid_map(map)
{
    // FIRST VALIDATES

    //o file existe ?
    // existe algo dentro do file ?
    // o mapa é rentangular ? (todas as linhas possuem a mesma dimensão ?)
    // o mapa é cercado por paredes ? (linhas e colunas extremas só possuem o numero 1 ?)
    // existe apenas uma E ?
    // existe apenas um P ?
    // Existe pelo menos um C ?

    //SECONDS VALIDATES

    // a saída é acessivel ? (existe um caminho viavel ?)
    // todos os coletáveis são acessiveis ? => Realizar uma propagação e validar o caminho de cada coletavel ate o P
}