/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:49:04 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/02 17:58:50 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void type_percent(t_list *list)
{
    if (list->width > 1)
    {
		if ((!list->minus && !list->zero) || (!list->minus && list->zero))
		{
			if (list->zero)
				while (list->width-- > 1)	
					write (1, "0", 1);
			else
				while (list->width-- > 1)	
					write (1, " ", 1);
		}
		write(1, "%", 1);
		if ((list->minus && list->zero) || (list->minus && !list->zero))
			while (list->width-- > 1)	
				write(1, " ", 1);
	}
    else
        write(1, "%", 1);
}
