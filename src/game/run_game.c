/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 09:54:13 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/29 16:48:02 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void 	print_moves(t_map *map)
{
	ft_printf("You made %d moves\n", map->oc_player.moves);
}

void	move_player(int key, t_map *map)
{
	int	*new_pos;

	new_pos = ft_calloc(2, sizeof(int));
	if (!new_pos)
		game_cleaner(map, "Malloc failed");
	new_pos[0] = map->oc_player.x;
	new_pos[1] = map->oc_player.y;
	if (key == MLX_KEY_W)
		new_pos[1] -= 1;
	if (key == MLX_KEY_A)
		new_pos[0] -= 1;
	if (key == MLX_KEY_S)
		new_pos[1] += 1;
	if (key == MLX_KEY_D)
		new_pos[0] += 1;
	if (is_valid_move(map, new_pos))
	{
		map->oc_player.x = new_pos[0];
		map->oc_player.y = new_pos[1];
		map->img->player->instances[0].x = new_pos[0] * PIXELS;
		map->img->player->instances[0].y = new_pos[1] * PIXELS;
		map->oc_player.moves++;
		print_moves(map);
	}
	free(new_pos);
}

void	movements_handler(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = param;
	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map->mlx);
	if (keydata.action == MLX_PRESS && (keydata.key == MLX_KEY_W
			|| keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_S
			|| keydata.key == MLX_KEY_D))
		move_player(keydata.key, map);
}

int	run_game(t_map *map)
{
	img_t	*images;

	map->mlx = mlx_init(map->width * PIXELS, map->height * PIXELS, "One Piece",
			false);
	if (!map->mlx)
		return (0);
	images = load_images(map);
	map->img = images;
	render_assets(map);
	mlx_key_hook(map->mlx, &movements_handler, map);
	mlx_loop(map->mlx);
	return (1);
}
