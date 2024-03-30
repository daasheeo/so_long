/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:15:27 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/29 17:27:17 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <so_long.h>

void new_character_pos(t_map *map, int *new_pos)
{
	map->oc_player.x = new_pos[0];
	map->oc_player.y = new_pos[1];
	map->img->player->instances[0].x = new_pos[0] * PIXELS;
	map->img->player->instances[0].y = new_pos[1] * PIXELS;
	map->oc_player.moves++;
	printf("Total Collectibles: %d\n", map->collectibles_total);
	printf("Collectibles collected: %d\n", map->collectibles_collected);
}
