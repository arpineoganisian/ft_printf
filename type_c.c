/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:15:58 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/04 22:33:12 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	type_c(va_list arg, t_list *list)
{
	char c;

	c = va_arg(arg, int);
	if (list->width > 1)
	{
		if ((!list->minus && !list->zero) || (!list->minus && list->zero))
		{
			if (list->zero)
				while (list->width-- > 1)
					ft_putchar_len('0', list);
			else
				while (list->width-- > 1)
					ft_putchar_len(' ', list);
		}
		ft_putchar_len(c, list);
		if ((list->minus && list->zero) || (list->minus && !list->zero))
			while (list->width-- > 1)
				ft_putchar_len(' ', list);
	}
	else
		ft_putchar_len(c, list);
}
