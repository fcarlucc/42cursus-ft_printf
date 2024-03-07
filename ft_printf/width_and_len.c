/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_and_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:24:11 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/05/21 18:27:28 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_width(const char *str, t_flag *flag)
{
	int	tmp;

	tmp = 0;
	tmp = flag->index;
	if (str[flag->index + 1] >= '0' && str[flag->index + 1] <= '9')
	{
		flag->width = str[flag->index + 1] - '0';
		flag->index++;
		while (str[flag->index + 1] >= '0' && str[flag->index + 1] <= '9')
		{
			flag->width = flag->width * 10 + (str[flag->index + 1] - '0');
			flag->index++;
		}
	}
	else
		flag->width = 0;
	flag->index = tmp;
}

int	len_width(const char *str, t_flag *flag)
{
	int	len;
	int	tmp;

	len = 0;
	tmp = 0;
	tmp = flag->index;
	if (str[flag->index + 1] >= '0' && str[flag->index + 1] <= '9')
	{
		len = 1;
		while (str[flag->index + 2] >= '0' && str[flag->index + 2] <= '9')
		{
			flag->index++;
			len++;
		}
		flag->index = tmp;
		return (len);
	}
	return (0);
}

int	len_nbr(long long n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count = 1;
	else
	{
		while (n != 0)
		{
			n = n / base;
			count++;
		}
	}
	return (count);
}
