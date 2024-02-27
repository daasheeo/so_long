/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:47:33 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/02/27 12:47:48 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <so_long.h>

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