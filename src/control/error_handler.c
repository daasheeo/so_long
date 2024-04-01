/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:53:48 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/04/01 11:14:00 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	error_handler(char *msg)
{
	ft_putendl_fd("Error", STDOUT_FILENO);
	ft_putendl_fd(msg, STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

void	game_cleaner(t_map *map, char *msg)
{
	if (map)
	{
		if (map->map)
			free_array_map(map->map);
		if (map->mlx)
			mlx_terminate(map->mlx);
		if (map->collectibles_instances)
			free_array_textures(map->collectibles_instances);
		free(map);
	}
	error_handler(msg);
}
