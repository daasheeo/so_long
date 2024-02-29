/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init_cunit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:43:39 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/02/29 10:29:45 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test_so_long.h>

void	parser_suite(void)
{
	CU_pSuite test_parser_suite;
	// Set up suites and tests
	test_parser_suite = CU_add_suite("Parser Tests", NULL, NULL);
	
	CU_add_test(test_parser_suite, "test of test_extension_map_should_be_true()",
		test_extension_map_should_be_true);
	CU_add_test(test_parser_suite, "test of test_extension_map_should_be_false()",
		test_extension_map_should_be_false);
	CU_add_test(test_parser_suite, "test of test_open_map_should_return_valid_fd()",
		test_open_map_should_return_valid_fd);
	CU_add_test(test_parser_suite, "test of test_open_map_should_return_invalid_fd()",
		test_open_map_should_return_invalid_fd);
	CU_add_test(test_parser_suite, "test of test_get_map()",
		test_get_map);
	CU_add_test(test_parser_suite, "test of test_map_should_be_rectangular()",
		test_map_should_be_rectangular);
	CU_add_test(test_parser_suite, "test of test_map_should_not_be_rectangular()",
		test_map_should_not_be_rectangular);
	CU_add_test(test_parser_suite, "test of test_map_should_have_closed_walls()",
		test_map_should_have_closed_walls);
	CU_add_test(test_parser_suite, "test of test_map_should_not_have_closed_walls()",
		test_map_should_not_have_closed_walls);
}

int	run_testing(void)
{
	// Initialize CUnit test registry
	if (CUE_SUCCESS != CU_initialize_registry())
		return (CU_get_error());
	// Set up suites and tests
	
	parser_suite();
	
	// Run all tests using the basic interface
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return (CU_get_error());
}