/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:41:26 by jesmunoz          #+#    #+#             */
/*   Updated: 2023/09/25 10:20:22 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_p_i(void *ptr, size_t *i)
{
	unsigned long	ptr_addr;

	ptr_addr = (unsigned long)ptr;
	ft_putstr_i("0x", i);
	ft_putnbr_base(ptr_addr, HEX_LOW_BASE, i);
}
