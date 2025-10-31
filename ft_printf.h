/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joateixe <joateixe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:21:01 by joateixe          #+#    #+#             */
/*   Updated: 2025/10/27 20:27:13 by joateixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

# define DEX_10_BASE "0123456789"
# define HEX_UP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

int		ft_printf(char const *format, ...);
void	ft_putchar_pf(char c, int *count);
void	ft_putstr_pf(char *s, int *count);
void	ft_putnbr_pf(int n, int *count);
void	ft_putnbr_base_pf(unsigned int n, char *base, int *count);
void	ft_putptr_pf(void *ptr, int *count);
size_t	ft_strlen_pf(char *str);
char	*ft_convbase_pf(size_t n, char *base);
size_t	ft_len_pf(size_t n, char *base);

#endif
