/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 20:04:09 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/09 19:42:32 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_puthex_len(unsigned long nb, t_struct *l, char type)
{
	char c;
	int t;

	type == 'x' ? t = 87 :
		(t = 55);
	if (nb == 0 && l->precision != 0)
		ft_putchar_len('0', l);
	if (nb > 0)
	{
		if (nb > 16)
			ft_puthex_len(nb / 16, l, type);
		nb %= 16;
		if (nb < 10)
		{
			c = nb + '0';
			ft_putchar_len(c, l);
		}
		else if (nb > 9 && nb < 16)
		{	
			c = nb + t;
			ft_putchar_len(c, l);
		}
	}
}
