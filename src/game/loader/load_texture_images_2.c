/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture_images_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:21:55 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/04/01 11:14:00 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

img_t	*load_sand_image(t_map *map, img_t *images)
{
	return (load_image_generic(map, images, SAND_IMAGE_64,
			&images->sand));
}

img_t	*load_chunk_image(t_map *map, img_t *images)
{
	return (load_image_generic(map, images, CHUNK_IMAGE_64,
			&images->chunk));
}

img_t	*load_player_image(t_map *map, img_t *images)
{
	return (load_image_generic(map, images, PLAYER_IMAGE_64,
			&images->player));
}

img_t	*load_exit_image(t_map *map, img_t *images)
{
	return (load_image_generic(map, images, EXIT_IMAGE_64,
			&images->exit));
}
