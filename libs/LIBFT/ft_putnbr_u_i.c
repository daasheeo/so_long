/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:41:30 by jesmunoz          #+#    #+#             */
/*   Updated: 2023/09/25 10:13:34 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u_i(unsigned int n, size_t *i)
{
	if (n >= 10)
	{
		ft_putnbr_u_i(n / 10, i);
	}
	ft_putchar_i((n % 10) + '0', i);
}
