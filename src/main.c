/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:43:44 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/19 11:57:15 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>
#include <test_so_long.h>

void	ft_leaks(void)
{
	system("leaks -q so_long");
}

int	main(int argc, char **argv)
{
	atexit(ft_leaks);
	if (argc == 2 && ft_strncmp(argv[1], "test", 4) == 0)
		return (run_testing());
	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		return (1);
	}
	parse_map(argv[1]);
	return (0);
}
