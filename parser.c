/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:48:18 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/05 16:41:29 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	parse_width(const char *format, t_list *list, va_list arg)
{
	if (format[list->i] == '*')
	{
		list->width = va_arg(arg, int);
		list->i++;
		if (list->width < 0)
		{
			list->width *= -1;
			list->minus = 1;
		}
	}
	else if (format[list->i] >= '0' && format[list->i] <= '9')
	{
		list->width = ft_atoi(format + list->i);
		while (format[list->i] >= '0' && format[list->i] <= '9')
			list->i++;
	}
}

void	parse_precision(const char *format, t_list *list, va_list arg)
{
	if (format[list->i] == '.')
	{
		list->i++;
		if (format[list->i] == '*')
		{
			list->precision = va_arg(arg, int);
			list->i++;
		}
		else if (format[list->i] >= '0' && format[list->i] <= '9')
		{
			list->precision = ft_atoi(format + list->i);
			while (format[list->i] >= '0' && format[list->i] <= '9')
				list->i++;
		}
		else
			list->precision = 0;
	}
}

void	parse_type(const char format, t_list *list, va_list arg)
{
	if (format == 'c')
		type_c(arg, list);
	if (format == 's')
		type_s(arg, list);
/*	if (format == 'p')
*/
	if (format == 'd' || format == 'i')
		type_d_i(arg, list);
/*	if (format == 'u')

	if (format == 'x')

	if (format == 'X')
*/
	if (format == '%')
		type_percent(list);
}

void	parser(const char *format, va_list arg, t_list *list)
{
	while (format[list->i])
	{
		if (format[list->i] != '%')
			ft_putchar_len(format[list->i], list);
		else
		{
			list->i++;
			while (format[list->i] == '-' || format[list->i] == '0')
			{
				(format[list->i] == '-') ? (list->minus = 1) :
					(list->zero = 1);
				list->i++;
			}
			parse_width(format, list, arg);
			parse_precision(format, list, arg);
			parse_type(format[list->i], list, arg);
		}
		if (format[list->i] != '\0')
			list->i++;
	}
}
