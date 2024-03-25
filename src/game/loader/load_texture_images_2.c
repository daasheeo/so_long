/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture_images_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:21:55 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/25 16:59:18 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <so_long.h>

img_t	*load_sand_image(t_map *one_piece, img_t *images)
{
	return (load_image_generic(one_piece, images, SAND_IMAGE_64, &images->sand));
}

img_t	*load_chunk_image(t_map *one_piece, img_t *images)
{
	return (load_image_generic(one_piece, images, CHUNK_IMAGE, &images->chunk));
}

img_t	*load_player_image(t_map *one_piece, img_t *images)
{
	return (load_image_generic(one_piece, images, PLAYER_IMAGE, &images->player));
}
img_t	*load_exit_image(t_map *one_piece, img_t *images)
{
	return (load_image_generic(one_piece, images, EXIT_IMAGE, &images->exit));
}
