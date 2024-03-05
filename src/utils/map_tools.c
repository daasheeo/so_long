/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:55:44 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/05 13:29:05 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	get_array_map_size(int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (1)
	{
		line = ft_strtrim(get_next_line(fd), "\n");
		if (!line)
			break ;
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

int	*get_map_dimesions(char **map)
{
	int x;
	int y;
	int *map_coordinates;

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

char	**get_map(char *map_file)
{
	char	*line;
	char	**map;
	int		i;
	int		fd;

	i = 0;
	map = malloc(sizeof(char *) * get_array_map_size(open_map(map_file)) + 1);
	if (!map)
		return (NULL);
	fd = open_map(map_file);
	while (1)
	{
		line = ft_strtrim(get_next_line(fd), "\n");
		if (!line)
			break ;
		map[i] = ft_strdup(line);
		if (!map[i])
			return (NULL);
		free(line);
		i++;
	}
	i++;
	map[i] = NULL;
	close(fd);
	return (map);
}

int *get_player_pos(t_map *map)
{
	int *pos;
	int x;
	int y;
	
	pos = (int *)malloc(sizeof(int) * 2);
	if (!pos)
		return (NULL);
	x = 0;
	y = 0;
	
	while (y < map->height)
	{
		while (x < map->width)
		{
			if (map->map[y][x] == PLAYER)
			{
				pos[0] = x;
				pos[1] = y;
				return (pos);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (NULL);
}