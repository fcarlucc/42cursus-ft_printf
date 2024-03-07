/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcarlucc <fcarlucc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:30:25 by fcarlucc          #+#    #+#             */
/*   Updated: 2023/05/21 23:33:42 by fcarlucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

typedef struct s_flag
{
	int	minus;
	int	zero;
	int	dot;
	int	plus;
	int	space;
	int	sharp;
	int	n;
	int	width;
	int	len;
	int	index;
	int	tmp;
	int	printed;
}		t_flag;

int		ft_strlen(char *s);
int		ft_putchar(char c);
int		ft_putstring(char *s);
int		ft_putnbr(int n);
int		ft_putunsbase(unsigned long n, char *format, unsigned long base);
int		ft_printf(const char *str_format, ...);
void	init_flag(t_flag *flag);
int		check_flags(const char str_format, t_flag *flag);
int		check_type_flag(va_list	param, const char *str, t_flag *flag);
int		ft_check(va_list param, const char format);
int		len_width(const char *str_format, t_flag *flag);
void	check_width(const char *str_format, t_flag *flag);
int		len_nbr(long long n, int base);
int		manage_flag_sharp(va_list param, const char *str_format, t_flag *flag);
int		flag_sharp_c(char c, t_flag *flag);
int		flag_sharp_s(char *str, t_flag *flag);
int		flag_sharp_d(int n, t_flag *flag);
int		flag_sharp_u(unsigned int n, t_flag *flag);
int		flag_sharp_p(unsigned long n, t_flag *flag);
int		flag_sharp_x(unsigned long n, t_flag *flag);
int		flag_sharp_xx(unsigned long n, t_flag *flag);
int		manage_flag_plus(va_list param, const char *str_format, t_flag *flag);
int		flag_plus_c(char c, t_flag *flag);
int		flag_plus_s(char *str, t_flag *flag);
int		flag_plus_d(int n, t_flag *flag);
int		flag_plus_u(unsigned int n, t_flag *flag);
int		flag_plus_p(unsigned long n, t_flag *flag);
int		flag_plus_x(unsigned int n, t_flag *flag);
int		flag_plus_xx(unsigned int n, t_flag *flag);
int		manage_flag_space(va_list param, const char *str_format, t_flag *flag);
int		flag_space_c(char c, t_flag *flag);
int		flag_space_s(char *str, t_flag *flag);
int		flag_space_d(int n, t_flag *flag);
int		flag_space_u(unsigned int n, t_flag *flag);
int		flag_space_p(unsigned long n, t_flag *flag);
int		flag_space_x(unsigned int n, t_flag *flag);
int		flag_space_xx(unsigned int n, t_flag *flag);
int		manage_flag_n(va_list param, const char *str_format, t_flag *flag);
int		select_dot_type_n(va_list param, const char *str_format, t_flag *flag);
int		flag_n_dot_s(char *str, t_flag *flag);
int		flag_n_dot_d(int n, t_flag *flag);
int		flag_n_dot_u(unsigned int n, t_flag *flag);
int		flag_n_dot_p(unsigned long n, t_flag *flag);
int		flag_n_dot_x(unsigned int n, t_flag *flag);
int		flag_n_dot_xx(unsigned int n, t_flag *flag);
int		flag_n_c(char c, t_flag *flag);
int		flag_n_s(char *str, t_flag *flag);
int		flag_n_d(int n, t_flag *flag);
int		flag_n_u(unsigned int n, t_flag *flag);
int		flag_n_p(unsigned long n, t_flag *flag);
int		flag_n_x(unsigned int n, t_flag *flag);
int		flag_n_xx(unsigned int n, t_flag *flag);
int		manage_flag_minus(va_list param, const char *str_format, t_flag *flag);
int		select_dot_type_m(va_list param, const char *str_format, t_flag *flag);
int		flag_min_dot_s(char *str, t_flag *flag);
int		flag_min_dot_d(int n, t_flag *flag);
int		flag_min_dot_u(unsigned int n, t_flag *flag);
int		flag_min_dot_p(unsigned long n, t_flag *flag);
int		flag_min_dot_x(unsigned int n, t_flag *flag);
int		flag_min_dot_xx(unsigned int n, t_flag *flag);
int		flag_minus_c(char c, t_flag *flag);
int		flag_minus_s(char *str, t_flag *flag);
int		flag_minus_d(int n, t_flag *flag);
int		flag_minus_u(unsigned int n, t_flag *flag);
int		flag_minus_p(unsigned long n, t_flag *flag);
int		flag_minus_x(unsigned int n, t_flag *flag);
int		flag_minus_xx(unsigned int n, t_flag *flag);
int		manage_flag_dot(va_list param, const char *str_format, t_flag *flag);
int		flag_dot_c(char c, t_flag *flag);
int		flag_dot_s(char *str, t_flag *flag);
int		flag_dot_d(int n, t_flag *flag);
int		flag_dot_u(unsigned int n, t_flag *flag);
int		flag_dot_p(unsigned long n, t_flag *flag);
int		flag_dot_x(unsigned int n, t_flag *flag);
int		flag_dot_xx(unsigned int n, t_flag *flag);
int		manage_flag_zero(va_list param, const char *str_format, t_flag *flag);
int		select_dot_type_z(va_list param, const char *str_format, t_flag *flag);
int		flag_zero_dot_s(char *str, t_flag *flag);
int		flag_zero_dot_d(int n, t_flag *flag);
int		flag_zero_dot_u(unsigned int n, t_flag *flag);
int		flag_zero_dot_p(unsigned long n, t_flag *flag);
int		flag_zero_dot_x(unsigned int n, t_flag *flag);
int		flag_zero_dot_xx(unsigned int n, t_flag *flag);
int		flag_zero_c(char c, t_flag *flag);
int		flag_zero_s(char *str, t_flag *flag);
int		flag_zero_d(int n, t_flag *flag);
int		flag_zero_u(unsigned int n, t_flag *flag);
int		flag_zero_p(unsigned long n, t_flag *flag);
int		flag_zero_x(unsigned int n, t_flag *flag);
int		flag_zero_xx(unsigned int n, t_flag *flag);
int		help_int(int n, t_flag *flag);
int		help_min_int(int n, t_flag *flag);
int		help_uint(unsigned int n, t_flag *flag);
int		help_hex(unsigned int n, t_flag *flag);
int		help_ulong(unsigned long n, t_flag *flag);
void	help_printf(va_list param, const char *str_format, t_flag *flag);

#endif
