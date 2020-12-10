/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:48:18 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/10 16:01:49 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	parse_width(const char *format, t_struct *l, va_list arg)
{
	if (format[l->i] == '*')
	{
		l->width = va_arg(arg, int);
		l->i++;
		if (l->width < 0)
		{
			l->width *= -1;
			l->minus = 1;
		}
	}
	else if (format[l->i] >= '0' && format[l->i] <= '9')
	{
		l->width = ft_atoi(format + l->i);
		while (format[l->i] >= '0' && format[l->i] <= '9')
			l->i++;
	}
}

void	parse_precision(const char *format, t_struct *l, va_list arg)
{
	if (format[l->i] == '.')
	{
		l->i++;
		if (format[l->i] == '*')
		{
			l->precision = va_arg(arg, int);
			l->i++;
		}
		else if (format[l->i] >= '0' && format[l->i] <= '9')
		{
			l->precision = ft_atoi(format + l->i);
			while (format[l->i] >= '0' && format[l->i] <= '9')
				l->i++;
		}
		else
			l->precision = 0;
	}
}

void	parse_type(const char format, t_struct *l, va_list arg)
{
	if (format == 'c')
		type_c(arg, l);
	if (format == 's')
		type_s(arg, l);
	if (format == 'd' || format == 'i' || format == 'u')
		type_d_i_u(arg, l, format);
	if (format == 'x' || format == 'X' || format == 'p')
		type_x_p(arg, l, format);
	if (format == '%')
		type_percent(l);
}

void	parser(const char *format, va_list arg, t_struct *l)
{
	while (format[l->i])
	{
		if (format[l->i] != '%')
			ft_putchar_len(format[l->i], l);
		else
		{
			l->i++;
			while (format[l->i] == '-' || format[l->i] == '0')
			{
				(format[l->i] == '-') ? (l->minus = 1) :
					(l->zero = 1);
				l->i++;
			}
			parse_width(format, l, arg);
			parse_precision(format, l, arg);
			parse_type(format[l->i], l, arg);
		}
		if (format[l->i] != '\0')
			l->i++;
		vladimir(l);
	}
}
