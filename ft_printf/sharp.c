/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sharp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:34:41 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/05/21 19:34:43 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	manage_flag_sharp(va_list param, const char *str_format, t_flag *flag)
{
	int	len;

	check_width(str_format, flag);
	len = len_width(str_format, flag);
	flag->index += len + 1;
	if (str_format[flag->index] == 'c')
		return (flag_sharp_c(va_arg(param, int), flag));
	else if (str_format[flag->index] == 's')
		return (flag_sharp_s(va_arg(param, char *), flag));
	else if (str_format[flag->index] == 'd' || str_format[flag->index] == 'i')
		return (flag_sharp_d(va_arg(param, int), flag));
	else if (str_format[flag->index] == 'u')
		return (flag_sharp_u(va_arg(param, unsigned int), flag));
	else if (str_format[flag->index] == 'p')
		return (flag_sharp_p(va_arg(param, unsigned long), flag));
	else if (str_format[flag->index] == 'x')
		return (flag_sharp_x(va_arg(param, unsigned int), flag));
	else if (str_format[flag->index] == 'X')
		return (flag_sharp_xx(va_arg(param, unsigned int), flag));
	return (1);
}

int	flag_sharp_c(char c, t_flag *flag)
{
	int	i;

	i = 0;
	while (i < flag->width - 1)
		i += ft_putchar(' ');
	i += ft_putchar(c);
	return (i);
}

int	flag_sharp_s(char *str, t_flag *flag)
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

int	flag_sharp_d(int n, t_flag *flag)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	count = len_nbr(n, 10);
	while (count <= flag->width)
	{
		i += ft_putchar(' ');
		count++;
	}
	if (n >= 0)
	{
		i += ft_putnbr(n);
	}
	else
		i += ft_putnbr(n);
	return (i);
}

int	flag_sharp_u(unsigned int n, t_flag *flag)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	count = len_nbr(n, 10);
	while (count <= flag->width)
	{
		i += ft_putchar(' ');
		count++;
	}
	i += ft_putunsbase(n, "0123456789", 10);
	return (i);
}
