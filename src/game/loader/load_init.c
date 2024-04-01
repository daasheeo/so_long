/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:45:51 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/04/01 12:38:02 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

img_t	*load_images(t_map *map)
{
	img_t	*images;

	images = (img_t *)ft_calloc(1, sizeof(img_t));
	if (!images)
		return (NULL);
	images = load_water_image(map, images);
	images = load_sand_image(map, images);
	images = load_chunk_image(map, images);
	images = load_exit_image(map, images);
	images = load_player_image(map, images);
	return (images);
}
