/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:21:50 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/05/21 20:21:51 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	manage_flag_minus(va_list param, const char *str_format, t_flag *flag)
{
	int	len;

	check_width(str_format, flag);
	flag->tmp = flag->width;
	len = len_width(str_format, flag);
	flag->index += len + 1;
	if (str_format[flag->index] == 'c')
		return (flag_minus_c(va_arg(param, int), flag));
	else if (str_format[flag->index] == 's')
		return (flag_minus_s(va_arg(param, char *), flag));
	else if (str_format[flag->index] == 'd' || str_format[flag->index] == 'i')
		return (flag_minus_d(va_arg(param, int), flag));
	else if (str_format[flag->index] == 'u')
		return (flag_minus_u(va_arg(param, unsigned int), flag));
	else if (str_format[flag->index] == 'p')
		return (flag_minus_p(va_arg(param, unsigned long), flag));
	else if (str_format[flag->index] == 'x')
		return (flag_minus_x(va_arg(param, unsigned int), flag));
	else if (str_format[flag->index] == 'X')
		return (flag_minus_xx(va_arg(param, unsigned int), flag));
	else if (str_format[flag->index] == '.')
		return (select_dot_type_m(param, str_format, flag));
	else
		return (ft_check(param, str_format[flag->index]));
}

int	flag_minus_c(char c, t_flag *flag)
{
	int	i;

	i = 0;
	i += ft_putchar(c);
	if (flag->width > 1)
	{
		while (i < flag->width)
			i += ft_putchar(' ');
	}
	return (i);
}

int	flag_minus_s(char *str, t_flag *flag)
{
	int	i;

	i = 0;
	while (str[i])
		i += ft_putchar(str[i]);
	if (flag->width > i)
	{
		while (i < flag->width)
			i += ft_putchar(' ');
	}
	return (i);
}

int	flag_min_dot_x(unsigned int n, t_flag *flag)
{
	int	i;

	i = 0;
	i += flag_dot_x(n, flag);
	if (flag->tmp < flag->width)
		flag->tmp = flag->width;
	while (i < flag->tmp)
		i += ft_putchar(' ');
	return (i);
}

int	flag_min_dot_xx(unsigned int n, t_flag *flag)
{
	int	i;

	i = 0;
	i += flag_dot_xx(n, flag);
	if (flag->tmp < flag->width)
		flag->tmp = flag->width;
	while (i < flag->tmp)
		i += ft_putchar(' ');
	return (i);
}
