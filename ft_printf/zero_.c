/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:43:21 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/05/21 20:43:22 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_zero_p(unsigned long n, t_flag *flag)
{
	int	i;

	i = 0;
	if (n == 0 && flag->width == 0)
		return (0);
	i += ft_putstring("0x");
	while (i < flag->width - len_nbr(n, 16))
		i += ft_putchar('0');
	i += ft_putunsbase(n, "0123456789abcdef", 16);
	return (i);
}

int	flag_zero_x(unsigned int n, t_flag *flag)
{
	int	i;

	i = 0;
	if (n == 0 && flag->width == 0)
		return (0);
	while (i < flag->width - len_nbr(n, 16))
		i += ft_putchar('0');
	i += ft_putunsbase(n, "0123456789abcdef", 16);
	return (i);
}

int	flag_zero_xx(unsigned int n, t_flag *flag)
{
	int	i;

	i = 0;
	if (n == 0 && flag->width == 0)
		return (0);
	while (i < flag->width - len_nbr(n, 16))
		i += ft_putchar('0');
	i += ft_putunsbase(n, "0123456789ABCDEF", 16);
	return (i);
}
