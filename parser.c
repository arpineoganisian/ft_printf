/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 14:48:18 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/11/30 21:32:52 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void *parse_type(const char *format, t_list *list)
{
	if (format[list->i] == 'c')
		type_c();
	if (format[list->i] == 's')

	if (format[list->i] == 'p')

	if (format[list->i] == 'd' || format[list->i] == 'i')

	if (format[list->i] == 'u')

	if (format[list->i] == 'x')

	if (format[list->i] == 'X')

	if (format[list->i] == '%')	

}

void *parse_width(const char *format, t_list *list, va_list *arg)
{
	if (format[list->i] == '*')
	{
		list->width = va_arg(arg, int);
		list->i++;
	}
	else
	{
		list->width = ft_atoi(format + list->i);
		while (format[list->i] >= '0' && format[list->i] <= '9')
			list->i++;
	}
}

void *parse_precision(const char *format, t_list *list, va_list *arg)
{
	if (list->i == ".")
	{
		list->i++;
		if (format[list->i] == '*')
		{
			list->precision = va_arg(arg, int);
			list->i++;
		}
		else
		{
			list->precision = ft_atoi(format + list->i);
			while (format[list->i] >= '0' && format[list->i] <= '9')
				list->i++;
		}
	}
}

void *parser(const char *format, va_list *arg)
{
	t_list	list;

	structure(&list);
	while (format[list->i])
	{
		if (format[list->i] != '%')
			write(1, &format[list->i], 1);
		else
		{
			list->i++;
			while(format[list->i] == '-' || format[list->i] == '0')
			{	
				format[list->i] == '-' ? list->minus = 1 : list->zero = 1;
				list->i++;	
			}
			parse_width(format + list->i, &list, arg);
			parse_precision(format + list->i, &list, arg)
			parse_type(format[list->i], &list);
		}
		list->i++;
	}
}
