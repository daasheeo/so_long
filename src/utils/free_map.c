/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:22:58 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/04/01 09:40:35 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void 	free_images(t_map *map)
{
	mlx_delete_image(map->mlx, map->img->water);
	mlx_delete_image(map->mlx, map->img->water_north);
	mlx_delete_image(map->mlx, map->img->water_south);
	mlx_delete_image(map->mlx, map->img->water_east);
	mlx_delete_image(map->mlx, map->img->water_west);
	mlx_delete_image(map->mlx, map->img->sand);
	mlx_delete_image(map->mlx, map->img->chunk);
	mlx_delete_image(map->mlx, map->img->exit);
	mlx_delete_image(map->mlx, map->img->player);
	free(map->img);
}

void 	free_array_textures(t_texture **textures)
{
	int	i;

	i = 0;
	while (textures[i])
	{
		free(textures[i]);
		i++;
	}
	free(textures);
}

void	free_array_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_map_struct(t_map *map)
{
	free_array_map(map->map);
	free(map);
}
