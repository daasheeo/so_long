/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:43:44 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/04/01 12:36:59 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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

int	main(int argc, char **argv)
{
	t_map	*map;

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
	free_array_textures(map->collectibles_instances);
	mlx_terminate(map->mlx);
	free(map);
	return (EXIT_SUCCESS);
}
