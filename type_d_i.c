/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:51:06 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/05 16:41:28 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    print(t_list *list, int len)
{
    if (list->zero)
        while (len-- > 0)
            ft_putchar_len('0', list);
    else
        while (len-- > 0)
            ft_putchar_len(' ', list);
}


void type_d_i(va_list arg, t_list *list)
{
	int		n;
	char	*str;
	int		len;
	int		preclen;

	n = va_arg(arg, int);
	str = ft_itoa(n);
	if (list->precision >= 0 && (list->precision < (int)ft_strlen(str)))
	{
    	len = list->width - list->precision;
		if (list->width >= list->precision)
		{
			if ((!list->minus && !list->zero) || (!list->minus && list->zero))
				print(list, len);
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
	else
	{
		len = list->width - (int)ft_strlen(str);
		if (list->precision > (int)ft_strlen(str))
		{
			preclen = list->precision - (int)ft_strlen(str);
			len = len - preclen;
		}
		if (list->width)
		{
			if ((!list->minus && !list->zero) || (!list->minus && list->zero))
				print(list, len);
			if (preclen > 0)
				while(preclen--)
					ft_putchar_len('0', list);
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
}
