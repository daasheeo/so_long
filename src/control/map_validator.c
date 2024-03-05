/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:23:13 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/05 12:02:02 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	open_map(char *map_file)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	return (fd);
}

int	is_valid_map_extension(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len < 4)
		return (0);
	if (ft_strncmp(map_name + len - 4, ".ber", 4) == 0)
		return (1);
	return (0);
}

static int	check_map(char *line, int i, int *prev_row_len, int *next_row_len)
{
	if (i == 0)
		*prev_row_len = ft_strlen(line);
	else
	{
		*next_row_len = ft_strlen(line);
		if (*next_row_len != *prev_row_len)
			return (0);
		*prev_row_len = *next_row_len;
	}
	return (1);
}

int	is_map_rectangular(char **map)
{
	int	i;
	int	prev_row_len;
	int	next_row_len;

	prev_row_len = 0;
	next_row_len = 0;
	i = 0;
	while (map[i] != NULL)
	{
		if (!check_map(map[i], i, &prev_row_len, &next_row_len))
			return (0);
		i++;
	}
	return (1);
}
