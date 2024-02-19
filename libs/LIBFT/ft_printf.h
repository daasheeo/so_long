/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesmunoz <jesmunoz@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:41:13 by jesmunoz          #+#    #+#             */
/*   Updated: 2023/09/26 11:30:30 by jesmunoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# define FD 1
# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

int		ft_printf(char const *str, ...);
void	ft_putchar_i(char c, size_t *i);
void	ft_putstr_i(char *s, size_t *i);
void	ft_putnbr_i(int n, size_t *i);
void	ft_putnbr_u_i(unsigned int n, size_t *i);
size_t	ft_strlen(const char *s);
void	ft_putnbr_base(unsigned long int nbr, char *base, size_t *i);
void	ft_putnbr_p_i(void *ptr, size_t *i);
#endif