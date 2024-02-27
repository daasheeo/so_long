/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init_cunit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:43:39 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/02/27 13:30:39 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test_so_long.h>

void	parser_suite(void)
{
	CU_pSuite test_parser_suite;
	// Set up suites and tests
	test_parser_suite = CU_add_suite("Parser Tests", NULL, NULL);
	
	CU_add_test(test_parser_suite, "test_parse_valid_extension_map",
		test_parse_valid_extension_map);
	CU_add_test(test_parser_suite, "test_parse_invalid_extension_map",
		test_parse_invalid_extension_map);
	CU_add_test(test_parser_suite, "test_parse_open_valid_map",
		test_parse_open_valid_map);
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