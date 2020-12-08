/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:19:48 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/08 16:20:08 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_len(long nb, t_list *list)
{
	char x;

	if (nb == 0 && list->precision != 0)
		ft_putchar_len('0', list);	
	if (nb > 0)
	{
		if (nb > 9)
		{
			ft_putnbr_len(nb / 10, list);
			x = nb % 10 + '0';
			ft_putchar_len(x, list);
		}
		else
		{
			x = nb % 10 + '0';
			ft_putchar_len(x, list);
		}
	}
}
