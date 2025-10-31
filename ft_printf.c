/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joateixe <joateixe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:09:35 by joateixe          #+#    #+#             */
/*   Updated: 2025/10/27 14:24:24 by joateixe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_format(char specifier, va_list ap, int *count)
{
	if (specifier == 'c')
		ft_putchar_pf(va_arg(ap, int), count);
	else if (specifier == 's')
		ft_putstr_pf(va_arg(ap, char *), count);
	else if (specifier == 'p')
		ft_putptr_pf(va_arg (ap, void *), count);
	else if (specifier == 'd' || specifier == 'i')
		ft_putnbr_pf(va_arg(ap, int), count);
	else if (specifier == 'u')
		ft_putnbr_base_pf(va_arg(ap, unsigned int), DEX_10_BASE, count);
	else if (specifier == 'x')
		ft_putnbr_base_pf(va_arg(ap, unsigned int), HEX_LOW_BASE, count);
	else if (specifier == 'X')
		ft_putnbr_base_pf(va_arg(ap, unsigned int), HEX_UP_BASE, count);
	else if (specifier == '%')
		ft_putchar_pf('%', count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;
	int		count;

	if (!format)
		return (-1);
	count = 0;
	i = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			print_format(format[i + 1], ap, &count);
			i++;
		}
		else
			ft_putchar_pf(format[i], &count);
		i++;
	}
	va_end(ap);
	return (count);
}
//
// int	main(void)
// {
// 	int	ret_ft;
// 	int	ret_std;
//
// 	printf("\n===== ft_printf TESTER =====\n\n");
//
// 	/* ---------- CATEGORY: c ---------- */
// 	printf("--- CATEGORY: c ---\n");
// 	ret_std = printf("STD: Hello %c World!\n", 'A');
// 	ret_ft = ft_printf("FT_: Hello %c World!\n", 'A');
// 	printf("Return: STD=%d | FT_=%d\n\n", ret_std, ret_ft);
//
// 	/* ---------- CATEGORY: s ---------- */
// 	printf("--- CATEGORY: s ---\n");
// 	ret_std = printf("STD: %s %s!\n", "Hello", "World");
// 	ret_ft = ft_printf("FT_: %s %s!\n", "Hello", "World");
// 	printf("Return: STD=%d | FT_=%d\n\n", ret_std, ret_ft);
//
// 	/* ---------- CATEGORY: p ---------- */
// 	printf("--- CATEGORY: p ---\n");
// 	int a = 42;
// 	ret_std = printf("STD: %p %p\n", &a, NULL);
// 	ret_ft = ft_printf("FT_: %p %p\n", &a, NULL);
// 	printf("Return: STD=%d | FT_=%d\n\n", ret_std, ret_ft);
//
// 	/* ---------- CATEGORY: d / i ---------- */
// 	printf("--- CATEGORY: d / i ---\n");
// 	ret_std = printf("STD: %d %i %d %i\n", 0, -42, INT_MAX, INT_MIN);
// 	ret_ft = ft_printf("FT_: %d %i %d %i\n", 0, -42, INT_MAX, INT_MIN);
// 	printf("Return: STD=%d | FT_=%d\n\n", ret_std, ret_ft);
//
// 	/* ---------- CATEGORY: u ---------- */
// 	printf("--- CATEGORY: u ---\n");
// 	ret_std = printf("STD: %u %u\n", 0, 4294967295u);
// 	ret_ft = ft_printf("FT_: %u %u\n", 0, 4294967295u);
// 	printf("Return: STD=%d | FT_=%d\n\n", ret_std, ret_ft);
//
// 	/* ---------- CATEGORY: x ---------- */
// 	printf("--- CATEGORY: x ---\n");
// 	ret_std = printf("STD: %x %x %x\n", 0, 255, 4294967295u);
// 	ret_ft = ft_printf("FT_: %x %x %x\n", 0, 255, 4294967295u);
// 	printf("Return: STD=%d | FT_=%d\n\n", ret_std, ret_ft);
//
// 	/* ---------- CATEGORY: X ---------- */
// 	printf("--- CATEGORY: X ---\n");
// 	ret_std = printf("STD: %X %X %X\n", 0, 255, 4294967295u);
// 	ret_ft = ft_printf("FT_: %X %X %X\n", 0, 255, 4294967295u);
// 	printf("Return: STD=%d | FT_=%d\n\n", ret_std, ret_ft);
//
// 	/* ---------- CATEGORY: %% ---------- */
// 	printf("--- CATEGORY: %% ---\n");
// 	ret_std = printf("STD: 100%% Working!\n");
// 	ret_ft = ft_printf("FT_: 100%% Working!\n");
// 	printf("Return: STD=%d | FT_=%d\n\n", ret_std, ret_ft);
//
// 	/* ---------- CATEGORY: MIX ---------- */
// 	printf("--- CATEGORY: MIX ---\n");
// 	ret_std = printf("STD: %c %s %p %d %i %u %x %X %%\n",
// 					'A', "mix", &a, -42, 42, 42u, 42, 42);
// 	ret_ft = ft_printf("FT_: %c %s %p %d %i %u %x %X %%\n",
// 					'A', "mix", &a, -42, 42, 42u, 42, 42);
// 	printf("Return: STD=%d | FT_=%d\n\n", ret_std, ret_ft);
//
// 	printf("===== END OF TESTS =====\n\n");
// 	return (0);
// }
