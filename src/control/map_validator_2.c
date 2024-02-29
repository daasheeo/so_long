/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:41:08 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/02/28 12:10:37 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int	check_map_walls(char *line, int i)
{
	int	prev_row_len;
	int	next_row_len;

	prev_row_len = 0;
	next_row_len = 0;
	if (i == 0)
		prev_row_len = ft_strlen(line);
	else
	{
		next_row_len = ft_strlen(line);
		if (next_row_len != prev_row_len)
			return (0);
		prev_row_len = next_row_len;
	}
	return (1);
}

int	is_map_closed(char **map)
{
	char	*line;
	int		i;

	i = 0;
	while (map[i])
	{
		if (!check_map_walls(map[i], i))
			return (0);
		i++;
	}
	return (1);
}
