/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:23:13 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/02/27 17:26:16 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	open_map(char *map_file)
{
	int	fd;
	int	temp;

	fd = open(map_file, O_RDONLY);
	temp = fd;
	close(fd);
	return (temp);
}

int	is_valid_map_extension(char *map_name)
{
	int len;

	len = ft_strlen(map_name);
	if (len < 4)
		return (0);
	if (ft_strncmp(map_name + len - 4, ".ber", 4) == 0)
		return (1);
	return (0);
}

int is_map_rectangular(char *map_file)
{
	(void)map_file;
	return (1);
}