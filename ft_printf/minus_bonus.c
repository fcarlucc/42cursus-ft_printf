/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minus_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:24:38 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/05/21 20:24:39 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	select_dot_type_m(va_list param, const char *str_format, t_flag *flag)
{
	int	len;

	check_width(str_format, flag);
	len = len_width(str_format, flag);
	flag->index += len + 1;
	if (str_format[flag->index] == 's')
		return (flag_min_dot_s(va_arg(param, char *), flag));
	else if (str_format[flag->index] == 'd' || str_format[flag->index] == 'i')
		return (flag_min_dot_d(va_arg(param, int), flag));
	else if (str_format[flag->index] == 'u')
		return (flag_min_dot_u(va_arg(param, unsigned int), flag));
	else if (str_format[flag->index] == 'p')
		return (flag_min_dot_p(va_arg(param, unsigned long), flag));
	else if (str_format[flag->index] == 'x')
		return (flag_min_dot_x(va_arg(param, unsigned int), flag));
	else if (str_format[flag->index] == 'X')
		return (flag_min_dot_xx(va_arg(param, unsigned int), flag));
	else
		return (manage_flag_minus(param, str_format, flag));
}

int	flag_min_dot_s(char *str, t_flag *flag)
{
	int	i;

	i = 0;
	i += flag_dot_s(str, flag);
	while (flag->tmp - flag->width > 0 || i < flag->width - ft_strlen(str))
	{
		i += ft_putchar(' ');
		flag->tmp--;
	}
	return (i);
}

int	flag_min_dot_d(int n, t_flag *flag)
{
	int	i;

	i = 0;
	i += flag_dot_d(n, flag);
	if (flag->tmp < flag->width)
		flag->tmp = flag->width;
	while (i < flag->tmp)
		i += ft_putchar(' ');
	return (i);
}

int	flag_min_dot_u(unsigned int n, t_flag *flag)
{
	int	i;

	i = 0;
	i += flag_dot_u(n, flag);
	if (flag->tmp < flag->width)
		flag->tmp = flag->width;
	while (i < flag->tmp)
		i += ft_putchar(' ');
	return (i);
}

int	flag_min_dot_p(unsigned long n, t_flag *flag)
{
	int	i;

	i = 0;
	i += flag_dot_p(n, flag);
	if (flag->tmp < flag->width)
		flag->tmp = flag->width;
	while (i < flag->tmp)
		i += ft_putchar(' ');
	return (i);
}
