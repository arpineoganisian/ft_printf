/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:49:04 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/04 22:35:21 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	type_percent(t_struct *l)
{
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
		ft_putchar_len('%', l);
		if ((l->minus && l->zero) || (l->minus && !l->zero))
			while (l->width-- > 1)
				ft_putchar_len(' ', l);
	}
	else
		ft_putchar_len('%', l);
}
