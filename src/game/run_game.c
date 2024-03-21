/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:54:13 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/21 18:55:34 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <so_long.h>

int	run_game(t_map *map)
{
	img_t *images;

	map->mlx = mlx_init(map->width * PIXELS, map->height * PIXELS, "One Piece", false);
	if (!map->mlx)
		return (0);
	images = load_images(map);
	return (1);
}
