/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:49:36 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/25 16:52:59 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static char	**get_dup_map(t_map *map)
{
	char	**dup_map;
	int		j;
	int		height;

	j = 0;
	height = map->height;
	dup_map = malloc(sizeof(char *) * height + 1);
	if (!dup_map)
		return (NULL);
	dup_map[height] = NULL;
	while (height-- && height >= 0)
	{
		dup_map[height] = ft_strdup(map->map[height]);
		if (!dup_map[height])
		{
			while (j < height)
			{
				free(dup_map[j]);
				j++;
			}
			free(dup_map);
			return (NULL);
		}
	}
	return (dup_map);
}

static void	fill(t_map *fake_map, t_player begin)
{
	if (fake_map->map[begin.y][begin.x] == WALL)
		return ;
	fake_map->map[begin.y][begin.x] = WALL;
	fill(fake_map, (t_player){begin.x - 1, begin.y, begin.moves, begin.alive});
	fill(fake_map, (t_player){begin.x + 1, begin.y, begin.moves, begin.alive});
	fill(fake_map, (t_player){begin.x, begin.y - 1, begin.moves, begin.alive});
	fill(fake_map, (t_player){begin.x, begin.y + 1, begin.moves, begin.alive});
}

t_map	*flood_fill(t_map *map)
{
	t_map	*fake_map;
	char 	**dup_map;

	fake_map = malloc(sizeof(*map));
	if (!fake_map)
		return (NULL);
	fake_map->height = map->height;
	fake_map->width = map->width;
	fake_map->oc_player = map->oc_player;
	dup_map = get_dup_map(map);
	if (!dup_map)
		return (NULL);
	fake_map->map = dup_map;
	fill(fake_map, fake_map->oc_player);
	return (fake_map);
}
