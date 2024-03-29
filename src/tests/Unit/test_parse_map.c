/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:46:56 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/29 16:42:48 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test_so_long.h>

void	test_extension_map_should_be_true(void)
{
	char	*map_file;

	map_file = "valid_map.ber";
	CU_ASSERT_TRUE(is_valid_map_extension(map_file));
}

void	test_extension_map_should_be_false(void)
{
	char	*map_file;

	map_file = "invalid_map.txt";
	CU_ASSERT_FALSE(is_valid_map_extension(map_file));
}

void	test_get_map(void)
{
	char	*map_file;
	char	**map;

	map_file = "maps/map.ber";
	map = get_map(map_file);
	CU_ASSERT_PTR_NOT_NULL(map);
	free_array_map(map);
}

void	test_map_should_be_rectangular(void)
{
	char	*map_file;
	char	**map;

	map_file = "maps/map.ber";
	map = get_map(map_file);
	CU_ASSERT_TRUE(is_map_rectangular(map));
	free_array_map(map);
}

void	test_map_should_not_be_rectangular(void)
{
	char	*map_file;
	char	**map;

	map_file = "maps/map_invalid.ber";
	map = get_map(map_file);
	CU_ASSERT_FALSE(is_map_rectangular(map));
	free_array_map(map);
}

void	test_map_should_have_closed_walls(void)
{

	char *map_file = "maps/map.ber";
	t_map	*fake_map = (t_map *)malloc(sizeof(t_map));
	if (!fake_map)
		return ;
	
	fake_map->map = get_map(map_file);
	int *dimensions = get_map_dimesions(fake_map->map);
	fake_map->width = dimensions[0];
	fake_map->height = dimensions[1];
	free(dimensions);

	CU_ASSERT_TRUE(is_map_closed(fake_map));
	free_array_map(fake_map->map);
	free(fake_map);
}

void	test_map_should_not_have_closed_walls(void)
{

	char *map_file = "maps/map_not_closed.ber";
	t_map	*fake_map = (t_map *)malloc(sizeof(t_map));
	if (!fake_map)
		return ;
	
	fake_map->map = get_map(map_file);
	int *dimensions = get_map_dimesions(fake_map->map);
	fake_map->width = dimensions[0];
	fake_map->height = dimensions[1];
	free(dimensions);

	CU_ASSERT_FALSE(is_map_closed(fake_map));
	free_array_map(fake_map->map);
	free(fake_map);
}

void 	test_map_should_have_valid_chars(void)
{
	char *map_file = "maps/map.ber";
	t_map *fake_map = (t_map *)malloc(sizeof(t_map));
	if (!fake_map)
		return ;

	fake_map->map = get_map(map_file);
	int *dimensions = get_map_dimesions(fake_map->map);
	fake_map->width = dimensions[0];
	fake_map->height = dimensions[1];
	free(dimensions);

	fake_map->players = 0;
	fake_map->collectibles_collected = 0;
	fake_map->collectibles_total = 0;
	fake_map->exits = 0;

	CU_ASSERT_TRUE(is_map_valid(fake_map));
	free_array_map(fake_map->map);
	free(fake_map);
}

void 	test_map_should_not_have_valid_chars(void)
{
	char *map_file = "maps/map_invalid_chars.ber";
	t_map *fake_map = (t_map *)malloc(sizeof(t_map));
	if (!fake_map)
		return ;

	fake_map->map = get_map(map_file);
	int *dimensions = get_map_dimesions(fake_map->map);
	fake_map->width = dimensions[0];
	fake_map->height = dimensions[1];

	fake_map->players = 0;
	fake_map->collectibles_collected = 0;
	fake_map->collectibles_total = 0;
	fake_map->exits = 0;

	CU_ASSERT_FALSE(is_map_valid(fake_map));
	free_array_map(fake_map->map);
	free(fake_map);
	free(dimensions);
}

void	test_get_player_pos(void)
{
	char *map_file = "maps/map.ber";
	t_map *fake_map = (t_map *)malloc(sizeof(t_map));
	if (!fake_map)
		return ;

	fake_map->map = get_map(map_file);
	int *dimensions = get_map_dimesions(fake_map->map);
	fake_map->width = dimensions[0];
	fake_map->height = dimensions[1];
	int *player_pos = get_player_pos(fake_map);
	fake_map->oc_player.x = player_pos[0];
	fake_map->oc_player.y = player_pos[1];
	CU_ASSERT_EQUAL(fake_map->oc_player.x, 7);
	CU_ASSERT_EQUAL(fake_map->oc_player.y, 2);
	free_array_map(fake_map->map);
	free(fake_map);
	free(dimensions);
	free(player_pos);
}

void	test_map_should_be_completed(void)
{
	char *map_file = "maps/map.ber";
	t_map *fake_map = (t_map *)malloc(sizeof(t_map));
	if (!fake_map)
		return ;

	fake_map->map = get_map(map_file);
	int *dimensions = get_map_dimesions(fake_map->map);
	fake_map->width = dimensions[0];
	fake_map->height = dimensions[1];

	int *player_pos = get_player_pos(fake_map);
	fake_map->oc_player.x = player_pos[0];
	fake_map->oc_player.y = player_pos[1];
	fake_map->players = 0;
	fake_map->collectibles_collected = 0;
	fake_map->collectibles_total = 0;
	fake_map->exits = 0;

	CU_ASSERT_TRUE(can_be_completed(fake_map));
	free_array_map(fake_map->map);
	free(fake_map);
	free(dimensions);
	free(player_pos);
}

void	test_map_should_not_be_completed(void)
{
	char *map_file = "maps/map_no_valid_path.ber";
	t_map *fake_map = (t_map *)malloc(sizeof(t_map));
	if (!fake_map)
		return ;

	fake_map->map = get_map(map_file);
	int *dimensions = get_map_dimesions(fake_map->map);
	fake_map->width = dimensions[0];
	fake_map->height = dimensions[1];

	int *player_pos = get_player_pos(fake_map);
	fake_map->oc_player.x = player_pos[0];
	fake_map->oc_player.y = player_pos[1];
	fake_map->players = 0;
	fake_map->collectibles_collected = 0;
	fake_map->collectibles_total = 0;
	fake_map->exits = 0;

	CU_ASSERT_FALSE(can_be_completed(fake_map));
	free_array_map(fake_map->map);
	free(fake_map);
	free(dimensions);
	free(player_pos);
}
