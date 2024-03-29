/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:45:42 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/29 16:46:13 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	is_valid_move(t_map *map, int *new_pos)
{
	if (new_pos[0] < 0 || new_pos[0] >= map->width || new_pos[1] < 0
		|| new_pos[1] >= map->height)
		return (0);
	if (map->map[new_pos[1]][new_pos[0]] == WALL)
		return (0);
	return (1);
}
