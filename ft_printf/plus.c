/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:34:19 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/05/21 19:34:20 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	manage_flag_plus(va_list param, const char *str_format, t_flag *flag)
{
	int	len;

	check_width(str_format, flag);
	len = len_width(str_format, flag);
	flag->index += len + 1;
	if (str_format[flag->index] == 'c')
		return (flag_plus_c(va_arg(param, int), flag));
	else if (str_format[flag->index] == 's')
		return (flag_plus_s(va_arg(param, char *), flag));
	else if (str_format[flag->index] == 'd' || str_format[flag->index] == 'i')
		return (flag_plus_d(va_arg(param, int), flag));
	else if (str_format[flag->index] == 'u')
		return (flag_plus_u(va_arg(param, unsigned int), flag));
	else if (str_format[flag->index] == 'p')
		return (flag_plus_p(va_arg(param, unsigned long), flag));
	else if (str_format[flag->index] == 'x')
		return (flag_plus_x(va_arg(param, unsigned int), flag));
	else if (str_format[flag->index] == 'X')
		return (flag_plus_xx(va_arg(param, unsigned int), flag));
	return (1);
}

int	flag_plus_c(char c, t_flag *flag)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	if (flag->width > 0)
	{
		printf("enr\n");
		while (count < flag->width)
		{
			i += ft_putchar(' ');
			count++;
		}
	}
	i += ft_putchar(c);
	return (i);
}

int	flag_plus_s(char *str, t_flag *flag)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	len = ft_strlen(str);
	if (flag->width > len)
	{
		while (i < (flag->width - len))
			i += ft_putchar(' ');
	}
	len = i;
	i = 0;
	while (str[i])
	{
		len += ft_putchar(str[i]);
		i++;
	}
	return (len);
}

int	flag_plus_d(int n, t_flag *flag)
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
		i += ft_putchar('+');
		i += ft_putnbr(n);
	}
	else
		i += ft_putnbr(n);
	return (i);
}

int	flag_plus_u(unsigned int n, t_flag *flag)
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
