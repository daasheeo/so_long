/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:53:48 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/20 17:01:37 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <so_long.h>

void	error_handler(char *msg)
{
	ft_putendl_fd("Error", STDOUT_FILENO);
	ft_putendl_fd(msg, STDOUT_FILENO);
	exit (1);
}