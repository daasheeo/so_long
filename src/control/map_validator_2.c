/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:41:08 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/02/29 16:34:05 by jesmunoz         ###   ########.fr       */
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
	printf("\n");
	while (x < map_coordinates[1])
	{
		printf("map[0] = %s\n", map[x]);
		if (map[x][0] != '1' || map[x][map_coordinates[0] - 1] != '1')
			return (0);
		x++;
	}
	return (1);
}
