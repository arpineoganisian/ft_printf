/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:51:06 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/08 16:31:48 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void type_d_i(va_list arg, t_list *list, char type)
{
	int		len;
	int		preclen;
	int		mns;
	long	n;

	type == 'u' ? (n = (long)va_arg(arg, unsigned int)) :
		(n = (long)va_arg(arg, int));
	mns = 0;
	preclen = 0;
	if (n < 0)
	{
		mns = 1;
		n = -n;
	}
	mns ? (len = list->width - intlen(n, list) - 1) :
		(len = list->width - intlen(n, list));
	if (list->precision > intlen(n, list))
	{
		preclen = list->precision - intlen(n, list);
		len = len - preclen;
	}
	if (list->precision >= 0)
		list->zero = 0;
	if (list->width)
	{
		if (mns && list->zero)
			ft_putchar_len('-', list);
		if ((!list->minus && !list->zero) || (!list->minus && list->zero))
		{
    		if (list->zero)
        		while (len-- > 0)
            		ft_putchar_len('0', list);
    		else
        		while (len-- > 0)
            		ft_putchar_len(' ', list);
		}	
		if (mns && !list->zero)
			ft_putchar_len('-', list);
		while(preclen-- > 0)
				ft_putchar_len('0', list);
		list->precision == 0 && n == 0 ? NULL : ft_putnbr_len(n, list);
		if ((list->minus && list->zero) || (list->minus && !list->zero))
			while (len-- > 0)
				ft_putchar_len(' ', list);
	}
	else
	{
		if (mns)
			ft_putchar_len('-', list);
		while(preclen--)
			ft_putchar_len('0', list);
		list->precision == 0 && n == 0 ? NULL : ft_putnbr_len(n, list);
	}
}
