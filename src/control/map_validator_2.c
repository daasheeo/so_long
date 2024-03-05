/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:41:08 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/05 13:38:46 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	is_map_closed(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[0][i] != '\0' && map->map[map->height - 1][i] != '\0')
	{
		if (map->map[0][i] != WALL || map->map[map->height - 1][i] != WALL)
			return (0);
		i++;
	}
	while (i < map->height)
	{
		if (map->map[i][0] != WALL || map->map[i][map->width - 1] != WALL)
			return (0);
		i++;
	}
	return (1);
}

static int	check_map_char(t_map *map, int x, int y)
{
	if (map->map[y][x] != EMPTY && map->map[y][x] != WALL
		&& map->map[y][x] != COLLECTIBLE && map->map[y][x] != EXIT
		&& map->map[y][x] != PLAYER)
		return (0);
	if (map->map[y][x] == PLAYER)
		map->players++;
	if (map->map[y][x] == COLLECTIBLE)
		map->collectibles_total++;
	if (map->map[y][x] == EXIT)
		map->exits++;
	return (1);
}

int	is_map_valid(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->height)
	{
		while (x < map->height)
		{
			if (!check_map_char(map, x, y))
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	if (map->players != 1 || map->exits != 1 || map->collectibles_total < 1)
		return (0);
	return (1);
}
