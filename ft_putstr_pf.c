/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joateixe <joateixe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 20:41:45 by joateixe          #+#    #+#             */
/*   Updated: 2025/10/27 20:42:51 by joateixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_pf(char *s, int *count)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr_pf("(null)", count);
		return ;
	}
	while (s[i] != '\0')
	{
		ft_putchar_pf(s[i], count);
		i++;
	}
}
