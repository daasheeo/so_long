/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_x_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:41:35 by jesmunoz          #+#    #+#             */
/*   Updated: 2023/09/25 10:13:48 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_nbr(unsigned long int n, unsigned int base_value,
		char *symbols, size_t *i)
{
	if (n >= base_value)
		ft_print_nbr(n / base_value, base_value, symbols, i);
	ft_putchar_i(symbols[n % base_value], i);
}

int	double_char(char *symbols)
{
	int	i;
	int	j;

	i = 0;
	while (*(symbols + i))
	{
		j = i + 1;
		while (*(symbols + j))
		{
			if (*(symbols + i) == *(symbols + j))
				return (1);
			++j;
		}
		++i;
	}
	return (0);
}

void	ft_putnbr_base(unsigned long int nbr, char *base, size_t *i)
{
	int	base_value;

	base_value = 0;
	while (base[base_value])
	{
		if (base[base_value] == '+' || base[base_value] == '-')
			return ;
		++base_value;
	}
	if (base_value < 2)
		return ;
	if (double_char(base))
		return ;
	ft_print_nbr(nbr, base_value, base, i);
}
