/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:46:56 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/02/27 17:21:48 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test_so_long.h>

void	test_extension_map_should_be_true(void)
{
	char *map_file = "valid_map.ber";
	CU_ASSERT_TRUE(is_valid_map_extension(map_file));
}

void 	test_extension_map_should_be_false(void)
{
	char *map_file = "invalid_map.txt";
	CU_ASSERT_FALSE(is_valid_map_extension(map_file));
}

void	test_open_map_should_return_valid_fd(void)
{
	char *map_file = "maps/map1.ber";
	CU_ASSERT_TRUE(open_map(map_file) > 0);
}

void	test_open_map_should_return_invalid_fd(void)
{
	char *map_file = "maps/invalid.ber";
	CU_ASSERT_EQUAL(open_map(map_file), -1);
}

void test_map_should_be_rectangular(void)
{
	char *map_file = "maps/map1.ber";
	CU_ASSERT_TRUE(is_map_rectangular(map_file));
}

void test_map_should_not_be_rectangular(void)
{
	char *map_file = "maps/invalid.ber";
	CU_ASSERT_FALSE(is_map_rectangular(map_file));
}
