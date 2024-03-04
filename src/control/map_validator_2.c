/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:41:08 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/04 16:58:33 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	*get_map_dimesions(char **map)
{
	int	x;
	int	y;
	int	*map_coordinates;

	x = 0;
	y = 0;
	while (map[0][x] != '\0')
		x++;
	while (map[y] != NULL)
		y++;
	map_coordinates = (int *)malloc(sizeof(int) * 2);
	if (!map_coordinates)
		return (NULL);
	map_coordinates[0] = x;
	map_coordinates[1] = y;
	return (map_coordinates);
}

int	is_map_closed(char **map)
{
	int	*map_coordinates;
	int	x;

	x = 0;
	map_coordinates = get_map_dimesions(map);
	if (!map_coordinates)
		return (0);
	while (map[0][x] != '\0' && map[map_coordinates[1] - 1][x] != '\0')
	{
		if (map[0][x] != '1' || map[map_coordinates[1] - 1][x] != '1')
			return (0);
		x++;
	}
	while (x < map_coordinates[1])
	{
		if (map[x][0] != '1' || map[x][map_coordinates[0] - 1] != '1')
			return (0);
		x++;
	}
	free(map_coordinates);
	return (1);
}

int		check_map_char(t_map *map, int x, int y)
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
		while (x < map->width)
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
