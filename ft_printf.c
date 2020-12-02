/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 18:34:47 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/01 19:35:37 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *format, ...)
{
	t_list list;
	va_list arg;

	va_start(arg, format);
	structure(&list);
	if (!format)
		return (-1);
	
	parser(format, arg, &list);
	va_end(arg);
	return(0);
}
