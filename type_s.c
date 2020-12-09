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

void	print_before(t_struct *l, int len)
{
	if (l->zero)
		while (len-- > 0)
			ft_putchar_len('0', l);
	else
		while (len-- > 0)
			ft_putchar_len(' ', l);
}

void	if_precision(char *str, t_struct *l)
{
	int len;

	len = l->width - l->precision;
	if (l->width >= l->precision)
	{
		if ((!l->minus && !l->zero) || (!l->minus && l->zero))
			print_before(l, len);
		while (l->precision-- > 0)
		{
			ft_putchar_len(*str, l);
			str++;
		}
		if ((l->minus && l->zero) || (l->minus && !l->zero))
			while (len-- > 0)
				ft_putchar_len(' ', l);
	}
	else
	{
		while (l->precision-- > 0)
		{
			ft_putchar_len(*str, l);
			str++;
		}
	}
}

void	no_precision(char *str, t_struct *l)
{
	int len;

	len = l->width - (int)ft_strlen(str);
	if (l->width)
	{
		if ((!l->minus && !l->zero) || (!l->minus && l->zero))
			print_before(l, len);
		while (*str)
		{
			ft_putchar_len(*str, l);
			str++;
		}
		if ((l->minus && l->zero) || (l->minus && !l->zero))
			while (len-- > 0)
				ft_putchar_len(' ', l);
	}
	else
	{
		while (*str)
		{
			ft_putchar_len(*str, l);
			str++;
		}
	}
}

void	type_s(va_list arg, t_struct *l)
{
	char *str;

	str = va_arg(arg, char*);
	if (str == NULL)
		str = "(null)";
	if (l->precision >= 0 && (l->precision < (int)ft_strlen(str)))
		if_precision(str, l);
	else
		no_precision(str, l);
}
