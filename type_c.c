/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:15:58 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/02 21:38:00 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void type_c(va_list arg, t_list *list)
{
	char c;
	
	c = va_arg(arg, int);
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
        write(1, &c, 1);
        if ((list->minus && list->zero) || (list->minus && !list->zero))
            while (list->width-- > 1)
                write(1, " ", 1);
    }
    else
        write(1, &c, 1);
}
