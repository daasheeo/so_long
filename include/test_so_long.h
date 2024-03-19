/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_so_long.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:45:02 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/19 12:05:50 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_SO_LONG_H
# define TEST_SO_LONG_H

# include "/Users/jesmunoz/.brew/Cellar/cunit/2.1-3/include/CUnit/Basic.h"
# include "/Users/jesmunoz/.brew/Cellar/cunit/2.1-3/include/CUnit/CUnit.h"
// # include <CUnit/Basic.h>
// # include <CUnit/CUnit.h>
# include <fcntl.h>
# include <so_long.h>
# include <unistd.h>

/**
 * @brief Run the tests
 *
 * @return int
 */
int		run_testing(void);

/**TESTS**/
void	test_extension_map_should_be_true(void);
void	test_extension_map_should_be_false(void);
void	test_get_map(void);
void	test_map_should_be_rectangular(void);
void	test_map_should_not_be_rectangular(void);
void	test_map_should_have_closed_walls(void);
void	test_map_should_not_have_closed_walls(void);
void	test_map_should_have_valid_chars(void);
void	test_map_should_not_have_valid_chars(void);
void	test_get_player_pos(void);
void	test_map_should_be_completed(void);

#endif