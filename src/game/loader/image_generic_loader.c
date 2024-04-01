/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_generic_loader.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:18:12 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/04/01 11:14:00 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

img_t	*load_image_generic(t_map *map, img_t *images,
		const char *image_name, mlx_image_t **image_pointer)
{
	mlx_texture_t	*image_texture;

	image_texture = mlx_load_png(image_name);
	if (!image_texture)
		game_cleaner(map, "Failed to load texture");
	*image_pointer = mlx_texture_to_image(map->mlx, image_texture);
	if (!*image_pointer)
	{
		mlx_delete_texture(image_texture);
		game_cleaner(map, "Failed to load image");
		return (NULL);
	}
	mlx_delete_texture(image_texture);
	return (images);
}
