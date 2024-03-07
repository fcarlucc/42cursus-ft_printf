/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:46:59 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/05/21 23:37:33 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	help_printf(va_list param, const char *str_format, t_flag *flag)
{
	while (str_format[flag->index])
	{
		if (str_format[flag->index] == '%')
		{
			init_flag(flag);
			if (check_flags(str_format[flag->index + 1], flag) == 1)
			{
				flag->index++;
				while (str_format[flag->index + 1] == str_format[flag->index] \
				&& flag->n != 1)
					flag->index++;
				if (flag->n == 1)
					flag->index--;
				flag->printed += check_type_flag(param, str_format, flag);
			}
			else
			{
				flag->index++;
				flag->printed += ft_check(param, str_format[flag->index]);
			}
		}
		else
			flag->printed += ft_putchar(str_format[flag->index]);
		flag->index++;
	}
}

int	help_int(int n, t_flag *flag)
{
	int	i;

	i = 0;
	if (flag->width < len_nbr(n, 10))
	{
		while (i < flag->tmp - len_nbr(n, 10))
			i += ft_putchar(' ');
	}
	else
	{
		if (flag->zero == 1)
		{
			if (n < 0)
				flag->tmp--;
		}
		while (i < flag->tmp - flag->width)
			i += ft_putchar(' ');
	}
	return (i);
}

int	help_uint(unsigned int n, t_flag *flag)
{
	int	i;

	i = 0;
	if (flag->width < len_nbr(n, 10))
	{
		while (i < flag->tmp - len_nbr(n, 10))
			i += ft_putchar(' ');
	}
	else
	{
		while (i < flag->tmp - flag->width)
			i += ft_putchar(' ');
	}
	return (i);
}

int	help_hex(unsigned int n, t_flag *flag)
{
	int	i;

	i = 0;
	if (flag->width < len_nbr(n, 16))
	{
		while (i < flag->tmp - len_nbr(n, 16))
			i += ft_putchar(' ');
	}
	else
	{
		while (i < flag->tmp - flag->width)
			i += ft_putchar(' ');
	}
	return (i);
}

int	help_ulong(unsigned long n, t_flag *flag)
{
	int	i;

	i = 0;
	if (flag->width < len_nbr(n, 16))
	{
		while (i < flag->tmp - len_nbr(n, 16))
			i += ft_putchar(' ');
	}
	else
	{
		while (i < flag->tmp - flag->width)
			i += ft_putchar(' ');
	}
	return (i);
}
