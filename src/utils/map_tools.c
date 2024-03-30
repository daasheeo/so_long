/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:55:44 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/29 17:37:11 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	get_array_map_size(int fd)
{
	char	*line;
	int		i;

	if (fd < 0)
		return (-1);
	i = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		i++;
	}
	return (i);
}

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
	map_coordinates = ft_calloc(2, sizeof(int));
	if (!map_coordinates)
		return (NULL);
	map_coordinates[0] = 0;
	map_coordinates[1] = 0;
	map_coordinates[0] = x;
	map_coordinates[1] = y;
	return (map_coordinates);
}

static void	*set_map_lines(char **map, int fd)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = ft_strtrim(line, "\n");
		if (!tmp)
			break ;
		map[i] = ft_strdup(tmp);
		if (!map[i])
			return (NULL);
		free(line);
		free(tmp);
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**get_map(char *map_file)
{
	char	**map;
	int		fd;
	int		array_map_size;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	array_map_size = get_array_map_size(fd);
	if (array_map_size == -1)
		return (NULL);
	close(fd);
	map = ft_calloc(array_map_size + 1, sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = set_map_lines(map, fd);
	if (!map)
		return (NULL);
	close(fd);
	return (map);
}

int	*get_player_pos(t_map *map)
{
	int	*pos;
	int	x;
	int	y;

	pos = (int *)ft_calloc(2, sizeof(int));
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
