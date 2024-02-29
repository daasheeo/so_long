/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:45:06 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/02/28 12:21:26 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIDTH 256
# define HEIGHT 256

# include <MLX42/MLX42.h>
# include <libft.h>
# include <stdio.h>
# include <fcntl.h>

// Structure for the game

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
	int					collectibles_total;
	int					collectibles_collected;
	int					exits;
}						t_map;

// Core functions

void					parse_map(char *map_name);
int						is_valid_map_extension(char *map_name);
int						open_map(char *map_file);
int						is_map_rectangular(char **map);
int						is_map_closed(char **map);
int						get_array_map_size(int fd);
char					**get_map(char *map_file);

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