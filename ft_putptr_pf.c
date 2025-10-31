/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joateixe <joateixe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:21:50 by joateixe          #+#    #+#             */
/*   Updated: 2025/10/29 09:25:14 by joateixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

size_t	ft_strlen_pf(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc_pf(size_t nitems, size_t size)
{
	size_t			total;
	void			*ptr;
	unsigned char	*p;
	size_t			i;

	if (nitems != 0 && size > (SIZE_MAX / nitems))
		return (NULL);
	total = nitems * size;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	p = (unsigned char *)ptr;
	i = 0;
	while (i < total)
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}

size_t	ft_len_pf(size_t n, char *base)
{
	size_t	len;
	size_t	base_len;

	len = 1;
	base_len = ft_strlen_pf(base);
	while (n >= base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_convbase_pf(size_t n, char *base)
{
	char	*str;
	int		num_len;
	int		base_len;

	num_len = ft_len_pf(n, base);
	base_len = ft_strlen_pf(base);
	str = ft_calloc_pf((num_len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (num_len)
	{
		num_len = num_len - 1;
		str[num_len] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}

void	ft_putptr_pf(void *ptr, int *count)
{
	char	*str;
	size_t	ptr_address;

	if (!ptr)
	{
		ft_putstr_pf("(nil)", count);
		return ;
	}
	ptr_address = (unsigned long)ptr;
	ft_putstr_pf("0x", count);
	str = ft_convbase_pf(ptr_address, HEX_LOW_BASE);
	ft_putstr_pf(str, count);
	free(str);
}
