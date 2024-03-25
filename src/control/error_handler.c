/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:53:48 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/25 16:23:05 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <so_long.h>

void	error_handler(char *msg)
{
	ft_putendl_fd("Error", STDOUT_FILENO);
	ft_putendl_fd(msg, STDOUT_FILENO);
	exit (EXIT_FAILURE);
}

void	game_cleaner(t_map *one_piece, char *msg)
{
	if (one_piece)
	{
		if (one_piece->mlx)
			mlx_terminate(one_piece->mlx);
		if (one_piece->map)
			free_array_map(one_piece->map);
		free(one_piece);
	}
	error_handler(msg);
}