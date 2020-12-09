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

void	type_c(va_list arg, t_struct *l)
{
	char c;

	c = va_arg(arg, int);
	if (l->width > 1)
	{
		if ((!l->minus && !l->zero) || (!l->minus && l->zero))
		{
			if (l->zero)
				while (l->width-- > 1)
					ft_putchar_len('0', l);
			else
				while (l->width-- > 1)
					ft_putchar_len(' ', l);
		}
		ft_putchar_len(c, l);
		if ((l->minus && l->zero) || (l->minus && !l->zero))
			while (l->width-- > 1)
				ft_putchar_len(' ', l);
	}
	else
		ft_putchar_len(c, l);
}
