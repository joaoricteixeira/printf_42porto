/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_pf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joateixe <joateixe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:42:44 by joateixe          #+#    #+#             */
/*   Updated: 2025/10/28 16:20:42 by joateixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_pf(unsigned int n, char *base, int *count)
{
	long	nb;
	int		length;

	length = ft_strlen_pf(base);
	if (length < 2)
		return ;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar_pf('-', count);
	}
	if (nb < length)
		ft_putchar_pf(base[nb], count);
	if (nb >= length)
	{
		ft_putnbr_base_pf(nb / length, base, count);
		ft_putnbr_base_pf(nb % length, base, count);
	}
}
