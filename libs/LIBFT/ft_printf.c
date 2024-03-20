/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:41:08 by jesmunoz          #+#    #+#             */
/*   Updated: 2024/03/20 16:45:08 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list va, char *str, size_t *i)
{
	if (*str == 'c')
		ft_putchar_i(va_arg(va, int), i);
	else if (*str == 's')
		ft_putstr_i(va_arg(va, char *), i);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr_i(va_arg(va, int), i);
	else if (*str == 'u')
		ft_putnbr_u_i(va_arg(va, unsigned int), i);
	else if (*str == 'x')
		ft_putnbr_base(va_arg(va, unsigned int), HEX_LOW_BASE, i);
	else if (*str == 'X')
		ft_putnbr_base(va_arg(va, unsigned int), HEX_UPP_BASE, i);
	else if (*str == 'p')
		ft_putnbr_p_i(va_arg(va, void *), i);
	else if (*str == '%')
		ft_putchar_i(*str, i);
}

int	ft_printf(char const *str, ...)
{
	va_list	va;
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(va, (char *)str, &i);
		}
		else
			ft_putchar_i(*str, &i);
		str++;
		if (i < 0)
			return (-1);
	}
	va_end(va);
	return (i);
}
