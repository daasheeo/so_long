/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:05:03 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/25 16:40:19 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <so_long.h>

void	render_background(t_map *map)
{
	int x;
	int y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == '1')
				mlx_image_to_window(map->mlx, map->img->water, x * PIXELS, y * PIXELS);
			else
				mlx_image_to_window(map->mlx, map->img->sand, x * PIXELS, y * PIXELS);
			x++;
		}
		y++;
	}
}
