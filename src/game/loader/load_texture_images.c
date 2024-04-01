/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture_images.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:55:25 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/04/01 12:37:58 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

img_t	*load_water_image(t_map *map, img_t *images)
{
	return (load_image_generic(map, images, WATER_IMAGE_64,
			&images->water));
}
