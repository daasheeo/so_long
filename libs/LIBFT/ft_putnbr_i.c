/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:41:22 by jesmunoz          #+#    #+#             */
/*   Updated: 2023/09/25 10:13:03 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_i(int n, size_t *i)
{
	long int	nbr;

	nbr = n;
	if (n < 0)
	{
		nbr *= -1;
		ft_putchar_i('-', i);
	}
	if (nbr >= 10)
	{
		ft_putnbr_i(nbr / 10, i);
	}
	ft_putchar_i((nbr % 10) + '0', i);
}
