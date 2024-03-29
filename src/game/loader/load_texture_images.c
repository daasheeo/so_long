/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture_images.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:55:25 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/29 16:41:40 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

img_t	*load_water_image(t_map *one_piece, img_t *images)
{
	return (load_image_generic(one_piece, images, WATER_IMAGE_64,
			&images->water));
}

img_t	*load_water_north_image(t_map *one_piece, img_t *images)
{
	return (load_image_generic(one_piece, images, WATER_NORTH_IMAGE,
			&images->water_north));
}

img_t	*load_water_south_image(t_map *one_piece, img_t *images)
{
	return (load_image_generic(one_piece, images, WATER_SOUTH_IMAGE,
			&images->water_south));
}

img_t	*load_water_east_image(t_map *one_piece, img_t *images)
{
	return (load_image_generic(one_piece, images, WATER_EAST_IMAGE,
			&images->water_east));
}

img_t	*load_water_west_image(t_map *one_piece, img_t *images)
{
	return (load_image_generic(one_piece, images, WATER_WEST_IMAGE,
			&images->water_west));
}
