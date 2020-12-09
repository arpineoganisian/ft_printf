/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:34:47 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/08 16:32:04 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
