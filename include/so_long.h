/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:45:06 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/21 19:05:11 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PIXELS 32

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

# define WATER "assets/usar/water_1.png"
# define WATER_NORTH "assets/usar/water_north.png"
# define WATER_SOUTH "assets/usar/water_south.png"
# define WATER_EAST "assets/usar/water_east.png"
# define WATER_WEST "assets/usar/water_west.png"
# define SAND "assets/usar/sand.png"
# define CHUNK "assets/usar/chunk.png"
# define PLAYER "assets/usar/luffy.png"
# define EXIT "assets/usar/ship.png"

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