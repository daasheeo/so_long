/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:41:39 by jesmunoz          #+#    #+#             */
/*   Updated: 2023/09/25 10:18:34 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_i(char *s, size_t *i)
{
	if (!s)
		s = ("(null)");
	while (*s)
	{
		ft_putchar_i(*s, i);
		s++;
	}
}
