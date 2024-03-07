/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:23:32 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/05/21 20:23:33 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_minus_d(int n, t_flag *flag)
{
	int	i;

	i = 0;
	if (n == 0 && flag->width == 0)
		return (ft_putchar('0'));
	i += ft_putnbr(n);
	if (flag->width > i)
	{
		while (i < flag->width)
			i += ft_putchar(' ');
	}
	return (i);
}

int	flag_minus_u(unsigned int n, t_flag *flag)
{
	int	i;

	i = 0;
	if (n == 0 && flag->width == 0)
		return (ft_putchar('0'));
	i += ft_putunsbase(n, "0123456789", 10);
	if (flag->width > i)
	{
		while (i < flag->width)
			i += ft_putchar(' ');
	}
	return (i);
}

int	flag_minus_p(unsigned long n, t_flag *flag)
{
	int	i;

	i = 0;
	if (n == 0 && flag->width == 0)
		return (ft_putchar('0'));
	i += ft_putstring("0x");
	i += ft_putunsbase(n, "0123456789abcdef", 16);
	while (i < flag->width)
		i += ft_putchar(' ');
	return (i);
}

int	flag_minus_x(unsigned int n, t_flag *flag)
{
	int	i;

	i = 0;
	if (n == 0 && flag->width == 0)
		return (ft_putchar('0'));
	i += ft_putunsbase(n, "0123456789abcdef", 16);
	while (i < flag->width)
		i += ft_putchar(' ');
	return (i);
}

int	flag_minus_xx(unsigned int n, t_flag *flag)
{
	int	i;

	i = 0;
	if (n == 0 && flag->width == 0)
		return (ft_putchar('0'));
	i += ft_putunsbase(n, "0123456789ABCDEF", 16);
	while (i < flag->width)
		i += ft_putchar(' ');
	return (i);
}
