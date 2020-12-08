/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:51:06 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/08 13:19:39 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void type_d_i(va_list arg, t_list *list)
{
	int		nbr;
	int		len;
	int		preclen;
	int		mns;
	long long int n;

	nbr = va_arg(arg, int);
	n = (long long int)nbr;
	mns = 0;
	preclen = 0;
	if (n < 0)
	{
		mns = 1;
		n = -n;
	}
//	str = ft_itoa(n);
	if (list->precision == 0 && n == 0)
		str = "";
	mns ? (len = list->width - (int)ft_strlen(str) - 1) :
		(len = list->width - (int)ft_strlen(str));
	if (list->precision > (int)ft_strlen(str))
	{
		preclen = list->precision - (int)ft_strlen(str);
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
//		while (*str)
//		{
//			ft_putchar_len(*str, list);
//			str++;
//		}
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
//		while (*str)
//		{
//			ft_putchar_len(*str, list);
//			str++;
//		}
	}
	free(str);
}

