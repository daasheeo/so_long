/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:43:44 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/30 17:28:45 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <test_so_long.h>

void	ft_leaks(void)
{
	system("leaks -q so_long");
}

t_map	*init_map(char *name)
{
	t_map	*map;
	int		*dimensions;
	int		*player_position;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		game_cleaner(NULL, "Malloc failed");
	map->map = get_map(name);
	if (map->map == NULL)
		game_cleaner(map, "Invalid map");
	dimensions = get_map_dimesions(map->map);
	if (dimensions == NULL)
		return (NULL);
	map->width = dimensions[0];
	map->height = dimensions[1];
	free(dimensions);
	player_position = get_player_pos(map);
	if (player_position == NULL)
		return (NULL);
	map->oc_player.x = player_position[0];
	map->oc_player.y = player_position[1];
	free(player_position);
	return (map);
}

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

int	main(int argc, char **argv)
{
	t_map	*map;

	// atexit(ft_leaks);
	// if (argc == 2 && ft_strncmp(argv[1], "test", 4) == 0)
	// 	return (run_testing());
	if (argc != 2)
		game_cleaner(NULL, "Usage: ./so_long [map.ber]");
	if (!is_valid_map_extension(argv[1]))
		game_cleaner(NULL, "Invalid map extension");
	map = init_map(argv[1]);
	if (map == NULL)
		game_cleaner(map, "Invalid map");
	parse_map(map);
	if (!run_game(map))
		return (EXIT_FAILURE);
	free_array_map(map->map);
	free_images(map);
	mlx_terminate(map->mlx);
	free(map);
	
	return (EXIT_SUCCESS);
}
