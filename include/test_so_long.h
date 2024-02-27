/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_so_long.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:45:02 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/02/27 16:50:16 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_SO_LONG_H
# define TEST_SO_LONG_H

# include "/Users/jesmunoz/.brew/Cellar/cunit/2.1-3/include/CUnit/Basic.h"
# include "/Users/jesmunoz/.brew/Cellar/cunit/2.1-3/include/CUnit/CUnit.h"
# include <so_long.h>
# include <fcntl.h>
# include <unistd.h>

/**
 * @brief Run the tests
 *
 * @return int
 */
int	run_testing(void);


/**TESTS**/
void	test_extension_map_should_be_true(void);
void 	test_extension_map_should_be_false(void);
void	test_open_map_should_return_valid_fd(void);
void	test_open_map_should_return_invalid_fd(void);

#endif