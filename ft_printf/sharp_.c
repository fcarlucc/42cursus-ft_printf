/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sharp_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:34:31 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/05/21 19:34:34 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_sharp_p(unsigned long n, t_flag *flag)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	count = len_nbr(n, 16);
	while (count <= flag->width - 2)
	{
		i += ft_putchar(' ');
		count++;
	}
	i += ft_putstring("0x");
	i += ft_putunsbase(n, "0123456789abcdef", 16);
	return (i);
}

int	flag_sharp_x(unsigned long n, t_flag *flag)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	count = len_nbr(n, 16);
	while (count <= flag->width - 2)
	{
		i += ft_putchar(' ');
		count++;
	}
	if (n > 0)
		i += ft_putstring("0x");
	i += ft_putunsbase(n, "0123456789abcdef", 16);
	return (i);
}

int	flag_sharp_xx(unsigned long n, t_flag *flag)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	count = len_nbr(n, 16);
	while (count <= flag->width - 2)
	{
		i += ft_putchar(' ');
		count++;
	}
	if (n > 0)
		i += ft_putstring("0X");
	i += ft_putunsbase(n, "0123456789ABCDEF", 16);
	return (i);
}
