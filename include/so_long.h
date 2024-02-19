

#ifndef SO_LONG_H
# define SO_LONG_H

#define WIDTH 256
#define HEIGHT 256

# include <libft.h>
# include <MLX42/MLX42.h>
# include <stdio.h>


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