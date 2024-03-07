/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:42:31 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/05/21 20:42:32 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	manage_flag_zero(va_list param, const char *str_format, t_flag *flag)
{
	int	len;

	check_width(str_format, flag);
	flag->tmp = flag->width;
	len = len_width(str_format, flag);
	flag->index += len + 1;
	if (str_format[flag->index] == 'c')
		return (flag_zero_c(va_arg(param, int), flag));
	else if (str_format[flag->index] == 's')
		return (flag_zero_s(va_arg(param, char *), flag));
	else if (str_format[flag->index] == 'd' || str_format[flag->index] == 'i')
		return (flag_zero_d(va_arg(param, int), flag));
	else if (str_format[flag->index] == 'u')
		return (flag_zero_u(va_arg(param, unsigned int), flag));
	else if (str_format[flag->index] == 'p')
		return (flag_zero_p(va_arg(param, unsigned long), flag));
	else if (str_format[flag->index] == 'x')
		return (flag_zero_x(va_arg(param, unsigned int), flag));
	else if (str_format[flag->index] == 'X')
		return (flag_zero_xx(va_arg(param, unsigned int), flag));
	else if (str_format[flag->index] == '.')
		return (select_dot_type_z(param, str_format, flag));
	else
		return (ft_check(param, str_format[flag->index]));
	return (1);
}

int	flag_zero_c(char c, t_flag *flag)
{
	int	i;

	i = 0;
	if (flag->width > 0)
	{
		while (i < flag->width)
			i += ft_putchar(' ');
	}
	i += ft_putchar(c);
	return (i);
}

int	flag_zero_s(char *str, t_flag *flag)
{
	int	i;

	i = 0;
	if (flag->width > ft_strlen(str))
	{
		while (i < ft_strlen(str))
			i += ft_putchar(' ');
	}
	while (str[i])
		i += ft_putchar(str[i]);
	return (i);
}

int	flag_zero_d(int n, t_flag *flag)
{
	int	i;

	i = 0;
	if (n == 0 && flag->width == 0)
		return (0);
	if (n == -2147483648)
	{
		i = 10;
		i += ft_putchar('-');
		while (i < flag->width)
			i += ft_putchar('0');
		ft_putstring("2147483648");
		return (i);
	}
	if (n < 0)
	{
		i += ft_putchar('-');
		n *= -1;
		while (i < flag->width - len_nbr(n, 10))
			i += ft_putchar('0');
	}
	while (i < flag->width - len_nbr(n, 10))
		i += ft_putchar('0');
	i += ft_putnbr(n);
	return (i);
}

int	flag_zero_u(unsigned int n, t_flag *flag)
{
	int	i;

	i = 0;
	if (n == 0 && flag->width == 0)
		return (0);
	while (i < flag->width - len_nbr(n, 10))
		i += ft_putchar('0');
	i += ft_putunsbase(n, "0123456789", 10);
	return (i);
}
