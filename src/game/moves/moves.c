/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:15:27 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/04/01 12:35:30 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	print_moves(t_map *map)
{
	ft_printf("You made %d moves\n", map->oc_player.moves);
}

int	get_instance(t_map *map, int y, int x)
{
	int	i;

	i = 0;
	while (map->collectibles_instances[i])
	{
		if (map->collectibles_instances[i]->y == y
			&& map->collectibles_instances[i]->x == x)
			return (map->collectibles_instances[i]->instance);
		i++;
	}
	return (-1);
}

void	new_character_pos(t_map *map, int *new_pos)
{
	int	instance;

	map->oc_player.x = new_pos[0];
	map->oc_player.y = new_pos[1];
	map->img->player->instances[0].x = new_pos[0] * PIXELS;
	map->img->player->instances[0].y = new_pos[1] * PIXELS;
	map->oc_player.moves++;
	if (map->map[new_pos[1]][new_pos[0]] == COLLECTIBLE)
	{
		instance = get_instance(map, new_pos[1], new_pos[0]);
		if (map->collectibles_instances[instance]->collected != 1)
		{
			map->img->chunk->instances[instance].enabled = 0;
			map->collectibles_instances[instance]->collected = 1;
			map->collectibles_collected++;
		}
	}
	print_moves(map);
	if (map->collectibles_collected == map->collectibles_total
		&& map->map[new_pos[1]][new_pos[0]] == EXIT)
	{
		ft_printf("You have satisfied luffy's hunger!!! \n");
		mlx_close_window(map->mlx);
	}
}
