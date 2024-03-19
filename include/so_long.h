/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:45:06 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/19 12:04:37 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 256
# define HEIGHT 256

# include <MLX42/MLX42.h>
# include <fcntl.h>
# include <libft.h>
# include <stdio.h>

// Structure for the game

typedef enum e_tile
{
	EMPTY = '0',
	WALL = '1',
	PLAYER = 'P',
	EXIT = 'E',
	COLLECTIBLE = 'C'
}						t_tile;

typedef struct s_player
{
	int					x;
	int					y;
	int					moves;
	int					alive;
	// texture

}						t_player;

typedef struct s_map
{
	char				**map;
	int					width;
	int					height;
	t_player			oc_player;
	int					players;
	int					collectibles_total;
	int					collectibles_collected;
	int					exits;
}						t_map;

// Core functions

void					parse_map(char *map_name);
int						is_valid_map_extension(char *map_name);
int						is_map_rectangular(char **map);
int						is_map_closed(t_map *map);
int						get_array_map_size(int fd);
int						*get_map_dimesions(char **map);
char					**get_map(char *map_file);
int						is_map_valid(t_map *map);
int						*get_player_pos(t_map *map);
void					free_array_map(char **map);
void					free_map_struct(t_map *map);
void					flood_fill(t_map *map);
int						can_be_completed(t_map *map);
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