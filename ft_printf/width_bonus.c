/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:53:33 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/05/21 21:06:37 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	select_dot_type_n(va_list param, const char *str_format, t_flag *flag)
{
	int	len;

	check_width(str_format, flag);
	len = len_width(str_format, flag);
	flag->index += len + 1;
	if (str_format[flag->index] == 's')
		return (flag_n_dot_s(va_arg(param, char *), flag));
	else if (str_format[flag->index] == 'd' || str_format[flag->index] == 'i')
		return (flag_n_dot_d(va_arg(param, int), flag));
	else if (str_format[flag->index] == 'u')
		return (flag_n_dot_u(va_arg(param, unsigned int), flag));
	else if (str_format[flag->index] == 'p')
		return (flag_n_dot_p(va_arg(param, unsigned long), flag));
	else if (str_format[flag->index] == 'x')
		return (flag_n_dot_x(va_arg(param, unsigned int), flag));
	else if (str_format[flag->index] == 'X')
		return (flag_n_dot_xx(va_arg(param, unsigned int), flag));
	else
		return (manage_flag_n(param, str_format, flag));
}

int	flag_n_dot_s(char *str, t_flag *flag)
{
	int	i;

	i = 0;
	while (flag->tmp > flag->width)
	{
		i += ft_putchar(' ');
		flag->tmp--;
	}
	i += flag_dot_s(str, flag);
	return (i);
}

int	flag_n_dot_d(int n, t_flag *flag)
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
		while (i <= flag->tmp - len_nbr(n, 10))
			i += ft_putchar(' ');
	}
	else if (flag->tmp > flag->width)
		i += help_int(n, flag);
	i += flag_dot_d(n, flag);
	return (i);
}

int	flag_n_dot_u(unsigned int n, t_flag *flag)
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
		while (i <= flag->tmp - len_nbr(n, 10))
			i += ft_putchar(' ');
	}
	else if (flag->tmp > flag->width)
		i += help_uint(n, flag);
	i += flag_dot_u(n, flag);
	return (i);
}
