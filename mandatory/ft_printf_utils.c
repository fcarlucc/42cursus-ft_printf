/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:53:39 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/02/16 18:49:25 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstring(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		return (ft_putstring("-2147483648"));
	}
	if (n < 0)
	{
		i += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		i += ft_putnbr(n / 10);
	i += ft_putchar(48 + (n % 10));
	return (i);
}

int	ft_putunsbase(unsigned long n, char *format, unsigned long base)
{
	int	i;

	i = 0;
	if (n >= base)
		i += ft_putunsbase(n / base, format, base);
	i += ft_putchar(format[(n % base)]);
	return (i);
}
