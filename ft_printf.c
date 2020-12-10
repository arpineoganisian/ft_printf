/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:34:47 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/10 13:51:31 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    structure(t_struct *l)
{
    l->i = 0;
    l->minus = 0;
    l->zero = 0;
    l->width = 0;
    l->precision = -1;
    l->len = 0;
    l->mns = 0;
    l->widlen = 0;
    l->preclen = 0;
}

int	ft_printf(const char *format, ...)
{
	t_struct    l;
	va_list     arg;

	va_start(arg, format);
	structure(&l);
	if (!format)
		return (-1);
	parser(format, arg, &l);
	va_end(arg);
	return (l.len);
}
