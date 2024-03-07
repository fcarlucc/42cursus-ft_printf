/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_bonus_.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:53:47 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/05/21 21:05:58 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_n_dot_p(unsigned long n, t_flag *flag)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		while (i < flag->width && flag->width > 0)
			i += ft_putchar('0');
	}
	else if (flag->tmp - flag->width == 1 && flag->width != 0)
		i += ft_putchar(' ');
	else if (n == 0 && flag->tmp > flag->width)
	{
		while (i <= flag->tmp - len_nbr(n, 16))
			i += ft_putchar(' ');
	}
	else if (flag->tmp > flag->width)
		i += help_ulong(n, flag);
	i += flag_dot_p(n, flag);
	return (i);
}

int	flag_n_dot_x(unsigned int n, t_flag *flag)
{
	int	i;

	i = 0;
	if (n == 0 && flag->width > 0)
	{
		while (i < flag->width)
			i += ft_putchar('0');
	}
	else if (flag->tmp - flag->width == 1 && flag->width != 0)
		i += ft_putchar(' ');
	else if (n == 0 && flag->tmp > flag->width)
	{
		while (i <= flag->tmp - len_nbr(n, 16))
			i += ft_putchar(' ');
	}
	else if (flag->tmp > flag->width)
		i += help_hex(n, flag);
	i += flag_dot_x(n, flag);
	return (i);
}

int	flag_n_dot_xx(unsigned int n, t_flag *flag)
{
	int	i;

	i = 0;
	if (n == 0 && flag->width > 0)
	{
		while (i < flag->width)
			i += ft_putchar('0');
	}
	else if (flag->tmp - flag->width == 1 && flag->width != 0)
		i += ft_putchar(' ');
	else if (n == 0 && flag->tmp > flag->width)
	{
		while (i <= flag->tmp - len_nbr(n, 16))
			i += ft_putchar(' ');
	}
	else if (flag->tmp > flag->width)
		i += help_hex(n, flag);
	i += flag_dot_xx(n, flag);
	return (i);
}
