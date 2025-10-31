/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joateixe <joateixe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:43:10 by joateixe          #+#    #+#             */
/*   Updated: 2025/10/27 20:43:41 by joateixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pf(int n, int *count)
{
	char	i;

	i = 0;
	if (n == -2147483648)
	{
		ft_putstr_pf("-2147483648", count);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_pf('-', count);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_pf(n / 10, count);
	i = (n % 10) + '0';
	ft_putstr_pf(&i, count);
}
