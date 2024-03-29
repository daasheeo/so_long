/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:45:51 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/29 16:41:57 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

img_t	*load_images(t_map *one_piece)
{
	img_t	*images;

	images = (img_t *)ft_calloc(1, sizeof(img_t));
	if (!images)
		return (NULL);
	images = load_water_image(one_piece, images);
	images = load_water_north_image(one_piece, images);
	images = load_water_south_image(one_piece, images);
	images = load_water_east_image(one_piece, images);
	images = load_water_west_image(one_piece, images);
	images = load_sand_image(one_piece, images);
	images = load_chunk_image(one_piece, images);
	images = load_exit_image(one_piece, images);
	images = load_player_image(one_piece, images);
	return (images);
}
