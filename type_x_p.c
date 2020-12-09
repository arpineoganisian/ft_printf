/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:50:02 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/09 16:52:55 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	if_width(long n, t_struct *l)
{
	if ((!l->minus && !l->zero) || (!l->minus && l->zero))
	{
   		if (l->zero)
       		while (l->widlen-- > 0)
           		ft_putchar_len('0', l);
   		else
       		while (l->widlen-- > 0)
           		ft_putchar_len(' ', l);
	}	
	while(l->preclen-- > 0)
			ft_putchar_len('0', l);
	l->precision == 0 && n == 0 ? NULL : ft_puthex_len(n, l);
	if ((l->minus && l->zero) || (l->minus && !l->zero))
		while (l->widlen-- > 0)
			ft_putchar_len(' ', l);
}

void	if_nowidth(long n, t_struct *l)
{
	while(l->preclen-- > 0)
		ft_putchar_len('0', l);
	l->precision == 0 && n == 0 ? NULL : ft_puthex_len(n, l);
}

void	type_x_p(va_list arg, t_struct *l, char type)
{
	unsigned long	n;
	int				hlen;

	type == 'x' || type == 'X' ? (n = va_arg(arg, unsigned int)) :
		(n = va_arg(arg, unsigned long));
	hlen = hexlen(n, l);
	l->widlen = l->width - hlen;
	if (l->precision > hexlen(n, l))
	{
		l->preclen = l->precision - hexlen(n, l);
		l->widlen -= l->preclen;
	}
	if (l->precision >= 0)
		l->zero = 0;
//	printf("\nwidth %d", l->width);
//	printf("\npreclen %d", l->preclen);
//	printf("\nwidlen %d", l->widlen);
	if (l->width)
		if_width(n, l);
	else
		if_nowidth(n, l);
}
