/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:41:08 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/02/29 14:17:59 by jesmunoz         ###   ########.fr       */
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
	printf("\nmap_coordinates[0] = %d\n", map_coordinates[0]);
	printf("map_coordinates[1] = %d\n", map_coordinates[1]);
	printf("map[0] = %s\n", map[0]);
	printf("map[map_coordinates[1] - 1] = %s\n", map[map_coordinates[1] - 1]);
	if (ft_strchr(map[0], '1') != 0 || ft_strchr(map[map_coordinates[1] - 1], '1') != 0)
		return (0);
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
