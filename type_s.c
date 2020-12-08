/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 18:57:17 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/08 16:31:50 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_before(t_list *list, int len)
{
	if (list->zero)
		while (len-- > 0)
			ft_putchar_len('0', list);
	else
		while (len-- > 0)
			ft_putchar_len(' ', list);
}

void	if_precision(char *str, t_list *list)
{
	int len;

	len = list->width - list->precision;
	if (list->width >= list->precision)
	{
		if ((!list->minus && !list->zero) || (!list->minus && list->zero))
			print_before(list, len);
		while (list->precision-- > 0)
		{
			ft_putchar_len(*str, list);
			str++;
		}
		if ((list->minus && list->zero) || (list->minus && !list->zero))
			while (len-- > 0)
				ft_putchar_len(' ', list);
	}
	else
	{
		while (list->precision-- > 0)
		{
			ft_putchar_len(*str, list);
			str++;
		}
	}
}

void	no_precision(char *str, t_list *list)
{
	int len;

	len = list->width - (int)ft_strlen(str);
	if (list->width)
	{
		if ((!list->minus && !list->zero) || (!list->minus && list->zero))
			print_before(list, len);
		while (*str)
		{
			ft_putchar_len(*str, list);
			str++;
		}
		if ((list->minus && list->zero) || (list->minus && !list->zero))
			while (len-- > 0)
				ft_putchar_len(' ', list);
	}
	else
	{
		while (*str)
		{
			ft_putchar_len(*str, list);
			str++;
		}
	}
}

void	type_s(va_list arg, t_list *list)
{
	char *str;

	str = va_arg(arg, char*);
	if (str == NULL)
		str = "(null)";
	if (list->precision >= 0 && (list->precision < (int)ft_strlen(str)))
		if_precision(str, list);
	else
		no_precision(str, list);
}
