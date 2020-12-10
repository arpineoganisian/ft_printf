/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:10:29 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/10 13:56:43 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	nbrlen(unsigned long n, t_struct *l, char type)
{
	int len;
	int	t;

	len = 0;
	type == 'x' || type == 'X' || type == 'p'? t = 16 :
		(t = 10);
	if (n == 0 && l->precision != 0)
		len = 1;
	while (n > 0)
	{
		n /= t;
		len++;
	}
	return (type == 'p' ? len + 2 : len);
}
