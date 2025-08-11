/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wini <wini@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:44:14 by wini              #+#    #+#             */
/*   Updated: 2025/08/10 17:23:49 by wini             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("\033[31minvalid arguments!\033[0m\n");
		return (1);
	}
	if (!is_valid_map(argv[1]))
	{
		printf("\033[33minvalid map!\033[0m\n");
		return (1);
	}
	printf("\033[32mvalid map!\033[0m\n");
	return (0);
}
