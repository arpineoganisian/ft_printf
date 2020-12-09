/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwoodwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 15:20:06 by hwoodwri          #+#    #+#             */
/*   Updated: 2020/12/09 16:52:57 by hwoodwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int hexlen(unsigned long n, t_struct *l)
{
	int len; 

	len = 0;
	if (n == 0 && l->precision != 0)
		len = 1;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}
