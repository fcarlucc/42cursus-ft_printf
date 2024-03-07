/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:30:25 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/02/16 19:43:24 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_putstring(char *s);

int		ft_putnbr(int n);

int		ft_putunsbase(unsigned long n, char *format, unsigned long base);

int		ft_printf(const char *str_format, ...);
#endif
