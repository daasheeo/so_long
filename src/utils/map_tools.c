/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:55:44 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/02/28 12:19:34 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	get_array_map_size(int fd)
{
	char *line;
	int i;

	i = 0;
	while (1)
	{
		line = ft_strtrim(get_next_line(fd), "\n");
		if (!line)
			break ;
		free(line);
		i++;
	}
	close(fd);
	return (i);
}