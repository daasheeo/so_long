/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:41:08 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/02/29 13:03:47 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	*get_map_dimesions(char **map)
{
	int	x;
	int	y;
	int	*map_dimesion;

	x = 0;
	y = 0;
	while (map[0][x] != '\0')
		x++;
	while (map[y] != NULL)
		y++;
	map_dimesion = (int *)malloc(sizeof(int) * 2);
	if (!map_dimesion)
		return (NULL);
	map_dimesion[0] = x;
	map_dimesion[1] = y;
	return (map_dimesion);
}

int	is_map_closed(char **map)
{
	int	*map_dimesion;
	int	x;
	int	y;

	x = 0;
	y = 0;
	map_dimesion = get_map_dimesions(map);
	if (!map_dimesion)
		return (0);
	if (!ft_strchr(map[x], '1') || !ft_strchr(map[map_dimesion[x] - 1], '1'))
		return (0);
	while (x <= map_dimesion[0])
	{
		if (map[x][y] != '1' || map[x][map_dimesion[y] - 1] != '1')
			return (0);
		x++;
	}
	return (1);
}
