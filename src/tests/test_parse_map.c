/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:46:56 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/02/27 13:58:53 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test_so_long.h>

void	test_parse_valid_extension_map(void)
{
	char *map_name = "valid_map.ber";
	CU_ASSERT_EQUAL(is_valid_map_extension(map_name), 1);
}

void 	test_parse_invalid_extension_map(void)
{
	char *map_name = "invalid_map.txt";
	CU_ASSERT_EQUAL(is_valid_map_extension(map_name), 0);
}

void	test_parse_open_valid_map(void)
{
	char *map_name = "maps/map1.ber";
	int fd = open(map_name, O_RDONLY);
	CU_ASSERT_NOT_EQUAL(fd, -1);
	close(fd);
}