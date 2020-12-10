/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d_i_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:34:59 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/10 17:10:27 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	there_is_width(long n, t_struct *l)
{
	if (l->mns && l->zero)
		ft_putchar_len('-', l);
	if ((!l->minus && !l->zero) || (!l->minus && l->zero))
	{
		if (l->zero)
			while (l->widlen-- > 0)
				ft_putchar_len('0', l);
		else
			while (l->widlen-- > 0)
				ft_putchar_len(' ', l);
	}
	if (l->mns && !l->zero)
		ft_putchar_len('-', l);
	while (l->preclen-- > 0)
		ft_putchar_len('0', l);
	l->precision == 0 && n == 0 ? NULL : ft_putnbr_len(n, l);
	if ((l->minus && l->zero) || (l->minus && !l->zero))
		while (l->widlen-- > 0)
			ft_putchar_len(' ', l);
}

void	there_is_nowidth(long n, t_struct *l)
{
	if (l->mns)
		ft_putchar_len('-', l);
	while (l->preclen-- > 0)
		ft_putchar_len('0', l);
	l->precision == 0 && n == 0 ? NULL : ft_putnbr_len(n, l);
}

void	type_d_i_u(va_list arg, t_struct *l, char type)
{
	long	n;
	int		nlen;

	type == 'u' ? (n = (long)va_arg(arg, unsigned int)) :
		(n = (long)va_arg(arg, int));
	if (n < 0)
	{
		l->mns = 1;
		n = -n;
	}
	nlen = nbrlen(n, l, type);
	l->mns ? (l->widlen = l->width - nlen - 1) :
		(l->widlen = l->width - nlen);
	if (l->precision > nlen)
	{
		l->preclen = l->precision - nlen;
		l->widlen -= l->preclen;
	}
	if (l->precision >= 0)
		l->zero = 0;
	if (l->width)
		there_is_width(n, l);
	else
		there_is_nowidth(n, l);
}
