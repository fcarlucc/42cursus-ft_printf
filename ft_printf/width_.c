/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:49:21 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/05/21 19:49:22 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flag_n_p(unsigned long n, t_flag *flag)
{
	int	i;

	i = 0;
	while (i < flag->width - len_nbr(n, 16) - 2)
		i += ft_putchar(' ');
	i += ft_putstring("0x");
	i += ft_putunsbase(n, "0123456789abcdef", 16);
	return (i);
}

int	flag_n_x(unsigned int n, t_flag *flag)
{
	int	i;

	i = 0;
	while (i < flag->width - len_nbr(n, 16))
		i += ft_putchar(' ');
	i += ft_putunsbase(n, "0123456789abcdef", 16);
	return (i);
}

int	flag_n_xx(unsigned int n, t_flag *flag)
{
	int	i;

	i = 0;
	while (i < flag->width - len_nbr(n, 16))
		i += ft_putchar(' ');
	i += ft_putunsbase(n, "0123456789ABCDEF", 16);
	return (i);
}
