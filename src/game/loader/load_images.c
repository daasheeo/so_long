/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:55:25 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/21 19:09:45 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <so_long.h>


img_t	*load_water_image(t_map *one_piece, img_t *images)
{
	mlx_texture_t *water;

	water = mlx_load_png(WATER);
	if (!water)
		game_cleaner(one_piece, "Failed to load water texture");
	images->water = mlx_texture_to_image(one_piece->mlx, water);
	if (!images->water)
	{
		mlx_delete_texture(water);
		game_cleaner(one_piece, "Failed to load water image");
	}
	mlx_delete_texture(water);
	return (images);
}
