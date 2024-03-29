/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:50:02 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/10 17:09:52 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	check_type_p(t_struct *l, unsigned long int n, char type)
{
	if (type == 'p')
	{
		write(1, "0x", 2);
		l->len += 2;
	}
	ft_puthex_len(n, l, type);
}

void	if_width(unsigned long int n, t_struct *l, char type)
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
	while (l->preclen-- > 0)
		ft_putchar_len('0', l);
	l->precision == 0 && n == 0 && type != 'p' ? NULL :
		check_type_p(l, n, type);
	if ((l->minus && l->zero) || (l->minus && !l->zero))
		while (l->widlen-- > 0)
			ft_putchar_len(' ', l);
}

void	if_nowidth(unsigned long int n, t_struct *l, char type)
{
	while (l->preclen-- > 0)
		ft_putchar_len('0', l);
	l->precision == 0 && n == 0 && type != 'p' ? NULL :
		check_type_p(l, n, type);
}

void	type_x_p(va_list arg, t_struct *l, char type)
{
	unsigned long int	n;
	int					hlen;

	type == 'p' ? (n = va_arg(arg, unsigned long int)) :
		(n = va_arg(arg, unsigned int));
	hlen = nbrlen(n, l, type);
	l->widlen = l->width - hlen;
	if (l->precision > hlen)
	{
		l->preclen = l->precision - hlen;
		l->widlen -= l->preclen;
	}
	if (l->precision >= 0)
		l->zero = 0;
	if (l->width)
		if_width(n, l, type);
	else
		if_nowidth(n, l, type);
}
