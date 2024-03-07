 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:26:19 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/03/17 13:52:55 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(va_list param, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(param, int)));
	else if (format == 's')
		return (ft_putstring(va_arg(param, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(param, int)));
	else if (format == 'u')
		return (ft_putunsbase(va_arg(param, unsigned int), "0123456789", 10));
	else if (format == 'p')
		return (ft_putstring("0x") + ft_putunsbase(va_arg(param, unsigned long),
				"0123456789abcdef", 16));
	else if (format == 'x')
		return (ft_putunsbase(va_arg(param, unsigned int), "0123456789abcdef",
				16));
	else if (format == 'X')
		return (ft_putunsbase(va_arg(param, unsigned int), "0123456789ABCDEF",
				16));
	else if (format == '%')
		return (ft_putchar('%'));
	return (1);
}

int	ft_printf(const char *str_format, ...)
{
	va_list	param;
	int		i;
	int		printed;

	i = 0;
	printed = 0;
	va_start(param, str_format);
	while (str_format[i])
	{
		if (str_format[i] == '%')
		{
			printed += (ft_check(param, str_format[i + 1]));
			i++;
		}
		else
			printed += (ft_putchar(str_format[i]));
		i++;
	}
	va_end(param);
	return (printed);
}
