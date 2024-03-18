/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:43:44 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/18 12:49:37 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <test_so_long.h>

int	main(int argc, char **argv)
{
	if (argc == 2 && ft_strncmp(argv[1], "test", 4) == 0)
		return (run_testing());
	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		return (1);
	}
	//parse_map(argv[1]);
		
	return (0);
}
