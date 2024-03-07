/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:53:39 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/05/21 18:25:07 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstring(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		return (ft_putstring("-2147483648"));
	}
	if (n < 0)
	{
		i += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		i += ft_putnbr(n / 10);
	i += ft_putchar(48 + (n % 10));
	return (i);
}

int	ft_putunsbase(unsigned long n, char *format, unsigned long base)
{
	int	i;

	i = 0;
	if (n >= base)
		i += ft_putunsbase(n / base, format, base);
	i += ft_putchar(format[(n % base)]);
	return (i);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// void	check_width(const char *str, t_flag *flag)
// {
// 	int	tmp;

// 	tmp = 0;
// 	tmp = flag->index;
// 	if (str[flag->index + 1] >= '0' && str[flag->index + 1] <= '9')
// 	{
// 		flag->width = str[flag->index + 1] - '0';
// 		flag->index++;
// 		while (str[flag->index + 1] >= '0' && str[flag->index + 1] <= '9')
// 		{
// 			flag->width = flag->width * 10 + (str[flag->index + 1] - '0');
// 			flag->index++;
// 		}
// 	}
// 	else
// 		flag->width = 0;
// 	flag->index = tmp;
// }

// int	len_width(const char *str, t_flag *flag)
// {
// 	int	len;
// 	int	tmp;

// 	len = 0;
// 	tmp = 0;
// 	tmp = flag->index;
// 	if (str[flag->index + 1] >= '0' && str[flag->index + 1] <= '9')
// 	{
// 		len = 1;
// 		while (str[flag->index + 2] >= '0' && str[flag->index + 2] <= '9')
// 		{
// 			flag->index++;
// 			len++;
// 		}
// 		flag->index = tmp;
// 		return (len);
// 	}
// 	return (0);
// }

// int	len_nbr(long long n, int base)
// {
// 	int	count;

// 	count = 0;
//     if	(n == 0)
// 		return (1);
// 	if	(n < 0)
// 		count = 1;
//     else
//     {
//         while (n != 0)
//         {
//             n = n / base;
//             count++;
//         }
//     }
//     return (count);
// }
