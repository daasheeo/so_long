/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_so_long.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:45:02 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/02/27 11:59:52 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_SO_LONG_H
# define TEST_SO_LONG_H

# include "/Users/jesmunoz/.brew/Cellar/cunit/2.1-3/include/CUnit/Basic.h"
# include "/Users/jesmunoz/.brew/Cellar/cunit/2.1-3/include/CUnit/CUnit.h"

/**
 * @brief Run the tests
 *
 * @return int
 */
int	run_testing(void);


/**TESTS**/
void	test_parse_valid_map(void);
void	test_parse_invalid_map(void);

#endif