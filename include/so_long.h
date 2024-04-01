/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:45:06 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/04/01 12:46:38 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PIXELS 64

# include <MLX42/MLX42.h>
# include <fcntl.h>
# include <libft.h>
# include <stdio.h>

/**
 * @brief Various enums for map characters
 */
typedef enum e_tile
{
	EMPTY = '0',
	WALL = '1',
	PLAYER = 'P',
	EXIT = 'E',
	COLLECTIBLE = 'C'
}				t_tile;

# define WATER_IMAGE_64 "textures/water_64x64.png"

# define SAND_IMAGE_64 "textures/sand_64x64.png"

# define CHUNK_IMAGE_64 "textures/chunk_64x64.png"

# define PLAYER_IMAGE_64 "textures/luffy_64x64.png"

# define EXIT_IMAGE_64 "textures/ship_64x64.png"

typedef struct s_player
{
	int			x;
	int			y;
	int			moves;
	int			alive;
}				t_player;

typedef struct s_img
{
	mlx_image_t	*water;
	mlx_image_t	*sand;
	mlx_image_t	*chunk;
	mlx_image_t	*player;
	mlx_image_t	*exit;
}				img_t;

typedef struct s_texture
{
	int			y;
	int			x;
	int			instance;
	bool		collected;
}				t_texture;

typedef struct s_map
{
	char		*name;
	char		**map;
	int			width;
	int			height;
	t_player	oc_player;
	int			players;
	int			collectibles_total;
	int			collectibles_collected;
	t_texture	**collectibles_instances;
	int			exits;
	mlx_t		*mlx;
	img_t		*img;
}				t_map;

// Validation functions
int				is_valid_map_extension(char *map_name);
int				is_map_rectangular(char **map);
int				is_map_closed(t_map *map);
int				is_map_valid(t_map *map);
int				can_be_completed(t_map *map);
int				is_valid_move(t_map *map, int *new_pos);

// Manipulation functions
void			parse_map(t_map *map);
char			**get_map(char *map_file);
int				get_array_map_size(int fd);
int				*get_map_dimesions(char **map);
t_map			*flood_fill(t_map *map);
void			new_character_pos(t_map *map, int *new_pos);
int				run_game(t_map *map);

// Player functions
int				*get_player_pos(t_map *map);

// Load images functions
img_t			*load_images(t_map *map);
img_t			*load_image_generic(t_map *map, img_t *images,
					const char *image_name, mlx_image_t **image_texture);
img_t			*load_water_image(t_map *map, img_t *images);
img_t			*load_sand_image(t_map *map, img_t *images);
img_t			*load_exit_image(t_map *map, img_t *images);
img_t			*load_chunk_image(t_map *map, img_t *images);
img_t			*load_player_image(t_map *map, img_t *images);

// Render functions
void			render_assets(t_map *map);

// Clean up functions
void			free_array_map(char **map);
void			free_map_struct(t_map *map);
void			free_array_textures(t_texture **textures);
void			free_images(t_map *map);

// Error handling functions
void			error_handler(char *msg);
void			game_cleaner(t_map *map, char *msg);

#endif