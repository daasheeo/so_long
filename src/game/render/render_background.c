/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:05:03 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/27 19:24:11 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	put_elements(t_map *map, int x, int y)
{
	if (map->map[y][x] == '1')
		mlx_image_to_window(map->mlx, map->img->water, x * PIXELS, y * PIXELS);
	if (map->map[y][x] == '0')
		mlx_image_to_window(map->mlx, map->img->sand, x * PIXELS, y * PIXELS);
	if (map->map[y][x] == 'C')
	{
		mlx_image_to_window(map->mlx, map->img->sand, x * PIXELS, y * PIXELS);
		mlx_image_to_window(map->mlx, map->img->chunk, x * PIXELS, y * PIXELS);
	}
	if (map->map[y][x] == 'E')
	{
		mlx_image_to_window(map->mlx, map->img->sand, x * PIXELS, y * PIXELS);
		mlx_image_to_window(map->mlx, map->img->exit, x * PIXELS, y * PIXELS);
	}
}

static void	render_background(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			put_elements(map, x, y);
			x++;
		}
		y++;
	}
}

static void	render_player(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
			{
				mlx_image_to_window(map->mlx, map->img->sand, x * PIXELS, y
					* PIXELS);
				mlx_image_to_window(map->mlx, map->img->player, x * PIXELS, y
					* PIXELS);
			}
			x++;
		}
		y++;
	}
}

void	render_assets(t_map *map)
{
	render_background(map);
	render_player(map);
}
