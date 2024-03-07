/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:34:06 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/05/21 19:34:09 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_plus_p(unsigned long n, t_flag *flag)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	count = len_nbr(n, 16);
	while (count <= flag->width - 3)
	{
		i += ft_putchar(' ');
		count++;
	}
	i += ft_putstring("+0x");
	i += ft_putunsbase(n, "0123456789abcdef", 16);
	return (i);
}

int	flag_plus_x(unsigned int n, t_flag *flag)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	count = len_nbr(n, 16);
	while (count <= flag->width)
	{
		i += ft_putchar(' ');
		count++;
	}
	i += ft_putunsbase(n, "0123456789abcdef", 16);
	return (i);
}

int	flag_plus_xx(unsigned int n, t_flag *flag)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	count = len_nbr(n, 16);
	while (count <= flag->width)
	{
		i += ft_putchar(' ');
		count++;
	}
	i += ft_putunsbase(n, "0123456789ABCDEF", 16);
	return (i);
}
