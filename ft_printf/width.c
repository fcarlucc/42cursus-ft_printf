/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:48:53 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/05/21 19:48:54 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	manage_flag_n(va_list param, const char *str_format, t_flag *flag)
{
	int	len;

	check_width(str_format, flag);
	flag->tmp = flag->width;
	len = len_width(str_format, flag);
	flag->index += len + 1;
	if (str_format[flag->index] == 'c')
		return (flag_n_c(va_arg(param, int), flag));
	else if (str_format[flag->index] == 's')
		return (flag_n_s(va_arg(param, char *), flag));
	else if (str_format[flag->index] == 'd' || str_format[flag->index] == 'i')
		return (flag_n_d(va_arg(param, int), flag));
	else if (str_format[flag->index] == 'u')
		return (flag_n_u(va_arg(param, unsigned int), flag));
	else if (str_format[flag->index] == 'p')
		return (flag_n_p(va_arg(param, unsigned long), flag));
	else if (str_format[flag->index] == 'x')
		return (flag_n_x(va_arg(param, unsigned int), flag));
	else if (str_format[flag->index] == 'X')
		return (flag_n_xx(va_arg(param, unsigned int), flag));
	else if (str_format[flag->index] == '.')
		return (select_dot_type_n(param, str_format, flag));
	else
		return (ft_check(param, str_format[flag->index]));
	return (1);
}

int	flag_n_c(char c, t_flag *flag)
{
	int	i;

	i = 0;
	while (i < flag->width - 1)
		i += ft_putchar(' ');
	i += ft_putchar(c);
	return (i);
}

int	flag_n_s(char *str, t_flag *flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
	{
		while (i < flag->width - 6)
			i += ft_putchar(' ');
		i += ft_putstring(str);
	}
	else if (ft_strlen(str) == 1)
	{
		while (i < flag->width - 1)
			i += ft_putchar(' ');
		i += ft_putchar(str[0]);
	}
	else
	{
		while (i < flag->width - ft_strlen(str))
			i += ft_putchar(' ');
		while (str[j])
			i += ft_putchar(str[j++]);
	}
	return (i);
}

int	flag_n_d(int n, t_flag *flag)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i = 11;
		while (i < flag->width)
			i += ft_putchar(' ');
		ft_putstring("-2147483648");
		return (i);
	}
	if (n < 0)
	{
		n *= -1;
		while (i < flag->width - len_nbr(n, 10) - 1)
			i += ft_putchar(' ');
		i += ft_putchar('-');
		i += ft_putnbr(n);
		return (i);
	}
	while (i < flag->width - len_nbr(n, 10))
		i += ft_putchar(' ');
	i += ft_putnbr(n);
	return (i);
}

int	flag_n_u(unsigned int n, t_flag *flag)
{
	int	i;

	i = 0;
	while (i < flag->width - len_nbr(n, 10))
		i += ft_putchar(' ');
	i += ft_putunsbase(n, "0123456789", 10);
	return (i);
}
