/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:44:28 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/25 16:53:32 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	parse_map(t_map *map)
{
	if (!is_map_rectangular(map->map))
		error_handler("Map is not rectangular");
	if (!is_map_closed(map))
		error_handler("Map is not closed");
	if (!is_map_valid(map))
		error_handler("Map has invalid chars");
	if (!can_be_completed(map))
		error_handler("Map can not be completed");
}
