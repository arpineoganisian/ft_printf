/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:49:04 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/02 21:49:52 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void type_percent(t_list *list)
{
//	list->width > 1 ? (list->len += list->width) : (list->len += 1);
    if (list->width > 1)
    {
		if ((!list->minus && !list->zero) || (!list->minus && list->zero))
		{
			if (list->zero)
				while (list->width-- > 1)	
					ft_putchar_len('0', list);
			else
				while (list->width-- > 1)	
					ft_putchar(' ', list);
		}
		ft_putchar_len('%', list);
		if ((list->minus && list->zero) || (list->minus && !list->zero))
			while (list->width-- > 1)	
				ft_putchar_len(' , list);
	}
    else
        ft_putchar_len('%', list);
}
