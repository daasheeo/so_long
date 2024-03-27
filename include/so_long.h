/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:45:06 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/27 19:24:30 by jesmunoz         ###   ########.fr       */
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
}						t_tile;

# define WATER_IMAGE "assets/usar/water_32x32.png"
# define WATER_IMAGE_64 "assets/usar/water_64x64.png"

# define WATER_NORTH_IMAGE "assets/usar/water_north_32x32.png"
# define WATER_NORTH_IMAGE_64 "assets/usar/water_north_64x64.png"

# define WATER_SOUTH_IMAGE "assets/usar/water_south_32x32.png"
# define WATER_SOUTH_IMAGE_64 "assets/usar/water_south_64x64.png"

# define WATER_EAST_IMAGE "assets/usar/water_east_32x32.png"
# define WATER_EAST_IMAGE_64 "assets/usar/water_east_64x64.png"

# define WATER_WEST_IMAGE "assets/usar/water_west_32x32.png"
# define WATER_WEST_IMAGE_64 "assets/usar/water_west_64x64.png"

# define SAND_IMAGE "assets/usar/sand_32x32.png"
# define SAND_IMAGE_64 "assets/usar/sand_64x64.png"

# define CHUNK_IMAGE "assets/usar/chunk_32x32.png"
# define CHUNK_IMAGE_64 "assets/usar/chunk_64x64.png"

# define PLAYER_IMAGE "assets/usar/luffy_32x32.png"
# define PLAYER_IMAGE_64 "assets/usar/luffy_64x64.png"

# define EXIT_IMAGE "assets/usar/ship_32x32.png"
# define EXIT_IMAGE_64 "assets/usar/ship_64x64.png"

typedef struct s_player
{
	int					x;
	int					y;
	int					moves;
	int					alive;
}						t_player;

typedef struct s_img
{
	mlx_image_t			*water;
	mlx_image_t			*water_north;
	mlx_image_t			*water_south;
	mlx_image_t			*water_east;
	mlx_image_t			*water_west;
	mlx_image_t			*sand;
	mlx_image_t			*chunk;
	mlx_image_t			*player;
	mlx_image_t			*exit;
}						img_t;

typedef struct s_map
{
	char				*name;
	char				**map;
	int					width;
	int					height;
	t_player			oc_player;
	int					players;
	int					collectibles_total;
	int					collectibles_collected;
	int					exits;
	mlx_t				*mlx;
	img_t				*img;
}						t_map;

// Core functions

void					parse_map(t_map *map);
int						is_valid_map_extension(char *map_name);
char					**get_map(char *map_file);
int						is_map_rectangular(char **map);
int						is_map_closed(t_map *map);
int						get_array_map_size(int fd);
int						*get_map_dimesions(char **map);
int						is_map_valid(t_map *map);
int						*get_player_pos(t_map *map);
void					free_array_map(char **map);
void					free_map_struct(t_map *map);
t_map					*flood_fill(t_map *map);
int						can_be_completed(t_map *map);
int						run_game(t_map *map);
/**
 * @brief This function loads the images for the game.
 *
 * @param one_piece The game structure with the mlx pointer
 * @return Structures with the images.
 */
img_t					*load_images(t_map *one_piece);
/**
 * @brief This function loads the water image.
 *
 * @param one_piece The game structure with the mlx pointer
 * @param images The images structure
 * @return The images structure with the water image loaded.
 */
img_t					*load_image_generic(t_map *one_piece, img_t *images,
							const char *image_name,
							mlx_image_t **image_texture);

img_t					*load_water_image(t_map *one_piece, img_t *images);
img_t					*load_water_north_image(t_map *one_piece,
							img_t *images);
img_t					*load_water_south_image(t_map *one_piece,
							img_t *images);
img_t					*load_water_east_image(t_map *one_piece, img_t *images);
img_t					*load_water_west_image(t_map *one_piece, img_t *images);
img_t					*load_sand_image(t_map *one_piece, img_t *images);
img_t					*load_exit_image(t_map *one_piece, img_t *images);
img_t					*load_chunk_image(t_map *one_piece, img_t *images);
img_t					*load_player_image(t_map *one_piece, img_t *images);

void					render_assets(t_map *map);

// Error handling functions
void					error_handler(char *msg);
void					game_cleaner(t_map *one_piece, char *msg);
// Rand function for random number generation
typedef struct s_rand
{
	unsigned long int	seed;
}						t_rand;

/**
 * @brief This function seeds the random number generator.
 *
 * @param generator
 * @param seed
 */
void					rand_seed(t_rand *generator, unsigned int seed);
/**
 * @brief This function generates a random number.
 *
 * @param generator
 * @return int
 */
int						rand_number(t_rand *generator);

#endif