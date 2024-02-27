/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:44:28 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/02/27 17:09:27 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <so_long.h>

void	parse_map(char *map_name)
{
	if (!is_valid_map_extension(map_name))
	{
		ft_putstr_fd("Error\nInvalid map extension\n", 2);
		exit(1);
	}
	if (open_map(map_name) < 0)
	{
		ft_putstr_fd("Error\nInvalid map file\n", 2);
		exit(1);
	}
}