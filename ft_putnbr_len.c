/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:19:48 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/09 16:52:59 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr_len(long nb, t_struct *l)
{
	char x;

	if (nb == 0 && l->precision != 0)
		ft_putchar_len('0', l);
	if (nb > 0)
	{
		if (nb > 9)
		{
			ft_putnbr_len(nb / 10, l);
			x = nb % 10 + '0';
			ft_putchar_len(x, l);
		}
		else
		{
			x = nb % 10 + '0';
			ft_putchar_len(x, l);
		}
	}
}
