/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:05:03 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/04/01 10:04:18 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	set_collectibles_instances(t_map *map, int y, int x, int32_t index)
{
	map->collectibles_instances[index] = malloc(sizeof(t_texture));
	if (!map->collectibles_instances[index])
		game_cleaner(map, "Malloc failed");
	map->collectibles_instances[index]->x = x;
	map->collectibles_instances[index]->y = y;
	map->collectibles_instances[index]->collected = 0;
	map->collectibles_instances[index]->instance = index;
}

static void	put_elements(t_map *map, int x, int y)
{
	int32_t	index;

	index = 0;
	if (map->map[y][x] == '1')
		mlx_image_to_window(map->mlx, map->img->water, x * PIXELS, y * PIXELS);
	if (map->map[y][x] == '0')
		mlx_image_to_window(map->mlx, map->img->sand, x * PIXELS, y * PIXELS);
	if (map->map[y][x] == 'C')
	{
		mlx_image_to_window(map->mlx, map->img->sand, x * PIXELS, y * PIXELS);
		index = mlx_image_to_window(map->mlx, map->img->chunk, x * PIXELS, y * PIXELS);
		if (index < 0)
			game_cleaner(map, "mlx_image_to_window failed");
		set_collectibles_instances(map, y, x, index);
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
	t_texture **collectibles;

	collectibles = ft_calloc(map->collectibles_total + 1, sizeof(t_texture *));
	if (!collectibles)
		game_cleaner(map, "Malloc failed");
	map->collectibles_instances = collectibles;
	render_background(map);
	render_player(map);
}
