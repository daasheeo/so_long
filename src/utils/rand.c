/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rand.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:50:03 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/02/27 13:42:59 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <so_long.h>

void 	rand_seed(t_rand *generator, unsigned int seed)
{
	generator->seed = seed;
}
int 	rand_number(t_rand *generator)
{
	generator->seed = generator->seed * 1103515245 + 12345;
	return ((unsigned int)(generator->seed / 65536) % 10);
}