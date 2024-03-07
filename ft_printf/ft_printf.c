/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:26:19 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/05/21 23:37:03 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flag(t_flag *flag)
{
	flag->zero = 0;
	flag->minus = 0;
	flag->dot = 0;
	flag->space = 0;
	flag->sharp = 0;
	flag->plus = 0;
	flag->n = 0;
	flag->width = 0;
}

int	check_flags(const char str_format, t_flag *flag)
{
	if (str_format == '-')
		flag->minus = 1;
	if (str_format == '0')
		flag->zero = 1;
	if (str_format == '.')
		flag->dot = 1;
	if (str_format == '+')
		flag->plus = 1;
	if (str_format == ' ')
		flag->space = 1;
	if (str_format == '#')
		flag->sharp = 1;
	if (str_format > '0' && str_format <= '9')
		flag->n = 1;
	if (flag->minus != 1 && flag->zero != 1 && flag->dot != 1 \
	&& flag->plus != 1 && flag->space != 1 && flag->sharp != 1 && flag->n != 1)
		return (0);
	return (1);
}

int	check_type_flag(va_list	param, const char *str, t_flag *flag)
{	
	if (flag->minus == 1)
		return (manage_flag_minus(param, str, flag));
	else if (flag->zero == 1)
		return (manage_flag_zero(param, str, flag));
	else if (flag->dot == 1)
		return (manage_flag_dot(param, str, flag));
	else if (flag->plus == 1)
		return (manage_flag_plus(param, str, flag));
	else if (flag->space == 1)
		return (manage_flag_space(param, str, flag));
	else if (flag->sharp == 1)
		return (manage_flag_sharp(param, str, flag));
	else if (flag->n == 1)
		return (manage_flag_n(param, str, flag));
	return (0);
}

int	ft_check(va_list param, const char format)
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
	t_flag	flag;
	va_list	param;

	flag.printed = 0;
	flag.index = 0;
	va_start(param, str_format);
	help_printf(param, &str_format[flag.index], &flag);
	va_end(param);
	return (flag.printed);
}
